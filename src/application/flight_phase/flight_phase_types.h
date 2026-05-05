/**
 * Types from Flight Phase used globally
 */
#ifndef FLIGHT_PHASE_TYPES_H
#define FLIGHT_PHASE_TYPES_H

/**
 * context/memory type structs
 */

/**
 * data storage (format) structs/enum
 */

/**
 * Enum representing a state transition event
 */
typedef enum {
	EVENT_NONE,
	EVENT_ESTIMATOR_INIT,
	EVENT_INJ_OPEN,
	EVENT_ACT_DELAY_ELAPSED,
	EVENT_FLIGHT_ELAPSED,
	EVENT_RESET
} flight_phase_event_t;

#endif
