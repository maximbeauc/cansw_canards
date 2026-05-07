/**
 * Types from Controller used globally
 */
#ifndef CONTROLLER_TYPES_H
#define CONTROLLER_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#include "application/controller/gain_table.h"

#define FEEDBACK_GAIN_NUM (GAIN_NUM - 1) // subtract 1 for the pre-gain
#define ROLL_STATE_NUM (FEEDBACK_GAIN_NUM)
#define MIN_COOR_BOUND 0

/**
 * data storage (format) structs
 */

typedef union {
	double roll_state_arr[ROLL_STATE_NUM];

	struct {
		double roll_angle;
		double roll_rate;
		double canard_angle;
	};
} roll_state_t;

// input from state estimation module
typedef struct {
	// Roll state
	roll_state_t roll_state;
	// Scheduling variables (flight condition)
	double pressure_dynamic;
	double canard_coeff;
	// TODO: potentially also examine if a timestamp would be more appropriate
	// check for freshness of the input
	// this is done to make sure only under a few state are the new cmd actually going to be
	// indicated as usable by the system (this is to keep in structure with last years system,
	// though this seem very redundent)
	bool state_updated;
} controller_input_t;

// Output of controller: latest commanded canard angle
typedef struct {
	double commanded_angle; // radians
	uint32_t timestamp; // ms
	bool cmd_updated; // this has now going to be used to let motor know if the there was a command
					  // update or not (this should be set false by the motor once read)
} controller_output_t;

#endif
