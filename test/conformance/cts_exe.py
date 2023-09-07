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

if __name__ == '__main__':

    parser = ArgumentParser()
    parser.add_argument("--test_command", help="Ctest test case")

    args = parser.parse_args()

    output_file_stderr = open("output_stderr.txt", "w")
    output_file_stdout = open("output_stdout.txt", "w")

    #result = subprocess.Popen([args.test_command, '--gtest_brief=1'], stdout=subprocess.PIPE, text=True)  # nosec B603
    result1 = subprocess.Popen([args.test_command, '--gtest_brief=1'], stdout=output_file_stdout, stderr=output_file_stderr, text=True)  # nosec B603

    pat = re.compile(r'\[( )*FAILED( )*\]')

    #for line in result.stdout:
    #    if pat.search(line):
    #        test_case = line.split(" ")[5]
    #        test_case = test_case.rstrip(',')
    #        print(test_case)

    rc = result1.wait()
    #result1.wait()
    output_file_stderr.close()
    output_file_stdout.close()

    if rc < 0:
        print(signal.strsignal(abs(rc)))

    with open("output.txt", "r") as output_file:
            for line in output_file:
                sys.stdout.write(line)