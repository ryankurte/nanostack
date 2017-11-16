/*
 * Copyright (c) 2015, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include "coap_connection_handler.h"
#include "coap_security_handler.h"
#include "ns_list.h"
#include "ns_trace.h"
#include "nsdynmemLIB.h"
#include "socket_api.h"
#include "net_interface.h"
#include "randLIB.h"
#include "eventOS_callback_timer.h"
#include "coap_connection_handler_stub.h"

thread_conn_handler_stub_def thread_conn_handler_stub;

int coap_connection_handler_virtual_recv(thread_conn_handler_t *handler, uint8_t address[static 16], uint16_t port, uint8_t *data_ptr, uint16_t data_len)
{
    return thread_conn_handler_stub.int_value;
}

thread_conn_handler_t *connection_handler_create(int (*recv_cb)(int8_t socket_id, uint8_t address[static 16], uint16_t port, unsigned char *, int),
                                                 int (*send_cb)(int8_t socket_id, uint8_t address[static 16], uint16_t port, const unsigned char *, int),
                                                 int (*pw_cb)(int8_t socket_id, uint8_t address[static 16], uint16_t port, uint8_t *pw_ptr, uint8_t *pw_len),
                                                 void(*done_cb)(int8_t socket_id, uint8_t address[static 16], uint16_t port, uint8_t keyblock[static KEY_BLOCK_LEN]) )
{
    thread_conn_handler_stub.send_to_sock_cb = send_cb;
    thread_conn_handler_stub.receive_from_sock_cb = recv_cb;
    thread_conn_handler_stub.get_passwd_cb = pw_cb;
    thread_conn_handler_stub.sec_done_cb = done_cb;
    return thread_conn_handler_stub.handler_obj;
}

void connection_handler_destroy(thread_conn_handler_t *handler)
{

}

int coap_connection_handler_open_connection(thread_conn_handler_t *handler, uint16_t listen_port, bool use_ephemeral_port, bool is_secure, bool is_real_socket, bool bypassSec)
{
    return thread_conn_handler_stub.int_value;
}

int coap_connection_handler_send_data(thread_conn_handler_t *handler, ns_address_t *dest_addr, uint8_t *data_ptr, uint16_t data_len, bool bypass_link_sec)
{
    return thread_conn_handler_stub.int_value;
}

bool coap_connection_handler_socket_belongs_to(thread_conn_handler_t *handler, int8_t socket_id)
{
    return thread_conn_handler_stub.bool_value;
}
