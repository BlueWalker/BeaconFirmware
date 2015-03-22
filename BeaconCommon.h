#ifndef BEACON_COMMON_H_
#define BEACON_COMMON_H_

#include "stdint.h"
#include "softdevice_handler.h"
#include "nordic_common.h"

static uint16_t const APP_COMPANY_IDENTIFIER       = 0x0059;
static uint8_t const MAJ_VAL_OFFSET_IN_BEACON_INFO = 18;
static uint32_t const UICR_ADDRESS                 = 0x10001080;
static uint16_t const APP_BEACON_INFO_LENGTH       = 0x17;
/**< Time for which the device must be advertising in non-connectable mode (in seconds). 0 disables timeout. */
static uint16_t const APP_CFG_NON_CONN_ADV_TIMEOUT = 0;
/**< The advertising interval for non-connectable advertisement (100 ms). This value can vary between 100ms to 10.24s). */
static uint16_t const NON_CONNECTABLE_ADV_INTERVAL = MSEC_TO_UNITS(100, UNIT_0_625_MS);
/**< Length of manufacturer specific data in the advertisement. */
static uint8_t const APP_ADV_DATA_LENGTH           = 0x15;
/**< 0x02 refers to Beacon. */
static uint8_t const APP_DEVICE_TYPE               = 0x02;
/**< The Beacon's measured RSSI at 1 meter distance in dBm. */
static uint8_t const APP_MEASURED_RSSI             = 0xC3;
/**< Major value used to identify Beacons. */
static uint16_t const APP_MAJOR_VALUE            = 0x0102;
/**< Minor value used to identify Beacons. */
static uint8_t APP_MINOR_VALUE[2]            = {0x03, 0x04};

 /**< Proprietary UUID for Beacon. */
static uint8_t APP_BEACON_UUID[16]                 = {0x01, 0x12, 0x23, 0x34,
                                                      0x45, 0x56, 0x67, 0x78,
                                                      0x89, 0x9a, 0xab, 0xbc,
                                                      0xcd, 0xde, 0xef, 0xf0};

static uint32_t const DEAD_BEEF = 0xDEADBEEF;

void app_error_handler(uint32_t error_code, uint32_t line_num, const uint8_t * p_file_name);

void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name);

#endif // BEACON_COMMON_H_
