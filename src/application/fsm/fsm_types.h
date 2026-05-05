/**
 * Types from FSM used globally
 */
#ifndef FSM_TYPES_H
#define FSM_TYPES_H

/**
 * context/memory type structs
 */

/**
 * data storage (format) structs/enum
 */

/**
 * Enum representing phase of flight (state machine state)
 */
typedef enum {
	STATE_IDLE,
	STATE_SE_INIT,
	STATE_BOOST,
	STATE_ACT_ALLOWED,
	STATE_RECOVERY,
	STATE_ERROR
} fsm_state_t;

#endif
