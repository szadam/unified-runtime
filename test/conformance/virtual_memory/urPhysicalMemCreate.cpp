// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <uur/fixtures.h>

using urPhysicalMemCreateTestParams = size_t;
struct urPhysicalMemCreateTest
    : uur::urContextTestWithParam<urPhysicalMemCreateTestParams> {

    void SetUp() {
        UUR_RETURN_ON_FATAL_FAILURE(uur::urContextTestWithParam<
                                    urPhysicalMemCreateTestParams>::SetUp());
        ASSERT_SUCCESS(urVirtualMemGranularityGetInfo(
            context, device, UR_VIRTUAL_MEM_GRANULARITY_INFO_MINIMUM,
            sizeof(granularity), &granularity, nullptr));
        ASSERT_NE(granularity, 0);
        size = getParam() * granularity;
    }

    size_t granularity;
    size_t size;
};

UUR_TEST_SUITE_P(
    urPhysicalMemCreateTest,
    ::testing::Values(1, 2, 3, 7, 12, 44, 1024, 4000, 12345),
    uur::deviceTestWithParamPrinter<urPhysicalMemCreateTestParams>);

TEST_P(urPhysicalMemCreateTest, Success) {
    ur_physical_mem_handle_t physical_mem = nullptr;
    ASSERT_SUCCESS(
        urPhysicalMemCreate(context, device, size, nullptr, &physical_mem));
    ASSERT_NE(physical_mem, nullptr);
    EXPECT_SUCCESS(urPhysicalMemRelease(physical_mem));
}

TEST_P(urPhysicalMemCreateTest, InvalidNullHandleContext) {
    ur_physical_mem_handle_t physical_mem = nullptr;
    ASSERT_EQ_RESULT(
        urPhysicalMemCreate(nullptr, device, size, nullptr, &physical_mem),
        UR_RESULT_ERROR_INVALID_NULL_HANDLE);
}

TEST_P(urPhysicalMemCreateTest, InvalidNullHandleDevice) {
    ur_physical_mem_handle_t physical_mem = nullptr;
    ASSERT_EQ_RESULT(
        urPhysicalMemCreate(context, nullptr, size, nullptr, &physical_mem),
        UR_RESULT_ERROR_INVALID_NULL_HANDLE);
}

TEST_P(urPhysicalMemCreateTest, InvalidNullPointerPhysicalMem) {
    ASSERT_EQ_RESULT(
        urPhysicalMemCreate(context, device, size, nullptr, nullptr),
        UR_RESULT_ERROR_INVALID_NULL_POINTER);
}
