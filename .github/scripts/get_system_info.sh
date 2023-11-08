#!/usr/bin/env bash

#  Copyright (C) 2023 Intel Corporation
#  Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
#  See LICENSE.TXT
#  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

# get_system_info.sh - Script for printing system info

function system_info {
	echo "********** system_info **********"
	cat /etc/os-release | grep -oP "PRETTY_NAME=\K.*"
	cat /proc/version
	echo "**********SYCL-LS**********"
	source /opt/intel/oneapi/setvars.sh
	sycl-ls
	echo "**********VGA**********"
	lspci | grep VGA
	echo "**********CUDA Version**********"
	if command -v nvidia-smi &> /dev/null; then
		nvidia-smi
	else
		echo "CUDA not installed"
	fi
	echo "**********L0 Version**********"
	dpkg -l | grep level-zero
	echo "**********ROCm Version**********"
	if command -v rocminfo &> /dev/null; then
		rocminfo
	else
		echo "ROCm not installed"
	fi
	echo "**********/proc/cmdline**********"
	cat /proc/cmdline
	echo "**********CPU info**********"
	lscpu
	echo "**********/proc/meminfo**********"
	cat /proc/meminfo
	echo "**********build/bin/urinfo**********"
	$(dirname "$(readlink -f "$0")")/../../build/bin/urinfo || true
	echo "******OpenCL*******"
	# The driver version of OpenCL Graphics is the compute-runtime version
	clinfo
	echo "**********list-environment**********"
	echo "PATH=$PATH"
	echo
	echo "CPATH=$CPATH"
	echo
	echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"
	echo
	echo "LIBRARY_PATH=$LIBRARY_PATH"
	echo
	echo "PKG_CONFIG_PATH=$PKG_CONFIG_PATH"
	echo
	echo "******list-build-system-versions*******"
	gcc --version 2>/dev/null || true
	echo
	clang --version 2>/dev/null || true
	echo
	make --version 2>/dev/null || true
	echo "**********/proc/modules**********"
	cat /proc/modules
	echo "*************** installed-packages ***************"
	# Instructions below will return some minor errors, as they are dependent on the Linux distribution.
	zypper se --installed-only 2>/dev/null || true
	apt list --installed 2>/dev/null || true
	yum list installed 2>/dev/null || true
}

# Call the function above to print system info.
system_info
