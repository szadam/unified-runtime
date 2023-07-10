// Copyright (C) 2022-2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "fixtures.h"

struct urPlatformGetLastErrorTest : uur::platform::urPlatformTest {
    int32_t error;
    const char *message = nullptr;
};

TEST_F(urPlatformGetLastErrorTest, Success) {
    // We can't reliably generate a UR_RESULT_ERROR_ADAPTER_SPECIFIC error to
    // test the full functionality of this entry point, so instead do a minimal
    // smoke test and check that the call returns successfully, even if no
    // actual error was set.
    ASSERT_EQ_RESULT(UR_RESULT_SUCCESS,
                     urPlatformGetLastError(platform, &message, &error));
}

TEST_F(urPlatformGetLastErrorTest, InvalidHandle) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_HANDLE,
                     urPlatformGetLastError(nullptr, &message, &error));
}

TEST_F(urPlatformGetLastErrorTest, InvalidMessagePtr) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_POINTER,
                     urPlatformGetLastError(platform, nullptr, &error));
}

TEST_F(urPlatformGetLastErrorTest, InvalidErrorPtr) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_POINTER,
                     urPlatformGetLastError(platform, &message, nullptr));
}
