// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <uur/fixtures.h>

struct urUSMDeviceAllocTest : uur::urQueueTestWithParam<uur::BoolTestParam> {
    void SetUp() override {
        UUR_RETURN_ON_FATAL_FAILURE(
            uur::urQueueTestWithParam<uur::BoolTestParam>::SetUp());
        ur_device_usm_access_capability_flags_t deviceUSMSupport = 0;
        ASSERT_SUCCESS(
            uur::GetDeviceUSMDeviceSupport(device, deviceUSMSupport));
        if (!deviceUSMSupport) {
            GTEST_SKIP() << "Device USM is not supported.";
        }

        if (getParam().value) {
            ur_usm_pool_desc_t pool_desc = {};
            ASSERT_SUCCESS(urUSMPoolCreate(context, &pool_desc, &pool));
        }
    }

    void TearDown() override {
        if (pool) {
            ASSERT_SUCCESS(urUSMPoolRelease(pool));
        }
        UUR_RETURN_ON_FATAL_FAILURE(
            uur::urQueueTestWithParam<uur::BoolTestParam>::TearDown());
    }

    ur_usm_pool_handle_t pool = nullptr;
};

UUR_TEST_SUITE_P(
    urUSMDeviceAllocTest,
    testing::ValuesIn(uur::BoolTestParam::makeBoolParam("UsePool")),
    uur::deviceTestWithParamPrinter<uur::BoolTestParam>);

TEST_P(urUSMDeviceAllocTest, Success) {
    void *ptr = nullptr;
    size_t allocation_size = sizeof(int);
    ASSERT_SUCCESS(urUSMDeviceAlloc(context, device, nullptr, pool,
                                    allocation_size, &ptr));
    ASSERT_NE(ptr, nullptr);

    ur_event_handle_t event = nullptr;
    uint8_t pattern = 0;
    ASSERT_SUCCESS(urEnqueueUSMFill(queue, ptr, sizeof(pattern), &pattern,
                                    allocation_size, 0, nullptr, &event));
    EXPECT_SUCCESS(urQueueFlush(queue));
    ASSERT_SUCCESS(urEventWait(1, &event));

    ASSERT_SUCCESS(urUSMFree(context, ptr));
    EXPECT_SUCCESS(urEventRelease(event));
}

TEST_P(urUSMDeviceAllocTest, SuccessWithDescriptors) {

    ur_usm_device_desc_t usm_device_desc{UR_STRUCTURE_TYPE_USM_DEVICE_DESC,
                                         nullptr,
                                         /* device flags */ 0};

    ur_usm_desc_t usm_desc{UR_STRUCTURE_TYPE_USM_DESC, &usm_device_desc,
                           /* mem advice flags */ UR_USM_ADVICE_FLAG_DEFAULT,
                           /* alignment */ 0};
    void *ptr = nullptr;
    size_t allocation_size = sizeof(int);
    ASSERT_SUCCESS(urUSMDeviceAlloc(context, device, &usm_desc, pool,
                                    allocation_size, &ptr));

    ur_event_handle_t event = nullptr;
    uint8_t pattern = 0;
    ASSERT_SUCCESS(urEnqueueUSMFill(queue, ptr, sizeof(pattern), &pattern,
                                    allocation_size, 0, nullptr, &event));
    ASSERT_SUCCESS(urEventWait(1, &event));

    ASSERT_SUCCESS(urUSMFree(context, ptr));
    EXPECT_SUCCESS(urEventRelease(event));
}

TEST_P(urUSMDeviceAllocTest, InvalidNullHandleContext) {
    void *ptr = nullptr;
    ASSERT_EQ_RESULT(
        UR_RESULT_ERROR_INVALID_NULL_HANDLE,
        urUSMDeviceAlloc(nullptr, device, nullptr, pool, sizeof(int), &ptr));
}

TEST_P(urUSMDeviceAllocTest, InvalidNullHandleDevice) {
    void *ptr = nullptr;
    ASSERT_EQ_RESULT(
        UR_RESULT_ERROR_INVALID_NULL_HANDLE,
        urUSMDeviceAlloc(context, nullptr, nullptr, pool, sizeof(int), &ptr));
}

TEST_P(urUSMDeviceAllocTest, InvalidNullPtrResult) {
    ASSERT_EQ_RESULT(
        UR_RESULT_ERROR_INVALID_NULL_POINTER,
        urUSMDeviceAlloc(context, device, nullptr, pool, sizeof(int), nullptr));
}

TEST_P(urUSMDeviceAllocTest, InvalidUSMSize) {
    void *ptr = nullptr;
    ASSERT_EQ_RESULT(
        UR_RESULT_ERROR_INVALID_USM_SIZE,
        urUSMDeviceAlloc(context, device, nullptr, pool, -1, &ptr));
}

TEST_P(urUSMDeviceAllocTest, InvalidValueAlignPowerOfTwo) {
    void *ptr = nullptr;
    ur_usm_desc_t desc = {};
    desc.stype = UR_STRUCTURE_TYPE_USM_DESC;
    desc.align = 5;
    ASSERT_EQ_RESULT(
        UR_RESULT_ERROR_INVALID_VALUE,
        urUSMDeviceAlloc(context, device, &desc, pool, sizeof(int), &ptr));
}
