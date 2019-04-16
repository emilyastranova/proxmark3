//-----------------------------------------------------------------------------
// Copyright (C) 2018 Merlok
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// EMV json logic
//-----------------------------------------------------------------------------
#ifndef EMVJSON_H__
#define EMVJSON_H__

#include <jansson.h>
#include "tlv.h"
#include "commonutil.h"

typedef struct {
    tlv_tag_t Tag;
    const char *Name;
} ApplicationDataElm;

const char *GetApplicationDataName(tlv_tag_t tag);

int JsonSaveJsonObject(json_t *root, const char *path, json_t *value);
int JsonSaveStr(json_t *root, const char *path, const char *value);
int JsonSaveInt(json_t *root, const char *path, int value);
int JsonSaveBufAsHexCompact(json_t *elm, const char *path, uint8_t *data, size_t datalen);
int JsonSaveBufAsHex(json_t *elm, const char *path, uint8_t *data, size_t datalen);
int JsonSaveHex(json_t *elm, const char *path, uint64_t data, int datalen);

int JsonSaveTLVValue(json_t *root, const char *path, struct tlvdb *tlvdbelm);
int JsonSaveTLVElm(json_t *elm, const char *path, struct tlv *tlvelm, bool saveName, bool saveValue, bool saveAppDataLink);
int JsonSaveTLVTreeElm(json_t *elm, const char *path, struct tlvdb *tlvdbelm, bool saveName, bool saveValue, bool saveAppDataLink);

int JsonSaveTLVTree(json_t *root, json_t *elm, const char *path, struct tlvdb *tlvdbelm);

int JsonLoadStr(json_t *root, const char *path, char *value);
int JsonLoadBufAsHex(json_t *elm, const char *path, uint8_t *data, size_t maxbufferlen, size_t *datalen);

bool ParamLoadFromJson(struct tlvdb *tlv);

#endif
