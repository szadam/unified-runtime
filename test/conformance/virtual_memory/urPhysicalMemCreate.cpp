// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <uur/fixtures.h>

struct urPhysicalMemCreateTest
    : uur::urVirtualMemGranularityTestWithParam<size_t> {

    void SetUp() override {
        UUR_RETURN_ON_FATAL_FAILURE(
            uur::urVirtualMemGranularityTestWithParam<size_t>::SetUp());
        size = getParam() * granularity;
    }

    size_t size;
};

UUR_TEST_SUITE_P(urPhysicalMemCreateTest,
                 ::testing::Values(1, 2, 3, 7, 12, 44, 1024, 4000, 12345),
                 uur::deviceTestWithParamPrinter<size_t>);

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

TEST_P(urPhysicalMemCreateTest, InvalidSize) {
    if (granularity == 1) {
        GTEST_SKIP()
            << "A granularity of 1 means that any size will be accepted.";
    }
    ur_physical_mem_handle_t physical_mem = nullptr;
    size_t invalid_size = size - 1;
    ASSERT_EQ_RESULT(urPhysicalMemCreate(context, device, invalid_size, nullptr,
                                         &physical_mem),
                     UR_RESULT_ERROR_INVALID_SIZE);
}
