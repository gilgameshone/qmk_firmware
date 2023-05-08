#include "print.h"
#include "oneshot.h"

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
            dprintf("trigger down (on?), mod: %d, ? -> os_down_unused\n", mod);
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                dprintf("trigger up, mod: %d, os_down_unused -> os_up_queued\n", mod);
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                dprintf("trigger up (off), mod: %d, os_down_used -> os_up_unqueued\n", mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
                dprintf("cancel (off), mod: %d, ? -> os_up_unqueued\n", mod);
            }
            if (!is_oneshot_ignored_key(keycode)) {
                switch (*state) {
                case os_up_queued:
                    *state = os_up_queued_used;
                    dprintf("key up (off), mod: %d, os_up_queued -> os_up_queued_used\n", mod);
                    break;
                case os_up_queued_used:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    dprintf("key up (off), mod: %d, os_up_queued_used -> os_up_unqueued\n", mod);
                    break;
                default:
                    break;
                }
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    dprintf("key up, mod: %d, os_down_unused -> os_down_used\n", mod);
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    dprintf("key up (off), mod: %d, os_up_queued -> os_up_unqueued\n", mod);
                    break;
                case os_up_queued_used:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    dprintf("key up (off), mod: %d, os_up_queued_used -> os_up_unqueued\n", mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
