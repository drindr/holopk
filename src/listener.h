#pragma once

#define POLKIT_AGENT_I_KNOW_API_IS_SUBJECT_TO_CHANGE
#include <polkitagent/polkitagent.h>
#include <polkit/polkit.h>

G_BEGIN_DECLS

#define HOLO_TYPE_POLKIT_LISTENER (holo_polkit_listener_get_type())
#define HOLO_POLKIT_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj, HOLO_TYPE_POLKIT_LISTENER, HoloPolkitListener)))
#define HOLO_IS_POLKIT_LISTENER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj), HOLO_TYPE_POLKIT_LISTENER))
#define HOLO_IS_POLKIT_LISTENER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass), HOLO_TYPE_POLKIT_LISTENER))
#define HOLO_POLKIT_LISTENER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), HOLO_TYPE_POLKIT_LISTENER, HoloPolkitListenerClass))


typedef struct _HoloPolkitListener	HoloPolkitListener;
typedef struct _HoloPolkitListenerClass	HoloPolkitListenerClass;

struct _HoloPolkitListener {
		PolkitAgentListener parent;
};

struct _HoloPolkitListenerClass {
		PolkitAgentListenerClass parent_class;
};

GType holo_polkit_listener_get_type(void);
PolkitAgentListener* holo_polkit_listener_new(void);

G_END_DECLS
