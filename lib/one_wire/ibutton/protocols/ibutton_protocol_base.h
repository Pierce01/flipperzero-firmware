#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <core/string.h>
#include <one_wire/one_wire_host.h>

typedef void iButtonProtocolData;

typedef enum {
    iButtonProtocolFeatureExtData = (1U << 0),
    iButtonProtocolFeatureWriteBlank = (1U << 1),
    iButtonProtocolFeatureWriteCopy = (1U << 2),
} iButtonProtocolFeature;

typedef bool (*iButtonProtocolReadFunc)(OneWireHost*, iButtonProtocolData*);
typedef void (*iButtonProtocolRenderDataFunc)(FuriString*, const iButtonProtocolData*);

typedef struct {
    const uint8_t family_code;
    const uint32_t features;
    const size_t data_size;
    const char* manufacturer;
    const char* name;

    iButtonProtocolReadFunc read;
    iButtonProtocolRenderDataFunc render_data;
    iButtonProtocolRenderDataFunc render_brief_data;
} iButtonProtocolBase;