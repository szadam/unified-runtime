#! /bin/bash

# SPDX-FileCopyrightText: Intel Corporation
#
# SPDX-License-Identifier: BSD-3-Clause

workspace=$1
compiler_c=$2
compiler_cxx=$3
build_type=$4
adapter=$5

set -e
hostname

# SLURM/MPI integration is broken
unset SLURM_TASKS_PER_NODE
unset SLURM_JOBID

source /opt/intel/oneapi/setvars.sh
source ${workspace}/dpcpp_compiler/startup.sh
export PATH=${workspace}/dpcpp_compiler/bin:$PATH
export CPATH=${workspace}/dpcpp_compiler/include:$CPATH
export LIBRARY_PATH=${workspace}/dpcpp_compiler/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=${workspace}/dpcpp_compiler/lib:$LD_LIBRARY_PATH

cmake \
-B${workspace}/build \
-DCMAKE_C_COMPILER=${compiler_c} \
-DCMAKE_CXX_COMPILER=${compiler_cxx} \
-DUR_ENABLE_TRACING=ON \
-DUR_DEVELOPER_MODE=OFF \
-DCMAKE_BUILD_TYPE=${build_type} \
-DUR_BUILD_TESTS=ON \
-DUR_FORMAT_CPP_STYLE=OFF \
-DUR_BUILD_ADAPTER_${adapter}=ON \

cmake --build ${workspace}/build -j $(nproc)

# Temporarily disabling platform test for L0, because of hang
# See issue: #824
cd ${workspace}/build
ctest -C ${build_type} --output-on-failure -L "conformance" -E "platform-adapter_level_zero" --timeout 180
