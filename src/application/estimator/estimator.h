#ifndef STATE_EST_H
#define STATE_EST_H

#include "application/controller/controller_types.h"
#include "application/estimator/estimator_internal.h"
#include "application/estimator/estimator_types.h"
#include "application/fsm/fsm_types.h"
#include "common/math/math.h"

#include "third_party/rocketlib/include/common.h"

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Structure to track estimator errors and status
 */
typedef struct {
	bool is_init; /**< Initialization status flag */
	uint32_t imu_data_timeouts; /**< Count of IMU data receive timeouts */
	uint32_t encoder_data_fails; /**< Count of encoder data receive failures */
	uint32_t controller_data_fails; /**< Count of controller output retrieval failures */
	uint32_t pad_filter_fails; /**< Count of pad filter run failures */
	uint32_t can_log_fails; /**< Count of CAN logging failures */
	uint32_t invalid_phase_errors; /**< Count of invalid flight phase errors */
} estimator_error_data_t;

/**
 * @brief initialize estimator module. call before creating estimator task
 */
w_status_t estimator_init();

/**
 * @brief Sends the complete state estimation data over CAN.
 *
 * Iterates through each state ID, builds a CAN message for it using the
 * current state data, and transmits it.
 *
 * @param current_state Pointer to the current state estimation data (x_state_t).
 * @return W_SUCCESS if all messages were sent successfully, W_FAILURE otherwise.
 */
w_status_t estimator_log_state_to_can(const x_state_t *current_state);

/**
 * @brief Report estimator module health status
 *
 * Retrieves and reports estimator error statistics and initialization status
 * through log messages.
 *
 * @return CAN board specific err bitfield
 */
uint32_t estimator_get_status(void);

/**
 * @brief 1 step of estimator
 * @param ctx pointer to estimator context
 * @param curr_fsm_state the current flight phase
 * @param p_latest_imu_data pointer to the latest imu data
 * @param p_controller_context pointer to conrtoller context for both past actuation info and to
 * update with new actuation info
 * @param loop_count for rate limiting
 */
w_status_t estimator_step(estimator_module_ctx_t *ctx, const fsm_state_t curr_fsm_state,
						  const all_sensors_data_t *p_latest_imu_data,
						  controller_ctx_t *p_controller_context, uint32_t loop_count);

#endif

