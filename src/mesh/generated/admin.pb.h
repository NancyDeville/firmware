/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6 */

#ifndef PB_ADMIN_PB_H_INCLUDED
#define PB_ADMIN_PB_H_INCLUDED
#include <pb.h>
#include "channel.pb.h"
#include "config.pb.h"
#include "device_metadata.pb.h"
#include "mesh.pb.h"
#include "module_config.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _AdminMessage_ConfigType { 
    AdminMessage_ConfigType_DEVICE_CONFIG = 0, 
    AdminMessage_ConfigType_POSITION_CONFIG = 1, 
    AdminMessage_ConfigType_POWER_CONFIG = 2, 
    AdminMessage_ConfigType_NETWORK_CONFIG = 3, 
    AdminMessage_ConfigType_DISPLAY_CONFIG = 4, 
    AdminMessage_ConfigType_LORA_CONFIG = 5, 
    AdminMessage_ConfigType_BLUETOOTH_CONFIG = 6 
} AdminMessage_ConfigType;

typedef enum _AdminMessage_ModuleConfigType { 
    AdminMessage_ModuleConfigType_MQTT_CONFIG = 0, 
    AdminMessage_ModuleConfigType_SERIAL_CONFIG = 1, 
    AdminMessage_ModuleConfigType_EXTNOTIF_CONFIG = 2, 
    AdminMessage_ModuleConfigType_STOREFORWARD_CONFIG = 3, 
    AdminMessage_ModuleConfigType_RANGETEST_CONFIG = 4, 
    AdminMessage_ModuleConfigType_TELEMETRY_CONFIG = 5, 
    AdminMessage_ModuleConfigType_CANNEDMSG_CONFIG = 6 
} AdminMessage_ModuleConfigType;

/* Struct definitions */
/* This message is handled by the Admin module and is responsible for all settings/channel read/write operations.
 This message is used to do settings operations to both remote AND local nodes.
 (Prior to 1.2 these operations were done via special ToRadio operations) */
typedef struct _AdminMessage { 
    pb_size_t which_payload_variant;
    union {
        /* Send the specified channel in the response to this message
     NOTE: This field is sent with the channel index + 1 (to ensure we never try to send 'zero' - which protobufs treats as not present) */
        uint32_t get_channel_request;
        /* TODO: REPLACE */
        Channel get_channel_response;
        /* Send the current owner data in the response to this message. */
        bool get_owner_request;
        /* TODO: REPLACE */
        User get_owner_response;
        /* Ask for the following config data to be sent */
        AdminMessage_ConfigType get_config_request;
        /* Send the current Config in the response to this message. */
        Config get_config_response;
        /* Ask for the following config data to be sent */
        AdminMessage_ModuleConfigType get_module_config_request;
        /* Send the current Config in the response to this message. */
        ModuleConfig get_module_config_response;
        /* Send all channels in the response to this message */
        bool get_all_channel_request;
        /* Get the Canned Message Module messages in the response to this message. */
        bool get_canned_message_module_messages_request;
        /* Get the Canned Message Module messages in the response to this message. */
        char get_canned_message_module_messages_response[201];
        /* Request the node to send device metadata (firmware, protobuf version, etc) */
        uint32_t get_device_metadata_request;
        /* Device metadata response */
        DeviceMetadata get_device_metadata_response;
        /* Set the owner for this node */
        User set_owner;
        /* Set channels (using the new API).
     A special channel is the "primary channel".
     The other records are secondary channels.
     Note: only one channel can be marked as primary.
     If the client sets a particular channel to be primary, the previous channel will be set to SECONDARY automatically. */
        Channel set_channel;
        /* Set the current Config */
        Config set_config;
        /* Set the current Config */
        ModuleConfig set_module_config;
        /* Set the Canned Message Module messages text. */
        char set_canned_message_module_messages[201];
        /* Sent immediatly after a config change has been sent to ensure comms, if this is not recieved, the config will be reverted after 10 mins */
        bool confirm_set_config;
        /* Sent immediatly after a config change has been sent to ensure comms, if this is not recieved, the config will be reverted after 10 mins */
        bool confirm_set_module_config;
        /* Setting channels/radio config remotely carries the risk that you might send an invalid config and the radio never talks to your mesh again.
     Therefore if setting either of these properties remotely, you must send a confirm_xxx message within 10 minutes.
     If you fail to do so, the radio will assume loss of comms and revert your changes.
     These messages are optional when changing the local node. */
        bool confirm_set_channel;
        /* TODO: REPLACE */
        bool confirm_set_radio;
        /* This message is only supported for the simulator porduino build.
     If received the simulator will exit successfully. */
        bool exit_simulator;
        /* Tell the node to reboot in this many seconds (or <0 to cancel reboot) */
        int32_t reboot_seconds;
        /* Tell the node to shutdown in this many seconds (or <0 to cancel shutdown) */
        int32_t shutdown_seconds;
        /* Tell the node to factory reset, all device settings will be returned to factory defaults. */
        int32_t factory_reset;
    };
} AdminMessage;


/* Helper constants for enums */
#define _AdminMessage_ConfigType_MIN AdminMessage_ConfigType_DEVICE_CONFIG
#define _AdminMessage_ConfigType_MAX AdminMessage_ConfigType_BLUETOOTH_CONFIG
#define _AdminMessage_ConfigType_ARRAYSIZE ((AdminMessage_ConfigType)(AdminMessage_ConfigType_BLUETOOTH_CONFIG+1))

#define _AdminMessage_ModuleConfigType_MIN AdminMessage_ModuleConfigType_MQTT_CONFIG
#define _AdminMessage_ModuleConfigType_MAX AdminMessage_ModuleConfigType_CANNEDMSG_CONFIG
#define _AdminMessage_ModuleConfigType_ARRAYSIZE ((AdminMessage_ModuleConfigType)(AdminMessage_ModuleConfigType_CANNEDMSG_CONFIG+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define AdminMessage_init_default                {0, {0}}
#define AdminMessage_init_zero                   {0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define AdminMessage_get_channel_request_tag     1
#define AdminMessage_get_channel_response_tag    2
#define AdminMessage_get_owner_request_tag       3
#define AdminMessage_get_owner_response_tag      4
#define AdminMessage_get_config_request_tag      5
#define AdminMessage_get_config_response_tag     6
#define AdminMessage_get_module_config_request_tag 7
#define AdminMessage_get_module_config_response_tag 8
#define AdminMessage_get_all_channel_request_tag 9
#define AdminMessage_get_canned_message_module_messages_request_tag 10
#define AdminMessage_get_canned_message_module_messages_response_tag 11
#define AdminMessage_get_device_metadata_request_tag 12
#define AdminMessage_get_device_metadata_response_tag 13
#define AdminMessage_set_owner_tag               32
#define AdminMessage_set_channel_tag             33
#define AdminMessage_set_config_tag              34
#define AdminMessage_set_module_config_tag       35
#define AdminMessage_set_canned_message_module_messages_tag 36
#define AdminMessage_confirm_set_config_tag      64
#define AdminMessage_confirm_set_module_config_tag 65
#define AdminMessage_confirm_set_channel_tag     66
#define AdminMessage_confirm_set_radio_tag       67
#define AdminMessage_exit_simulator_tag          96
#define AdminMessage_reboot_seconds_tag          97
#define AdminMessage_shutdown_seconds_tag        98
#define AdminMessage_factory_reset_tag           99

/* Struct field encoding specification for nanopb */
#define AdminMessage_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    UINT32,   (payload_variant,get_channel_request,get_channel_request),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_channel_response,get_channel_response),   2) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_owner_request,get_owner_request),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_owner_response,get_owner_response),   4) \
X(a, STATIC,   ONEOF,    UENUM,    (payload_variant,get_config_request,get_config_request),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_config_response,get_config_response),   6) \
X(a, STATIC,   ONEOF,    UENUM,    (payload_variant,get_module_config_request,get_module_config_request),   7) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_module_config_response,get_module_config_response),   8) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_all_channel_request,get_all_channel_request),   9) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_canned_message_module_messages_request,get_canned_message_module_messages_request),  10) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,get_canned_message_module_messages_response,get_canned_message_module_messages_response),  11) \
X(a, STATIC,   ONEOF,    UINT32,   (payload_variant,get_device_metadata_request,get_device_metadata_request),  12) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_device_metadata_response,get_device_metadata_response),  13) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_owner,set_owner),  32) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_channel,set_channel),  33) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_config,set_config),  34) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_module_config,set_module_config),  35) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,set_canned_message_module_messages,set_canned_message_module_messages),  36) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,confirm_set_config,confirm_set_config),  64) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,confirm_set_module_config,confirm_set_module_config),  65) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,confirm_set_channel,confirm_set_channel),  66) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,confirm_set_radio,confirm_set_radio),  67) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,exit_simulator,exit_simulator),  96) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,reboot_seconds,reboot_seconds),  97) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,shutdown_seconds,shutdown_seconds),  98) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,factory_reset,factory_reset),  99)
#define AdminMessage_CALLBACK NULL
#define AdminMessage_DEFAULT NULL
#define AdminMessage_payload_variant_get_channel_response_MSGTYPE Channel
#define AdminMessage_payload_variant_get_owner_response_MSGTYPE User
#define AdminMessage_payload_variant_get_config_response_MSGTYPE Config
#define AdminMessage_payload_variant_get_module_config_response_MSGTYPE ModuleConfig
#define AdminMessage_payload_variant_get_device_metadata_response_MSGTYPE DeviceMetadata
#define AdminMessage_payload_variant_set_owner_MSGTYPE User
#define AdminMessage_payload_variant_set_channel_MSGTYPE Channel
#define AdminMessage_payload_variant_set_config_MSGTYPE Config
#define AdminMessage_payload_variant_set_module_config_MSGTYPE ModuleConfig

extern const pb_msgdesc_t AdminMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define AdminMessage_fields &AdminMessage_msg

/* Maximum encoded size of messages (where known) */
#define AdminMessage_size                        204

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
