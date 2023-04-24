// Generated Code - DO NOT EDIT !!
// generated by 'emugen'
#ifndef __GUARD_magma_opcodes_h_
#define __GUARD_magma_opcodes_h_

#define OP_magma_device_import 					100000
#define OP_magma_device_release 					100001
#define OP_magma_device_query 					100002
#define OP_magma_device_create_connection 					100003
#define OP_magma_connection_release 					100004
#define OP_magma_connection_get_error 					100005
#define OP_magma_connection_create_context 					100006
#define OP_magma_connection_release_context 					100007
#define OP_magma_connection_create_buffer 					100008
#define OP_magma_connection_release_buffer 					100009
#define OP_magma_connection_import_buffer 					100010
#define OP_magma_connection_create_semaphore 					100011
#define OP_magma_connection_release_semaphore 					100012
#define OP_magma_connection_import_semaphore 					100013
#define OP_magma_connection_perform_buffer_op 					100014
#define OP_magma_connection_map_buffer 					100015
#define OP_magma_connection_unmap_buffer 					100016
#define OP_magma_connection_execute_command 					100017
#define OP_magma_connection_execute_command_fudge 					100018
#define OP_magma_connection_execute_immediate_commands 					100019
#define OP_magma_connection_execute_immediate_commands_fudge 					100020
#define OP_magma_connection_flush 					100021
#define OP_magma_connection_get_notification_channel_handle 					100022
#define OP_magma_connection_read_notification_channel 					100023
#define OP_magma_buffer_clean_cache 					100024
#define OP_magma_buffer_set_cache_policy 					100025
#define OP_magma_buffer_get_cache_policy 					100026
#define OP_magma_buffer_set_name 					100027
#define OP_magma_buffer_set_name_fudge 					100028
#define OP_magma_buffer_get_info 					100029
#define OP_magma_buffer_get_handle 					100030
#define OP_magma_buffer_export 					100031
#define OP_magma_semaphore_signal 					100032
#define OP_magma_semaphore_reset 					100033
#define OP_magma_semaphore_export 					100034
#define OP_magma_poll 					100035
#define OP_magma_initialize_tracing 					100036
#define OP_magma_initialize_logging 					100037
#define OP_magma_connection_enable_performance_counter_access 					100038
#define OP_magma_connection_enable_performance_counters 					100039
#define OP_magma_connection_create_performance_counter_buffer_pool 					100040
#define OP_magma_connection_release_performance_counter_buffer_pool 					100041
#define OP_magma_connection_add_performance_counter_buffer_offsets_to_pool 					100042
#define OP_magma_connection_remove_performance_counter_buffer_from_pool 					100043
#define OP_magma_connection_dump_performance_counters 					100044
#define OP_magma_connection_clear_performance_counters 					100045
#define OP_magma_connection_read_performance_counter_completion 					100046
#define OP_magma_virt_connection_create_image 					100047
#define OP_magma_virt_connection_get_image_info 					100048
#define OP_last 					100049


#endif
