#ifndef __APP_TEST_COMMON_H
#define __APP_TEST_COMMON_H

#include "module_conf.h"
#include "system.h"
#include "dw1000.h"
#include "timer.h"
#include "app_standard_common.h"

/******************************************************************************/
// Parameters for the localization and ranging protocol
/******************************************************************************/

// How many of the DW1000 supported UWB channels we are using for ranging
// packets.
#define NUM_RANGING_CHANNELS 3

// It's possible that someday the number of antennas should be configurable
// to support different hardware...
#define NUM_ANTENNAS 3

/******************************************************************************/
// Data Structs for packet messages between tags and anchors
/******************************************************************************/

// Message types that identify the UWB packets. Very reminiscent of
// Active Messages from the TinyOS days.
#define MSG_TYPE_PP_NOSLOTS_TAG_POLL  0x80

// Used to show whether message is a ranging packet or not
#define MSG_TYPE_CONTROL	0
#define MSG_TYPE_RANGING	1

// Packet the tag broadcasts to all nearby anchors
struct rangetest_packet  {
	struct ieee154_header_broadcast header;
	uint8_t message_type;                   // Packet type identifier so the anchor knows what it is receiving.
	uint8_t subsequence;                    // Index of which broadcast sequence number this packet is.
	uint8_t reply_after_subsequence;        // Tells anchor which broadcast subsequence number to respond after.
	uint32_t anchor_reply_window_in_us;     // How long each anchor response window is. Each window allows multiple anchor responses.
	uint16_t anchor_reply_slot_time_in_us;  // How long that slots that break up each window are.
	struct ieee154_footer footer;
} __attribute__ ((__packed__));

/******************************************************************************/
// State objects for the Rangetest application
/******************************************************************************/

// Keep config settings for a node
typedef struct {
	module_role_e my_role;
	uint8_t update_rate;
} test_config_t;

void rangetest_configure (module_config_t* config);
void rangetest_start ();

void rangetest_set_ranging_broadcast_settings (module_role_e role, uint8_t subseq_num);

extern dwt_config_t simpletest_config;
void simpletest_configure (module_config_t* config);

#endif
