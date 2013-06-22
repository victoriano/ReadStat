//
//  stat.h
//  Wizard
//
//  Created by Evan Miller on 3/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef INCLUDE_READSTAT_H
#define INCLUDE_READSTAT_H

#include <stdint.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "readstat_bits.h"

typedef enum readstat_types_e {
    READSTAT_TYPE_STRING,
    READSTAT_TYPE_CHAR,
    READSTAT_TYPE_INT16,
    READSTAT_TYPE_INT32,
    READSTAT_TYPE_FLOAT,
    READSTAT_TYPE_DOUBLE,
    READSTAT_TYPE_LONG_STRING
} readstat_types_t;

typedef enum readstat_errors_e {
    READSTAT_ERROR_OPEN = 1,
    READSTAT_ERROR_READ,
    READSTAT_ERROR_MALLOC,
    READSTAT_ERROR_USER_ABORT,
    READSTAT_ERROR_PARSE
} readstat_errors_t;

typedef int (*readstat_handle_info_callback)(int obs_count, int var_count, void *ctx);
typedef int (*readstat_handle_variable_callback)(int index, const char *var_name, const char *var_format, 
        const char *var_label, const char *val_labels, readstat_types_t type, size_t max_len, void *ctx);
typedef int (*readstat_handle_value_callback)(int obs_index, int var_index, void *value, readstat_types_t type, void *ctx);
typedef int (*readstat_handle_value_label_callback)(const char *val_labels, void *value, readstat_types_t type, const char *label, void *ctx);

#endif
