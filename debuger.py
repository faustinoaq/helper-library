#!/usr/bin/env python3
# coding=utf-8

import re
from os import system, sys


class Debuger():

    def __init__(self, File):
        self.file = File
        self.buffer = ""
        self.debug = ("_{0}".format(self.file)).split(".")

    def read(self):
        try:
            with open(self.file, "r") as file:
                self.buffer = file.read()
                # print(self.buffer)
        except:
            print("\n\t{0} not found\n".format(self.file))
            exit(1)
        # Include dev Library
        dev = "#include <time.h>\n#include <stdlib.h>\n#include \"lib/debug.h\"\n#include"
        self.buffer = re.subn("#include", dev, self.buffer, 1)[0]
        # Add srand
        srand = "main(int argc, char const *argv[]){\n\tsrand(time(NULL));"
        remain = r"main(\s+)?\((\s+)?(int(\s+)?\w+(\s+)?,(\s+)?\w+(\s+)?\w+(\s+)?\*(\s+)?\w+(\s+)?\[(\s+)?\])?(\s+)?\)(\s+)?\{"
        self.buffer = re.sub(remain, srand, self.buffer)

    def debuger(self):
        integer = r"scanf(\s+)?\((\s+)?\"%i\"(\s+)?,"
        digit = r"scanf(\s+)?\((\s+)?\"%d\"(\s+)?,"
        float = r"scanf(\s+)?\((\s+)?\"%f\"(\s+)?,"
        string = r"scanf(\s+)?\((\s+)?\"%s\"(\s+)?,"
        fgets = r"fgets(\s+)?\((\s+)?"
        f_stdin = r",(\s+)?\d+(\s+)?,(\s+)?stdin"
        i_debug = "debug_int("
        f_debug = "debug_float("
        s_debug = "debug_str("
        self.buffer = re.sub(integer, i_debug, self.buffer)
        self.buffer = re.sub(digit, i_debug, self.buffer)
        self.buffer = re.sub(float, f_debug, self.buffer)
        self.buffer = re.sub(string, s_debug, self.buffer)
        self.buffer = re.sub(fgets, s_debug, self.buffer)
        self.buffer = re.sub(f_stdin, "", self.buffer)
        # print(self.buffer)
        with open(self.debug[0] + ".c", "w") as file:
            file.write(self.buffer)
            file.close()

    def compile(self):
        if sys.platform == "win32":
            system("set PATH=%PATH%;%programfiles% (x86)\Dev-Cpp\MinGW64\bin")
            system("gcc -std=c99 {0}.c -o {0}.exe && {0}.exe".format(self.debug[0]))
            try:
                if sys.argv[2]:
                    pass
            except:
                system("erase {0}*".format(self.debug[0]))
        elif sys.platform == "linux" or sys.platform == "linux2":
            system("gcc -ggdb -std=c99 {0}.c -o {0}.exe && ./{0}.exe".format(self.debug[0]))
            try:
                if sys.argv[2]:
                    pass
            except:
                system("rm {0}*".format(self.debug[0]))
        else:
            print("\n\tOS platform could not be detected\n")

    def run(self):
        self.read()
        self.debuger()
        self.compile()


if len(sys.argv) > 1:
    exe = Debuger(sys.argv[1])
    exe.run()
else:
    print("\n\tHelp:\n\tpython debuger.py \"source.c\"\n")
