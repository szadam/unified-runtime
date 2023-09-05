#! /usr/bin/env python3
"""
 Copyright (C) 2023 Intel Corporation

 Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
 See LICENSE.TXT
 SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

"""

import sys
from argparse import ArgumentParser
import subprocess  # nosec B404
import signal
import re
import threading

def read_output(pipe, prefix):
    for line in pipe:
        print(prefix + line, end='')

if __name__ == '__main__':

    parser = ArgumentParser()
    parser.add_argument("--test_command", help="Ctest test case")

    args = parser.parse_args()
    result = subprocess.Popen([args.test_command, '--gtest_brief=1'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)  # nosec B603

    pat = re.compile(r'\[( )*FAILED( )*\]')

    # Create threads to read and print stdout and stderr concurrently
    stdout_thread = threading.Thread(target=read_output, args=(result.stdout, "Standard Output: "))
    stderr_thread = threading.Thread(target=read_output, args=(result.stderr, "Standard Error: "))

    stdout_thread.start()
    stderr_thread.start()

    stdout_thread.join()
    stderr_thread.join()

    rc = result.wait()

    if rc < 0:
        print(signal.strsignal(abs(rc)))