#ifndef __BLE_CONFIG_H
#define __BLE_CONFIG_H

#include "app_timer.h"
#include "boards.h"

// CONSTS --------------------------------------------------------------------------------------------------------------

// SUMMON URL (must be <= 17 characters to not throw NRF_ERROR_INVALID_LENGTH, as header overhead is 14 byte and packet has size <= 31)
//#define PHYSWEB_URL "n.ethz.ch/~abiri/d"
#define PHYSWEB_URL "bit.ly/p1R8"

// Information
#define APP_COMPANY_IDENTIFIER 0x02E0
#define APP_SERVICE_ID         0x0022
#define MANUFACTURER_NAME      "Lab11"
#define MODEL_NUMBER           DEVICE_NAME
#define HARDWARE_REVISION      "D"
#define FIRMWARE_REVISION      "0.1"

// Behaviour
#define UPDATE_RATE             APP_TIMER_TICKS(1000)

// Structs -------------------------------------------------------------------------------------------------------------

typedef struct ble_app_s {
    uint8_t                      current_location[6];    /** Value of num characteristic */
    uint8_t                      app_raw_response_buffer[128]; // Buffer to store raw responses from module so that it can be sent over BLE
    uint16_t                     app_raw_response_length;
    bool                         app_ranging_enabled; // Whether or not the module is running and ranging
    uint8_t                      calibration_index;
} ble_app_t;

// BLE -----------------------------------------------------------------------------------------------------------------

// Physical Web
#define PHYSWEB_SERVICE_ID  0xFEAA
#define PHYSWEB_URL_TYPE    0x10    // Denotes URLs (vs URIs or TLM data)
#define PHYSWEB_TX_POWER    0xBA    // Tx Power. Measured at 1 m plus 41 dBm. (who cares)

#define PHYSWEB_URLSCHEME_HTTPWWW   0x00    // http://www.
#define PHYSWEB_URLSCHEME_HTTPSWWW  0x01    // https://www.
#define PHYSWEB_URLSCHEME_HTTP      0x02    // http://
#define PHYSWEB_URLSCHEME_HTTPS     0x03    // https://

#define PHYSWEB_URLEND_COMSLASH 0x00    // .com/
#define PHYSWEB_URLEND_ORGSLASH 0x01    // .org/
#define PHYSWEB_URLEND_EDUSLASH 0x02    // .edu/
#define PHYSWEB_URLEND_COM      0x07    // .com
#define PHYSWEB_URLEND_ORG      0x08    // .org
#define PHYSWEB_URLEND_EDU      0x09    // .edu


/**
 * Eddystone App configurations, adapted from nRF example
 * "examples\ble_peripheral\ble_app_eddystone\es_app_config.h"
 */

//!< Beacon lock code
#define APP_CONFIG_LOCK_CODE {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}

#define APP_CONFIG_CALIBRATED_RANGING_DATA {-49, -39, -29, -24, -19, -14, -9, -7, -5}   //!< Calibrated TX power at 0 m. See the nRF52 Product Specification for corresponding TX values.

#define APP_CONFIG_TLM_TEMP_VBATT_UPDATE_INTERVAL_SECONDS   10                          //!< How often should the data in the TLM frame be updated.
#define APP_CONFIG_TLM_ADV_INTERLEAVE_RATIO                 5                           //!< How often should the TLM frame be advertised.


#define APP_CONFIG_ADV_INTERVAL_MS_MAX                      20000                       //!< Maximum allowed advertisement interval. Can be undefined without int
#define APP_CONFIG_ADV_FRAME_SPACING_MS_MIN                 500                         //!< Minimum time between advertisement frames. Imposes limit on minumum accepted advertisement interval
#define APP_CONFIG_ADV_FRAME_ETLM_SPACING_MS                300                         //!< The time that is reqired for preparing an eTLM slot. Imposes limit on minimum accepted advertisement interval.

#define ES_STOPWATCH_MAX_USERS                              4                           //!< Maximum amount of users that can be registered with the es_stopwatch module.

#define DEBUG_TIMING_INIT_VALUE                             65280                       //!< Initial time (as recommended by Google) to test the TK rollover behavior.
#define APP_CONFIG_TIMING_INIT_VALUE                        DEBUG_TIMING_INIT_VALUE     //!< Initializing value for the timing value of security slots.

#define APP_CONFIG_TLM_TEMP_INTERVAL_SECONDS                (30)                        //!< How often should the temperature of the beacon be updated when TLM slot is configured.
#define APP_CONFIG_TLM_VBATT_INTERVAL_SECONDS               (30)                        //!< How often should the battery voltage of the beacon be updated when TLM slot is configured.

// BLE CONFIGS
#define APP_DEVICE_NAME                                     DEVICE_NAME                 //!< Advertised device name in the scan response when in connectable mode.
#define IS_SRVC_CHANGED_CHARACT_PRESENT                     0                           //!< Information whether the service changed characteristic is available. If it is not enabled, the server's database cannot be changed for the lifetime of the device.
#define MAX_ADV_INTERVAL                                    (1000)                     //!< Maximum connection interval (in ms).
#define MIN_CONN_ADV_INTERVAL                               (20)                        //!< Minimum connection interval (in ms).
#define MIN_NON_CONN_ADV_INTERVAL                           (100)                       //!< Minimum advertisement interval for non-connectable advertisements (in ms).

#define CENTRAL_LINK_COUNT                                  0                           //!< Number of central links used by the application. When changing this number, remember to adjust the RAM settings.
#define PERIPHERAL_LINK_COUNT                               1                           //!< Number of peripheral links used by the application. When changing this number, remember to adjust the RAM settings.

#define APP_CFG_NON_CONN_ADV_TIMEOUT                        0                           //!< Time for which the device must be advertising in non-connectable mode (in seconds). 0 disables the time-out.
#define APP_CFG_NON_CONN_ADV_INTERVAL_MS                    1000                        //!< The advertising interval for non-connectable advertisement (in milliseconds). This value can vary between 100 ms and 10.24 s.
#define APP_CFG_CONNECTABLE_ADV_TIMEOUT                     6000                        //!< Time for which the device must be advertising in connectable mode (in milliseconds). 0 disables the time-out.
#define APP_CFG_CONNECTABLE_ADV_INTERVAL_MS                 100                         //!< The advertising interval for connectable advertisement (in milliseconds). This value can vary between 20 ms and 10.24 s.

#define APP_CFG_DEFAULT_RADIO_TX_POWER                      0x00                        //!< Default TX power of the radio.

#define APP_ADV_INTERVAL                    MSEC_TO_UNITS(300, UNIT_0_625_MS)

#define MIN_CONN_INTERVAL                   MSEC_TO_UNITS(50, UNIT_1_25_MS)             //!< Minimum acceptable connection interval (50 ms). The connection interval uses 1.25 ms units.
#define MAX_CONN_INTERVAL                   MSEC_TO_UNITS(100, UNIT_1_25_MS)            //!< Maximum acceptable connection interval (100 ms). The connection interval uses 1.25 ms units.
#define SLAVE_LATENCY                       0                                           //!< Slave latency.
#define CONN_SUP_TIMEOUT                    MSEC_TO_UNITS(4000, UNIT_10_MS)             //!< Connection supervision time-out (4 seconds). The supervision time-out uses 10 ms units.
#define FIRST_CONN_PARAMS_UPDATE_DELAY      APP_TIMER_TICKS(5000)                       //!< Time from initiating an event (connection or start of notification) to the first time @ref sd_ble_gap_conn_param_update is called (5 seconds).
#define NEXT_CONN_PARAMS_UPDATE_DELAY       APP_TIMER_TICKS(30000)                      //!< Time between each call to @ref sd_ble_gap_conn_param_update after the first call (30 seconds).
#define MAX_CONN_PARAMS_UPDATE_COUNT        3                                           //!< Number of attempts before giving up the connection parameter negotiation.

// Priority of the application BLE event handler.
#define APP_BLE_OBSERVER_PRIO               3
#define APP_BLE_CONN_CFG_TAG                BLE_CONN_CFG_TAG_DEFAULT                    /**< A tag identifying the SoftDevice BLE configuration. */

// ES CONFIGS
#define APP_MAX_ADV_SLOTS                   5                                           //!< Maximum number of advertisement slots.
#define APP_MAX_EID_SLOTS                   APP_MAX_ADV_SLOTS                           /**< @brief Maximum number of EID slots.
                                                                                         * @note The maximum number of EID slots must be equal to the maximum number of advertisement slots */

// Broadcast Capabilities
#define APP_IS_VARIABLE_ADV_SUPPORTED       ESCS_BROADCAST_VAR_ADV_SUPPORTED_No         //!< Information whether variable advertisement intervals are supported.
#define APP_IS_VARIABLE_TX_POWER_SUPPORTED  ESCS_BROADCAST_VAR_TX_POWER_SUPPORTED_Yes   //!< Information whether variable advertisement TX power is supported.

#define APP_IS_UID_SUPPORTED                ESCS_FRAME_TYPE_UID_SUPPORTED_Yes           //!< Information whether the UID frame is supported.
#define APP_IS_URL_SUPPORTED                ESCS_FRAME_TYPE_URL_SUPPORTED_Yes           //!< Information whether the URL frame is supported.
#define APP_IS_TLM_SUPPORTED                ESCS_FRAME_TYPE_TLM_SUPPORTED_Yes           //!< Information whether the TLM frame is supported.
#define APP_IS_EID_SUPPORTED                ESCS_FRAME_TYPE_EID_SUPPORTED_No            //!< Information whether the EID frame is supported.

// Remain connectable
#define APP_IS_REMAIN_CONNECTABLE_SUPPORTED ESCS_FUNCT_REMAIN_CONNECTABLE_SUPPORTED_Yes //!< Information whether the 'remain connectable' option is supported.

// Eddystone common data
#define APP_ES_UUID                         0xFEAA                                      //!< UUID for Eddystone beacons according to specification.

// Eddystone UID data
#define APP_ES_UID_FRAME_TYPE               ES_FRAME_TYPE_UID                                          //!< UID frame type (fixed at 0x00).
#define APP_ES_UID_NAMESPACE                0x2e, 0x5d, 0x5e, 0x39, 0x31, 0x52, 0x45, 0x0c, 0x90, 0xee //!< 10-byte Eddystone UID ID namespace.
#define APP_ES_UID_ID                       0x3f, 0xa2, 0x31, 0x52, 0x8c, 0xd6                         //!< 6-byte Eddystone UID ID instance.

// Eddystone URL data
#define APP_ES_URL_FRAME_TYPE               ES_FRAME_TYPE_URL                           //!< URL Frame type (fixed at 0x10).
#define APP_ES_URL_SCHEME                   PHYSWEB_URLSCHEME_HTTPS                     //!< URL prefix scheme according to specification (0x01 = "https://www", 0x03 = "https://).
#define APP_ES_URL_URL                      'b', 'i', 't', '.', 'l', 'y', '/', \
                                            'p', '1', 'R', '8'                          //!< PHYSWEB_URL. Can use last byte suffix 0x00 = ".com" according to specification.

#define DEFAULT_FRAME_TYPE                  APP_ES_URL_FRAME_TYPE                       //!< Frame type of default frame.
#define DEFAULT_FRAME_TX_POWER              0x00                                        //!< Default frame TX power.

/** @brief This value should mimic the data that would be written to the RW ADV Slot characteristic (for example, no RSSI for UID). */
#define DEFAULT_FRAME_DATA                  {DEFAULT_FRAME_TYPE, DEFAULT_FRAME_TX_POWER, APP_ES_URL_SCHEME, APP_ES_URL_URL}
#define DEFAULT_FRAME_LENGTH                14                                          //!< 1 - Frame Type, 1 - TX - power 1 - URL Scheme, URL - 11 = 14

// SCHEDULER CONFIGS
#define SCHED_MAX_EVENT_DATA_SIZE           APP_TIMER_SCHED_EVENT_DATA_SIZE             //!< Maximum size of the scheduler event data.
#define SCHED_QUEUE_SIZE                    10                                          //!< Size of the scheduler queue.

#endif