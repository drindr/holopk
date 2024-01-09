#pragma once

#include <stddef.h>

const char *read_input(const char *const *argv, char *buffer,
                       size_t buffer_size);

extern const char **menu_cmd;
