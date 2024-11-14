#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "util.h"

const char *read_input(const char *const *argv, char *buffer,
                       size_t buffer_size) {
  int pipes[2];
  if (pipe(pipes) == -1) {
    g_error("failed to create pipes\n");
  }
  int pipe_read = pipes[0];
  int pipe_write = pipes[1];

  int child_pid = fork();
  if (child_pid == -1) {
    g_error("failed to fork\n");
    close(pipe_read);
    close(pipe_write);
    return NULL;
  }

  if (child_pid == 0) {
    // CHILD PROCESS
    int child_pipes[2];
    pipe(child_pipes);
    dup2(pipe_write, STDOUT_FILENO);
    dup2(child_pipes[0], STDIN_FILENO);

    write(child_pipes[1], " ", 1);
    close(child_pipes[0]);
    close(child_pipes[1]);
    close(pipe_read);
    close(pipe_write);

    if (execvp(argv[0], (void *)argv) == -1) {
      g_error("failed to launch program: %s\n", argv[0]);
      exit(1);
    }

    exit(0);
  } else {
    // PARENT PROCESS
    close(pipe_write);

    ssize_t len = read(pipe_read, buffer, buffer_size - 1);
    if (len == -1) {
      g_error("failed to read stdout from child process\n");
      close(pipe_read);
      wait(NULL);
      return NULL;
    } else {
      if (len != 0) {
        // terminate string at newline
        buffer[len - 1] = 0;
      } else {
        // terminate string
        buffer[0] = 0;
      }
      close(pipe_read);
      wait(NULL);
      return buffer;
    }
  }
}
