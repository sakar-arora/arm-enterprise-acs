/** @file
 * Copyright (c) 2018, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#include <val_interface.h>
#include <val_sdei_interface.h>

#define TEST_DESC "Verify ERROR CODE-INVALID_PARAMETERS           "
#define SDEI_UNKNOWN_EVENT 0x10000

static void test_entry(void) {

    struct sdei_event event;
    int32_t err;

    /* INVALID_PARAMETERS Testcase */
    event.event_num = SDEI_UNKNOWN_EVENT;
    event.is_bound_irq = FALSE;
    err = val_sdei_event_register(event.event_num, (uint64_t)asm_event_handler, NULL, 0, 0);
    if (err != SDEI_STATUS_INVALID) {
        val_print(ACS_LOG_ERR, "\n        Invalid parameters check failed");
        val_test_pe_set_status(val_pe_get_index(), SDEI_TEST_FAIL);
        return;
    }

    val_test_pe_set_status(val_pe_get_index(), SDEI_TEST_PASS);
    return;
}

SDEI_SET_TEST_DEPS(test_020_deps, TEST_001_ID, TEST_002_ID);
SDEI_PUBLISH_TEST(test_020, TEST_020_ID, TEST_DESC, test_020_deps, test_entry, FALSE);
