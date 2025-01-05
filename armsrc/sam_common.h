//-----------------------------------------------------------------------------
// Copyright (C) Proxmark3 contributors. See AUTHORS.md for details.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See LICENSE.txt for the text of the license.
//-----------------------------------------------------------------------------
#ifndef __SAM_COMMON_H
#define __SAM_COMMON_H

#include "common.h"

static const uint8_t SAM_TX_APDU_PREFIX_LENGTH = 5;
static const uint8_t SAM_TX_ASN1_PREFIX_LENGTH = 6;
static const uint8_t SAM_RX_ASN1_PREFIX_LENGTH = 5;

int sam_rxtx(const uint8_t *data, uint16_t n, uint8_t *resp, uint16_t *resplen);

void switch_clock_to_ticks(void);
void switch_clock_to_countsspclk(void);

int sam_send_payload(
    uint8_t addr_src,
    uint8_t addr_dest,
    uint8_t addr_reply,

    uint8_t *payload,
    uint16_t *payload_len,

    uint8_t *response,
    uint16_t *response_len
);

int sam_get_version(void);

uint8_t * sam_find_asn1_node(uint8_t * root, const uint8_t type);
void sam_append_asn1_node(uint8_t * root, uint8_t * node, uint8_t type, uint8_t * data, uint8_t len);

void sam_send_ack(void);

#endif
