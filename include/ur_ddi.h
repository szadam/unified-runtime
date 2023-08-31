/*
 *
 * Copyright (C) 2022 Intel Corporation
 *
 * Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
 * See LICENSE.TXT
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 * @file ur_ddi.h
 * @version v0.7-r0
 *
 */
#ifndef UR_DDI_H_INCLUDED
#define UR_DDI_H_INCLUDED
#if defined(__cplusplus)
#pragma once
#endif
#include "ur_api.h"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformGet
typedef ur_result_t(UR_APICALL *ur_pfnPlatformGet_t)(
    ur_adapter_handle_t *,
    uint32_t,
    uint32_t,
    ur_platform_handle_t *,
    uint32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnPlatformGetInfo_t)(
    ur_platform_handle_t,
    ur_platform_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnPlatformGetNativeHandle_t)(
    ur_platform_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnPlatformCreateWithNativeHandle_t)(
    ur_native_handle_t,
    const ur_platform_native_properties_t *,
    ur_platform_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformGetApiVersion
typedef ur_result_t(UR_APICALL *ur_pfnPlatformGetApiVersion_t)(
    ur_platform_handle_t,
    ur_api_version_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPlatformGetBackendOption
typedef ur_result_t(UR_APICALL *ur_pfnPlatformGetBackendOption_t)(
    ur_platform_handle_t,
    const char *,
    const char **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Platform functions pointers
typedef struct ur_platform_dditable_t {
    ur_pfnPlatformGet_t pfnGet;
    ur_pfnPlatformGetInfo_t pfnGetInfo;
    ur_pfnPlatformGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnPlatformCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnPlatformGetApiVersion_t pfnGetApiVersion;
    ur_pfnPlatformGetBackendOption_t pfnGetBackendOption;
} ur_platform_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Platform table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetPlatformProcAddrTable(
    ur_api_version_t version,         ///< [in] API version requested
    ur_platform_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetPlatformProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetPlatformProcAddrTable_t)(
    ur_api_version_t,
    ur_platform_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextCreate
typedef ur_result_t(UR_APICALL *ur_pfnContextCreate_t)(
    uint32_t,
    const ur_device_handle_t *,
    const ur_context_properties_t *,
    ur_context_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextRetain
typedef ur_result_t(UR_APICALL *ur_pfnContextRetain_t)(
    ur_context_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextRelease
typedef ur_result_t(UR_APICALL *ur_pfnContextRelease_t)(
    ur_context_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnContextGetInfo_t)(
    ur_context_handle_t,
    ur_context_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnContextGetNativeHandle_t)(
    ur_context_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnContextCreateWithNativeHandle_t)(
    ur_native_handle_t,
    uint32_t,
    const ur_device_handle_t *,
    const ur_context_native_properties_t *,
    ur_context_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urContextSetExtendedDeleter
typedef ur_result_t(UR_APICALL *ur_pfnContextSetExtendedDeleter_t)(
    ur_context_handle_t,
    ur_context_extended_deleter_t,
    void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Context functions pointers
typedef struct ur_context_dditable_t {
    ur_pfnContextCreate_t pfnCreate;
    ur_pfnContextRetain_t pfnRetain;
    ur_pfnContextRelease_t pfnRelease;
    ur_pfnContextGetInfo_t pfnGetInfo;
    ur_pfnContextGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnContextCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnContextSetExtendedDeleter_t pfnSetExtendedDeleter;
} ur_context_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Context table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetContextProcAddrTable(
    ur_api_version_t version,        ///< [in] API version requested
    ur_context_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetContextProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetContextProcAddrTable_t)(
    ur_api_version_t,
    ur_context_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnEventGetInfo_t)(
    ur_event_handle_t,
    ur_event_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventGetProfilingInfo
typedef ur_result_t(UR_APICALL *ur_pfnEventGetProfilingInfo_t)(
    ur_event_handle_t,
    ur_profiling_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventWait
typedef ur_result_t(UR_APICALL *ur_pfnEventWait_t)(
    uint32_t,
    const ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventRetain
typedef ur_result_t(UR_APICALL *ur_pfnEventRetain_t)(
    ur_event_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventRelease
typedef ur_result_t(UR_APICALL *ur_pfnEventRelease_t)(
    ur_event_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnEventGetNativeHandle_t)(
    ur_event_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnEventCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    const ur_event_native_properties_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEventSetCallback
typedef ur_result_t(UR_APICALL *ur_pfnEventSetCallback_t)(
    ur_event_handle_t,
    ur_execution_info_t,
    ur_event_callback_t,
    void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Event functions pointers
typedef struct ur_event_dditable_t {
    ur_pfnEventGetInfo_t pfnGetInfo;
    ur_pfnEventGetProfilingInfo_t pfnGetProfilingInfo;
    ur_pfnEventWait_t pfnWait;
    ur_pfnEventRetain_t pfnRetain;
    ur_pfnEventRelease_t pfnRelease;
    ur_pfnEventGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnEventCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnEventSetCallback_t pfnSetCallback;
} ur_event_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Event table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetEventProcAddrTable(
    ur_api_version_t version,      ///< [in] API version requested
    ur_event_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetEventProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetEventProcAddrTable_t)(
    ur_api_version_t,
    ur_event_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramCreateWithIL
typedef ur_result_t(UR_APICALL *ur_pfnProgramCreateWithIL_t)(
    ur_context_handle_t,
    const void *,
    size_t,
    const ur_program_properties_t *,
    ur_program_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramCreateWithBinary
typedef ur_result_t(UR_APICALL *ur_pfnProgramCreateWithBinary_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    size_t,
    const uint8_t *,
    const ur_program_properties_t *,
    ur_program_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramBuild
typedef ur_result_t(UR_APICALL *ur_pfnProgramBuild_t)(
    ur_context_handle_t,
    ur_program_handle_t,
    const char *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramCompile
typedef ur_result_t(UR_APICALL *ur_pfnProgramCompile_t)(
    ur_context_handle_t,
    ur_program_handle_t,
    const char *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramLink
typedef ur_result_t(UR_APICALL *ur_pfnProgramLink_t)(
    ur_context_handle_t,
    uint32_t,
    const ur_program_handle_t *,
    const char *,
    ur_program_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramRetain
typedef ur_result_t(UR_APICALL *ur_pfnProgramRetain_t)(
    ur_program_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramRelease
typedef ur_result_t(UR_APICALL *ur_pfnProgramRelease_t)(
    ur_program_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramGetFunctionPointer
typedef ur_result_t(UR_APICALL *ur_pfnProgramGetFunctionPointer_t)(
    ur_device_handle_t,
    ur_program_handle_t,
    const char *,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnProgramGetInfo_t)(
    ur_program_handle_t,
    ur_program_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramGetBuildInfo
typedef ur_result_t(UR_APICALL *ur_pfnProgramGetBuildInfo_t)(
    ur_program_handle_t,
    ur_device_handle_t,
    ur_program_build_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramSetSpecializationConstants
typedef ur_result_t(UR_APICALL *ur_pfnProgramSetSpecializationConstants_t)(
    ur_program_handle_t,
    uint32_t,
    const ur_specialization_constant_info_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnProgramGetNativeHandle_t)(
    ur_program_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urProgramCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnProgramCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    const ur_program_native_properties_t *,
    ur_program_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Program functions pointers
typedef struct ur_program_dditable_t {
    ur_pfnProgramCreateWithIL_t pfnCreateWithIL;
    ur_pfnProgramCreateWithBinary_t pfnCreateWithBinary;
    ur_pfnProgramBuild_t pfnBuild;
    ur_pfnProgramCompile_t pfnCompile;
    ur_pfnProgramLink_t pfnLink;
    ur_pfnProgramRetain_t pfnRetain;
    ur_pfnProgramRelease_t pfnRelease;
    ur_pfnProgramGetFunctionPointer_t pfnGetFunctionPointer;
    ur_pfnProgramGetInfo_t pfnGetInfo;
    ur_pfnProgramGetBuildInfo_t pfnGetBuildInfo;
    ur_pfnProgramSetSpecializationConstants_t pfnSetSpecializationConstants;
    ur_pfnProgramGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnProgramCreateWithNativeHandle_t pfnCreateWithNativeHandle;
} ur_program_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Program table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetProgramProcAddrTable(
    ur_api_version_t version,        ///< [in] API version requested
    ur_program_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetProgramProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetProgramProcAddrTable_t)(
    ur_api_version_t,
    ur_program_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelCreate
typedef ur_result_t(UR_APICALL *ur_pfnKernelCreate_t)(
    ur_program_handle_t,
    const char *,
    ur_kernel_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnKernelGetInfo_t)(
    ur_kernel_handle_t,
    ur_kernel_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelGetGroupInfo
typedef ur_result_t(UR_APICALL *ur_pfnKernelGetGroupInfo_t)(
    ur_kernel_handle_t,
    ur_device_handle_t,
    ur_kernel_group_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelGetSubGroupInfo
typedef ur_result_t(UR_APICALL *ur_pfnKernelGetSubGroupInfo_t)(
    ur_kernel_handle_t,
    ur_device_handle_t,
    ur_kernel_sub_group_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelRetain
typedef ur_result_t(UR_APICALL *ur_pfnKernelRetain_t)(
    ur_kernel_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelRelease
typedef ur_result_t(UR_APICALL *ur_pfnKernelRelease_t)(
    ur_kernel_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnKernelGetNativeHandle_t)(
    ur_kernel_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnKernelCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    ur_program_handle_t,
    const ur_kernel_native_properties_t *,
    ur_kernel_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetArgValue
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetArgValue_t)(
    ur_kernel_handle_t,
    uint32_t,
    size_t,
    const ur_kernel_arg_value_properties_t *,
    const void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetArgLocal
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetArgLocal_t)(
    ur_kernel_handle_t,
    uint32_t,
    size_t,
    const ur_kernel_arg_local_properties_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetArgPointer
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetArgPointer_t)(
    ur_kernel_handle_t,
    uint32_t,
    const ur_kernel_arg_pointer_properties_t *,
    const void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetExecInfo
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetExecInfo_t)(
    ur_kernel_handle_t,
    ur_kernel_exec_info_t,
    size_t,
    const ur_kernel_exec_info_properties_t *,
    const void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetArgSampler
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetArgSampler_t)(
    ur_kernel_handle_t,
    uint32_t,
    const ur_kernel_arg_sampler_properties_t *,
    ur_sampler_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetArgMemObj
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetArgMemObj_t)(
    ur_kernel_handle_t,
    uint32_t,
    const ur_kernel_arg_mem_obj_properties_t *,
    ur_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urKernelSetSpecializationConstants
typedef ur_result_t(UR_APICALL *ur_pfnKernelSetSpecializationConstants_t)(
    ur_kernel_handle_t,
    uint32_t,
    const ur_specialization_constant_info_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Kernel functions pointers
typedef struct ur_kernel_dditable_t {
    ur_pfnKernelCreate_t pfnCreate;
    ur_pfnKernelGetInfo_t pfnGetInfo;
    ur_pfnKernelGetGroupInfo_t pfnGetGroupInfo;
    ur_pfnKernelGetSubGroupInfo_t pfnGetSubGroupInfo;
    ur_pfnKernelRetain_t pfnRetain;
    ur_pfnKernelRelease_t pfnRelease;
    ur_pfnKernelGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnKernelCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnKernelSetArgValue_t pfnSetArgValue;
    ur_pfnKernelSetArgLocal_t pfnSetArgLocal;
    ur_pfnKernelSetArgPointer_t pfnSetArgPointer;
    ur_pfnKernelSetExecInfo_t pfnSetExecInfo;
    ur_pfnKernelSetArgSampler_t pfnSetArgSampler;
    ur_pfnKernelSetArgMemObj_t pfnSetArgMemObj;
    ur_pfnKernelSetSpecializationConstants_t pfnSetSpecializationConstants;
} ur_kernel_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Kernel table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetKernelProcAddrTable(
    ur_api_version_t version,       ///< [in] API version requested
    ur_kernel_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetKernelProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetKernelProcAddrTable_t)(
    ur_api_version_t,
    ur_kernel_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerCreate
typedef ur_result_t(UR_APICALL *ur_pfnSamplerCreate_t)(
    ur_context_handle_t,
    const ur_sampler_desc_t *,
    ur_sampler_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerRetain
typedef ur_result_t(UR_APICALL *ur_pfnSamplerRetain_t)(
    ur_sampler_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerRelease
typedef ur_result_t(UR_APICALL *ur_pfnSamplerRelease_t)(
    ur_sampler_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnSamplerGetInfo_t)(
    ur_sampler_handle_t,
    ur_sampler_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnSamplerGetNativeHandle_t)(
    ur_sampler_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urSamplerCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnSamplerCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    const ur_sampler_native_properties_t *,
    ur_sampler_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Sampler functions pointers
typedef struct ur_sampler_dditable_t {
    ur_pfnSamplerCreate_t pfnCreate;
    ur_pfnSamplerRetain_t pfnRetain;
    ur_pfnSamplerRelease_t pfnRelease;
    ur_pfnSamplerGetInfo_t pfnGetInfo;
    ur_pfnSamplerGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnSamplerCreateWithNativeHandle_t pfnCreateWithNativeHandle;
} ur_sampler_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Sampler table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetSamplerProcAddrTable(
    ur_api_version_t version,        ///< [in] API version requested
    ur_sampler_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetSamplerProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetSamplerProcAddrTable_t)(
    ur_api_version_t,
    ur_sampler_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemImageCreate
typedef ur_result_t(UR_APICALL *ur_pfnMemImageCreate_t)(
    ur_context_handle_t,
    ur_mem_flags_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    void *,
    ur_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemBufferCreate
typedef ur_result_t(UR_APICALL *ur_pfnMemBufferCreate_t)(
    ur_context_handle_t,
    ur_mem_flags_t,
    size_t,
    const ur_buffer_properties_t *,
    ur_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemRetain
typedef ur_result_t(UR_APICALL *ur_pfnMemRetain_t)(
    ur_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemRelease
typedef ur_result_t(UR_APICALL *ur_pfnMemRelease_t)(
    ur_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemBufferPartition
typedef ur_result_t(UR_APICALL *ur_pfnMemBufferPartition_t)(
    ur_mem_handle_t,
    ur_mem_flags_t,
    ur_buffer_create_type_t,
    const ur_buffer_region_t *,
    ur_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnMemGetNativeHandle_t)(
    ur_mem_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemBufferCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnMemBufferCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    const ur_mem_native_properties_t *,
    ur_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemImageCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnMemImageCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    const ur_mem_native_properties_t *,
    ur_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnMemGetInfo_t)(
    ur_mem_handle_t,
    ur_mem_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urMemImageGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnMemImageGetInfo_t)(
    ur_mem_handle_t,
    ur_image_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Mem functions pointers
typedef struct ur_mem_dditable_t {
    ur_pfnMemImageCreate_t pfnImageCreate;
    ur_pfnMemBufferCreate_t pfnBufferCreate;
    ur_pfnMemRetain_t pfnRetain;
    ur_pfnMemRelease_t pfnRelease;
    ur_pfnMemBufferPartition_t pfnBufferPartition;
    ur_pfnMemGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnMemBufferCreateWithNativeHandle_t pfnBufferCreateWithNativeHandle;
    ur_pfnMemImageCreateWithNativeHandle_t pfnImageCreateWithNativeHandle;
    ur_pfnMemGetInfo_t pfnGetInfo;
    ur_pfnMemImageGetInfo_t pfnImageGetInfo;
} ur_mem_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Mem table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetMemProcAddrTable(
    ur_api_version_t version,    ///< [in] API version requested
    ur_mem_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetMemProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetMemProcAddrTable_t)(
    ur_api_version_t,
    ur_mem_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPhysicalMemCreate
typedef ur_result_t(UR_APICALL *ur_pfnPhysicalMemCreate_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    size_t,
    const ur_physical_mem_properties_t *,
    ur_physical_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPhysicalMemRetain
typedef ur_result_t(UR_APICALL *ur_pfnPhysicalMemRetain_t)(
    ur_physical_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urPhysicalMemRelease
typedef ur_result_t(UR_APICALL *ur_pfnPhysicalMemRelease_t)(
    ur_physical_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of PhysicalMem functions pointers
typedef struct ur_physical_mem_dditable_t {
    ur_pfnPhysicalMemCreate_t pfnCreate;
    ur_pfnPhysicalMemRetain_t pfnRetain;
    ur_pfnPhysicalMemRelease_t pfnRelease;
} ur_physical_mem_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's PhysicalMem table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetPhysicalMemProcAddrTable(
    ur_api_version_t version,             ///< [in] API version requested
    ur_physical_mem_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetPhysicalMemProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetPhysicalMemProcAddrTable_t)(
    ur_api_version_t,
    ur_physical_mem_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueKernelLaunch
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueKernelLaunch_t)(
    ur_queue_handle_t,
    ur_kernel_handle_t,
    uint32_t,
    const size_t *,
    const size_t *,
    const size_t *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueEventsWait
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueEventsWait_t)(
    ur_queue_handle_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueEventsWaitWithBarrier
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueEventsWaitWithBarrier_t)(
    ur_queue_handle_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferRead
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferRead_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferWrite
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferWrite_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    size_t,
    size_t,
    const void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferReadRect
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferReadRect_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferWriteRect
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferWriteRect_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferCopy
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferCopy_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    ur_mem_handle_t,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferCopyRect
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferCopyRect_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    ur_mem_handle_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferFill
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferFill_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    const void *,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemImageRead
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemImageRead_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemImageWrite
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemImageWrite_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemImageCopy
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemImageCopy_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    ur_mem_handle_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemBufferMap
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemBufferMap_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    bool,
    ur_map_flags_t,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueMemUnmap
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueMemUnmap_t)(
    ur_queue_handle_t,
    ur_mem_handle_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMFill
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMFill_t)(
    ur_queue_handle_t,
    void *,
    size_t,
    const void *,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMMemcpy
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMMemcpy_t)(
    ur_queue_handle_t,
    bool,
    void *,
    const void *,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMPrefetch
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMPrefetch_t)(
    ur_queue_handle_t,
    const void *,
    size_t,
    ur_usm_migration_flags_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMAdvise
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMAdvise_t)(
    ur_queue_handle_t,
    const void *,
    size_t,
    ur_usm_advice_flags_t,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMFill2D
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMFill2D_t)(
    ur_queue_handle_t,
    void *,
    size_t,
    size_t,
    const void *,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueUSMMemcpy2D
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueUSMMemcpy2D_t)(
    ur_queue_handle_t,
    bool,
    void *,
    size_t,
    const void *,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueDeviceGlobalVariableWrite
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueDeviceGlobalVariableWrite_t)(
    ur_queue_handle_t,
    ur_program_handle_t,
    const char *,
    bool,
    size_t,
    size_t,
    const void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueDeviceGlobalVariableRead
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueDeviceGlobalVariableRead_t)(
    ur_queue_handle_t,
    ur_program_handle_t,
    const char *,
    bool,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueReadHostPipe
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueReadHostPipe_t)(
    ur_queue_handle_t,
    ur_program_handle_t,
    const char *,
    bool,
    void *,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urEnqueueWriteHostPipe
typedef ur_result_t(UR_APICALL *ur_pfnEnqueueWriteHostPipe_t)(
    ur_queue_handle_t,
    ur_program_handle_t,
    const char *,
    bool,
    void *,
    size_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Enqueue functions pointers
typedef struct ur_enqueue_dditable_t {
    ur_pfnEnqueueKernelLaunch_t pfnKernelLaunch;
    ur_pfnEnqueueEventsWait_t pfnEventsWait;
    ur_pfnEnqueueEventsWaitWithBarrier_t pfnEventsWaitWithBarrier;
    ur_pfnEnqueueMemBufferRead_t pfnMemBufferRead;
    ur_pfnEnqueueMemBufferWrite_t pfnMemBufferWrite;
    ur_pfnEnqueueMemBufferReadRect_t pfnMemBufferReadRect;
    ur_pfnEnqueueMemBufferWriteRect_t pfnMemBufferWriteRect;
    ur_pfnEnqueueMemBufferCopy_t pfnMemBufferCopy;
    ur_pfnEnqueueMemBufferCopyRect_t pfnMemBufferCopyRect;
    ur_pfnEnqueueMemBufferFill_t pfnMemBufferFill;
    ur_pfnEnqueueMemImageRead_t pfnMemImageRead;
    ur_pfnEnqueueMemImageWrite_t pfnMemImageWrite;
    ur_pfnEnqueueMemImageCopy_t pfnMemImageCopy;
    ur_pfnEnqueueMemBufferMap_t pfnMemBufferMap;
    ur_pfnEnqueueMemUnmap_t pfnMemUnmap;
    ur_pfnEnqueueUSMFill_t pfnUSMFill;
    ur_pfnEnqueueUSMMemcpy_t pfnUSMMemcpy;
    ur_pfnEnqueueUSMPrefetch_t pfnUSMPrefetch;
    ur_pfnEnqueueUSMAdvise_t pfnUSMAdvise;
    ur_pfnEnqueueUSMFill2D_t pfnUSMFill2D;
    ur_pfnEnqueueUSMMemcpy2D_t pfnUSMMemcpy2D;
    ur_pfnEnqueueDeviceGlobalVariableWrite_t pfnDeviceGlobalVariableWrite;
    ur_pfnEnqueueDeviceGlobalVariableRead_t pfnDeviceGlobalVariableRead;
    ur_pfnEnqueueReadHostPipe_t pfnReadHostPipe;
    ur_pfnEnqueueWriteHostPipe_t pfnWriteHostPipe;
} ur_enqueue_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Enqueue table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetEnqueueProcAddrTable(
    ur_api_version_t version,        ///< [in] API version requested
    ur_enqueue_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetEnqueueProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetEnqueueProcAddrTable_t)(
    ur_api_version_t,
    ur_enqueue_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnQueueGetInfo_t)(
    ur_queue_handle_t,
    ur_queue_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueCreate
typedef ur_result_t(UR_APICALL *ur_pfnQueueCreate_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_queue_properties_t *,
    ur_queue_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueRetain
typedef ur_result_t(UR_APICALL *ur_pfnQueueRetain_t)(
    ur_queue_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueRelease
typedef ur_result_t(UR_APICALL *ur_pfnQueueRelease_t)(
    ur_queue_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnQueueGetNativeHandle_t)(
    ur_queue_handle_t,
    ur_queue_native_desc_t *,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnQueueCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_queue_native_properties_t *,
    ur_queue_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueFinish
typedef ur_result_t(UR_APICALL *ur_pfnQueueFinish_t)(
    ur_queue_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urQueueFlush
typedef ur_result_t(UR_APICALL *ur_pfnQueueFlush_t)(
    ur_queue_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Queue functions pointers
typedef struct ur_queue_dditable_t {
    ur_pfnQueueGetInfo_t pfnGetInfo;
    ur_pfnQueueCreate_t pfnCreate;
    ur_pfnQueueRetain_t pfnRetain;
    ur_pfnQueueRelease_t pfnRelease;
    ur_pfnQueueGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnQueueCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnQueueFinish_t pfnFinish;
    ur_pfnQueueFlush_t pfnFlush;
} ur_queue_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Queue table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetQueueProcAddrTable(
    ur_api_version_t version,      ///< [in] API version requested
    ur_queue_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetQueueProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetQueueProcAddrTable_t)(
    ur_api_version_t,
    ur_queue_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesUnsampledImageHandleDestroyExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesUnsampledImageHandleDestroyExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesSampledImageHandleDestroyExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesSampledImageHandleDestroyExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImageAllocateExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImageAllocateExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    ur_exp_image_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImageFreeExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImageFreeExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesUnsampledImageCreateExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesUnsampledImageCreateExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_mem_handle_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    ur_mem_handle_t *,
    ur_exp_image_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesSampledImageCreateExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesSampledImageCreateExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_mem_handle_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    ur_sampler_handle_t,
    ur_mem_handle_t *,
    ur_exp_image_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImageCopyExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImageCopyExp_t)(
    ur_queue_handle_t,
    void *,
    void *,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    ur_exp_image_copy_flags_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    ur_rect_region_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImageGetInfoExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImageGetInfoExp_t)(
    ur_exp_image_mem_handle_t,
    ur_image_info_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesMipmapGetLevelExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesMipmapGetLevelExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_mem_handle_t,
    uint32_t,
    ur_exp_image_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesMipmapFreeExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesMipmapFreeExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_image_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImportOpaqueFDExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImportOpaqueFDExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    size_t,
    ur_exp_interop_mem_desc_t *,
    ur_exp_interop_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesMapExternalArrayExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesMapExternalArrayExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_image_format_t *,
    const ur_image_desc_t *,
    ur_exp_interop_mem_handle_t,
    ur_exp_image_mem_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesReleaseInteropExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesReleaseInteropExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_interop_mem_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesImportExternalSemaphoreOpaqueFDExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesImportExternalSemaphoreOpaqueFDExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_interop_semaphore_desc_t *,
    ur_exp_interop_semaphore_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesDestroyExternalSemaphoreExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesDestroyExternalSemaphoreExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_exp_interop_semaphore_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesWaitExternalSemaphoreExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesWaitExternalSemaphoreExp_t)(
    ur_queue_handle_t,
    ur_exp_interop_semaphore_handle_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urBindlessImagesSignalExternalSemaphoreExp
typedef ur_result_t(UR_APICALL *ur_pfnBindlessImagesSignalExternalSemaphoreExp_t)(
    ur_queue_handle_t,
    ur_exp_interop_semaphore_handle_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of BindlessImagesExp functions pointers
typedef struct ur_bindless_images_exp_dditable_t {
    ur_pfnBindlessImagesUnsampledImageHandleDestroyExp_t pfnUnsampledImageHandleDestroyExp;
    ur_pfnBindlessImagesSampledImageHandleDestroyExp_t pfnSampledImageHandleDestroyExp;
    ur_pfnBindlessImagesImageAllocateExp_t pfnImageAllocateExp;
    ur_pfnBindlessImagesImageFreeExp_t pfnImageFreeExp;
    ur_pfnBindlessImagesUnsampledImageCreateExp_t pfnUnsampledImageCreateExp;
    ur_pfnBindlessImagesSampledImageCreateExp_t pfnSampledImageCreateExp;
    ur_pfnBindlessImagesImageCopyExp_t pfnImageCopyExp;
    ur_pfnBindlessImagesImageGetInfoExp_t pfnImageGetInfoExp;
    ur_pfnBindlessImagesMipmapGetLevelExp_t pfnMipmapGetLevelExp;
    ur_pfnBindlessImagesMipmapFreeExp_t pfnMipmapFreeExp;
    ur_pfnBindlessImagesImportOpaqueFDExp_t pfnImportOpaqueFDExp;
    ur_pfnBindlessImagesMapExternalArrayExp_t pfnMapExternalArrayExp;
    ur_pfnBindlessImagesReleaseInteropExp_t pfnReleaseInteropExp;
    ur_pfnBindlessImagesImportExternalSemaphoreOpaqueFDExp_t pfnImportExternalSemaphoreOpaqueFDExp;
    ur_pfnBindlessImagesDestroyExternalSemaphoreExp_t pfnDestroyExternalSemaphoreExp;
    ur_pfnBindlessImagesWaitExternalSemaphoreExp_t pfnWaitExternalSemaphoreExp;
    ur_pfnBindlessImagesSignalExternalSemaphoreExp_t pfnSignalExternalSemaphoreExp;
} ur_bindless_images_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's BindlessImagesExp table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetBindlessImagesExpProcAddrTable(
    ur_api_version_t version,                    ///< [in] API version requested
    ur_bindless_images_exp_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetBindlessImagesExpProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetBindlessImagesExpProcAddrTable_t)(
    ur_api_version_t,
    ur_bindless_images_exp_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMHostAlloc
typedef ur_result_t(UR_APICALL *ur_pfnUSMHostAlloc_t)(
    ur_context_handle_t,
    const ur_usm_desc_t *,
    ur_usm_pool_handle_t,
    size_t,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMDeviceAlloc
typedef ur_result_t(UR_APICALL *ur_pfnUSMDeviceAlloc_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_usm_desc_t *,
    ur_usm_pool_handle_t,
    size_t,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMSharedAlloc
typedef ur_result_t(UR_APICALL *ur_pfnUSMSharedAlloc_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_usm_desc_t *,
    ur_usm_pool_handle_t,
    size_t,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMFree
typedef ur_result_t(UR_APICALL *ur_pfnUSMFree_t)(
    ur_context_handle_t,
    void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMGetMemAllocInfo
typedef ur_result_t(UR_APICALL *ur_pfnUSMGetMemAllocInfo_t)(
    ur_context_handle_t,
    const void *,
    ur_usm_alloc_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMPoolCreate
typedef ur_result_t(UR_APICALL *ur_pfnUSMPoolCreate_t)(
    ur_context_handle_t,
    ur_usm_pool_desc_t *,
    ur_usm_pool_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMPoolRetain
typedef ur_result_t(UR_APICALL *ur_pfnUSMPoolRetain_t)(
    ur_usm_pool_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMPoolRelease
typedef ur_result_t(UR_APICALL *ur_pfnUSMPoolRelease_t)(
    ur_usm_pool_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMPoolGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnUSMPoolGetInfo_t)(
    ur_usm_pool_handle_t,
    ur_usm_pool_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of USM functions pointers
typedef struct ur_usm_dditable_t {
    ur_pfnUSMHostAlloc_t pfnHostAlloc;
    ur_pfnUSMDeviceAlloc_t pfnDeviceAlloc;
    ur_pfnUSMSharedAlloc_t pfnSharedAlloc;
    ur_pfnUSMFree_t pfnFree;
    ur_pfnUSMGetMemAllocInfo_t pfnGetMemAllocInfo;
    ur_pfnUSMPoolCreate_t pfnPoolCreate;
    ur_pfnUSMPoolRetain_t pfnPoolRetain;
    ur_pfnUSMPoolRelease_t pfnPoolRelease;
    ur_pfnUSMPoolGetInfo_t pfnPoolGetInfo;
} ur_usm_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's USM table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetUSMProcAddrTable(
    ur_api_version_t version,    ///< [in] API version requested
    ur_usm_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetUSMProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetUSMProcAddrTable_t)(
    ur_api_version_t,
    ur_usm_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMPitchedAllocExp
typedef ur_result_t(UR_APICALL *ur_pfnUSMPitchedAllocExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_usm_desc_t *,
    ur_usm_pool_handle_t,
    size_t,
    size_t,
    size_t,
    void **,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMImportExp
typedef ur_result_t(UR_APICALL *ur_pfnUSMImportExp_t)(
    ur_context_handle_t,
    void *,
    size_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUSMReleaseExp
typedef ur_result_t(UR_APICALL *ur_pfnUSMReleaseExp_t)(
    ur_context_handle_t,
    void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of USMExp functions pointers
typedef struct ur_usm_exp_dditable_t {
    ur_pfnUSMPitchedAllocExp_t pfnPitchedAllocExp;
    ur_pfnUSMImportExp_t pfnImportExp;
    ur_pfnUSMReleaseExp_t pfnReleaseExp;
} ur_usm_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's USMExp table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetUSMExpProcAddrTable(
    ur_api_version_t version,        ///< [in] API version requested
    ur_usm_exp_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetUSMExpProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetUSMExpProcAddrTable_t)(
    ur_api_version_t,
    ur_usm_exp_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferCreateExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferCreateExp_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    const ur_exp_command_buffer_desc_t *,
    ur_exp_command_buffer_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferRetainExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferRetainExp_t)(
    ur_exp_command_buffer_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferReleaseExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferReleaseExp_t)(
    ur_exp_command_buffer_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferFinalizeExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferFinalizeExp_t)(
    ur_exp_command_buffer_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendKernelLaunchExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendKernelLaunchExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_kernel_handle_t,
    uint32_t,
    const size_t *,
    const size_t *,
    const size_t *,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMemcpyUSMExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMemcpyUSMExp_t)(
    ur_exp_command_buffer_handle_t,
    void *,
    const void *,
    size_t,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferCopyExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferCopyExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    ur_mem_handle_t,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferWriteExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferWriteExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    size_t,
    size_t,
    const void *,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferReadExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferReadExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferCopyRectExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferCopyRectExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    ur_mem_handle_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferWriteRectExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferWriteRectExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferAppendMembufferReadRectExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferAppendMembufferReadRectExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_mem_handle_t,
    ur_rect_offset_t,
    ur_rect_offset_t,
    ur_rect_region_t,
    size_t,
    size_t,
    size_t,
    size_t,
    void *,
    uint32_t,
    const ur_exp_command_buffer_sync_point_t *,
    ur_exp_command_buffer_sync_point_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urCommandBufferEnqueueExp
typedef ur_result_t(UR_APICALL *ur_pfnCommandBufferEnqueueExp_t)(
    ur_exp_command_buffer_handle_t,
    ur_queue_handle_t,
    uint32_t,
    const ur_event_handle_t *,
    ur_event_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of CommandBufferExp functions pointers
typedef struct ur_command_buffer_exp_dditable_t {
    ur_pfnCommandBufferCreateExp_t pfnCreateExp;
    ur_pfnCommandBufferRetainExp_t pfnRetainExp;
    ur_pfnCommandBufferReleaseExp_t pfnReleaseExp;
    ur_pfnCommandBufferFinalizeExp_t pfnFinalizeExp;
    ur_pfnCommandBufferAppendKernelLaunchExp_t pfnAppendKernelLaunchExp;
    ur_pfnCommandBufferAppendMemcpyUSMExp_t pfnAppendMemcpyUSMExp;
    ur_pfnCommandBufferAppendMembufferCopyExp_t pfnAppendMembufferCopyExp;
    ur_pfnCommandBufferAppendMembufferWriteExp_t pfnAppendMembufferWriteExp;
    ur_pfnCommandBufferAppendMembufferReadExp_t pfnAppendMembufferReadExp;
    ur_pfnCommandBufferAppendMembufferCopyRectExp_t pfnAppendMembufferCopyRectExp;
    ur_pfnCommandBufferAppendMembufferWriteRectExp_t pfnAppendMembufferWriteRectExp;
    ur_pfnCommandBufferAppendMembufferReadRectExp_t pfnAppendMembufferReadRectExp;
    ur_pfnCommandBufferEnqueueExp_t pfnEnqueueExp;
} ur_command_buffer_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandBufferExp table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetCommandBufferExpProcAddrTable(
    ur_api_version_t version,                   ///< [in] API version requested
    ur_command_buffer_exp_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetCommandBufferExpProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetCommandBufferExpProcAddrTable_t)(
    ur_api_version_t,
    ur_command_buffer_exp_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUsmP2PEnablePeerAccessExp
typedef ur_result_t(UR_APICALL *ur_pfnUsmP2PEnablePeerAccessExp_t)(
    ur_device_handle_t,
    ur_device_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUsmP2PDisablePeerAccessExp
typedef ur_result_t(UR_APICALL *ur_pfnUsmP2PDisablePeerAccessExp_t)(
    ur_device_handle_t,
    ur_device_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urUsmP2PPeerAccessGetInfoExp
typedef ur_result_t(UR_APICALL *ur_pfnUsmP2PPeerAccessGetInfoExp_t)(
    ur_device_handle_t,
    ur_device_handle_t,
    ur_exp_peer_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of UsmP2PExp functions pointers
typedef struct ur_usm_p2p_exp_dditable_t {
    ur_pfnUsmP2PEnablePeerAccessExp_t pfnEnablePeerAccessExp;
    ur_pfnUsmP2PDisablePeerAccessExp_t pfnDisablePeerAccessExp;
    ur_pfnUsmP2PPeerAccessGetInfoExp_t pfnPeerAccessGetInfoExp;
} ur_usm_p2p_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's UsmP2PExp table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetUsmP2PExpProcAddrTable(
    ur_api_version_t version,            ///< [in] API version requested
    ur_usm_p2p_exp_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetUsmP2PExpProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetUsmP2PExpProcAddrTable_t)(
    ur_api_version_t,
    ur_usm_p2p_exp_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urInit
typedef ur_result_t(UR_APICALL *ur_pfnInit_t)(
    ur_device_init_flags_t,
    ur_loader_config_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urTearDown
typedef ur_result_t(UR_APICALL *ur_pfnTearDown_t)(
    void *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urAdapterGet
typedef ur_result_t(UR_APICALL *ur_pfnAdapterGet_t)(
    uint32_t,
    ur_adapter_handle_t *,
    uint32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urAdapterRelease
typedef ur_result_t(UR_APICALL *ur_pfnAdapterRelease_t)(
    ur_adapter_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urAdapterRetain
typedef ur_result_t(UR_APICALL *ur_pfnAdapterRetain_t)(
    ur_adapter_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urAdapterGetLastError
typedef ur_result_t(UR_APICALL *ur_pfnAdapterGetLastError_t)(
    ur_adapter_handle_t,
    const char **,
    int32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urAdapterGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnAdapterGetInfo_t)(
    ur_adapter_handle_t,
    ur_adapter_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Global functions pointers
typedef struct ur_global_dditable_t {
    ur_pfnInit_t pfnInit;
    ur_pfnTearDown_t pfnTearDown;
    ur_pfnAdapterGet_t pfnAdapterGet;
    ur_pfnAdapterRelease_t pfnAdapterRelease;
    ur_pfnAdapterRetain_t pfnAdapterRetain;
    ur_pfnAdapterGetLastError_t pfnAdapterGetLastError;
    ur_pfnAdapterGetInfo_t pfnAdapterGetInfo;
} ur_global_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Global table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetGlobalProcAddrTable(
    ur_api_version_t version,       ///< [in] API version requested
    ur_global_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetGlobalProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetGlobalProcAddrTable_t)(
    ur_api_version_t,
    ur_global_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemGranularityGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemGranularityGetInfo_t)(
    ur_context_handle_t,
    ur_device_handle_t,
    ur_virtual_mem_granularity_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemReserve
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemReserve_t)(
    ur_context_handle_t,
    const void *,
    size_t,
    void **);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemFree
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemFree_t)(
    ur_context_handle_t,
    const void *,
    size_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemMap
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemMap_t)(
    ur_context_handle_t,
    const void *,
    size_t,
    ur_physical_mem_handle_t,
    size_t,
    ur_virtual_mem_access_flags_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemUnmap
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemUnmap_t)(
    ur_context_handle_t,
    const void *,
    size_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemSetAccess
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemSetAccess_t)(
    ur_context_handle_t,
    const void *,
    size_t,
    ur_virtual_mem_access_flags_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urVirtualMemGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnVirtualMemGetInfo_t)(
    ur_context_handle_t,
    const void *,
    size_t,
    ur_virtual_mem_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of VirtualMem functions pointers
typedef struct ur_virtual_mem_dditable_t {
    ur_pfnVirtualMemGranularityGetInfo_t pfnGranularityGetInfo;
    ur_pfnVirtualMemReserve_t pfnReserve;
    ur_pfnVirtualMemFree_t pfnFree;
    ur_pfnVirtualMemMap_t pfnMap;
    ur_pfnVirtualMemUnmap_t pfnUnmap;
    ur_pfnVirtualMemSetAccess_t pfnSetAccess;
    ur_pfnVirtualMemGetInfo_t pfnGetInfo;
} ur_virtual_mem_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's VirtualMem table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetVirtualMemProcAddrTable(
    ur_api_version_t version,            ///< [in] API version requested
    ur_virtual_mem_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetVirtualMemProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetVirtualMemProcAddrTable_t)(
    ur_api_version_t,
    ur_virtual_mem_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceGet
typedef ur_result_t(UR_APICALL *ur_pfnDeviceGet_t)(
    ur_platform_handle_t,
    ur_device_type_t,
    uint32_t,
    ur_device_handle_t *,
    uint32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceGetInfo
typedef ur_result_t(UR_APICALL *ur_pfnDeviceGetInfo_t)(
    ur_device_handle_t,
    ur_device_info_t,
    size_t,
    void *,
    size_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceRetain
typedef ur_result_t(UR_APICALL *ur_pfnDeviceRetain_t)(
    ur_device_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceRelease
typedef ur_result_t(UR_APICALL *ur_pfnDeviceRelease_t)(
    ur_device_handle_t);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDevicePartition
typedef ur_result_t(UR_APICALL *ur_pfnDevicePartition_t)(
    ur_device_handle_t,
    const ur_device_partition_properties_t *,
    uint32_t,
    ur_device_handle_t *,
    uint32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceSelectBinary
typedef ur_result_t(UR_APICALL *ur_pfnDeviceSelectBinary_t)(
    ur_device_handle_t,
    const ur_device_binary_t *,
    uint32_t,
    uint32_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceGetNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnDeviceGetNativeHandle_t)(
    ur_device_handle_t,
    ur_native_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceCreateWithNativeHandle
typedef ur_result_t(UR_APICALL *ur_pfnDeviceCreateWithNativeHandle_t)(
    ur_native_handle_t,
    ur_platform_handle_t,
    const ur_device_native_properties_t *,
    ur_device_handle_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urDeviceGetGlobalTimestamps
typedef ur_result_t(UR_APICALL *ur_pfnDeviceGetGlobalTimestamps_t)(
    ur_device_handle_t,
    uint64_t *,
    uint64_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Device functions pointers
typedef struct ur_device_dditable_t {
    ur_pfnDeviceGet_t pfnGet;
    ur_pfnDeviceGetInfo_t pfnGetInfo;
    ur_pfnDeviceRetain_t pfnRetain;
    ur_pfnDeviceRelease_t pfnRelease;
    ur_pfnDevicePartition_t pfnPartition;
    ur_pfnDeviceSelectBinary_t pfnSelectBinary;
    ur_pfnDeviceGetNativeHandle_t pfnGetNativeHandle;
    ur_pfnDeviceCreateWithNativeHandle_t pfnCreateWithNativeHandle;
    ur_pfnDeviceGetGlobalTimestamps_t pfnGetGlobalTimestamps;
} ur_device_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::UR_RESULT_ERROR_UNSUPPORTED_VERSION
UR_DLLEXPORT ur_result_t UR_APICALL
urGetDeviceProcAddrTable(
    ur_api_version_t version,       ///< [in] API version requested
    ur_device_dditable_t *pDdiTable ///< [in,out] pointer to table of DDI function pointers
);

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for urGetDeviceProcAddrTable
typedef ur_result_t(UR_APICALL *ur_pfnGetDeviceProcAddrTable_t)(
    ur_api_version_t,
    ur_device_dditable_t *);

///////////////////////////////////////////////////////////////////////////////
/// @brief Container for all DDI tables
typedef struct ur_dditable_t {
    ur_platform_dditable_t Platform;
    ur_context_dditable_t Context;
    ur_event_dditable_t Event;
    ur_program_dditable_t Program;
    ur_kernel_dditable_t Kernel;
    ur_sampler_dditable_t Sampler;
    ur_mem_dditable_t Mem;
    ur_physical_mem_dditable_t PhysicalMem;
    ur_enqueue_dditable_t Enqueue;
    ur_queue_dditable_t Queue;
    ur_bindless_images_exp_dditable_t BindlessImagesExp;
    ur_usm_dditable_t USM;
    ur_usm_exp_dditable_t USMExp;
    ur_command_buffer_exp_dditable_t CommandBufferExp;
    ur_usm_p2p_exp_dditable_t UsmP2PExp;
    ur_global_dditable_t Global;
    ur_virtual_mem_dditable_t VirtualMem;
    ur_device_dditable_t Device;
} ur_dditable_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // UR_DDI_H_INCLUDED
