#!/usr/bin/python3
# Import module to get the pseudorandom numbers to be used
from os import mkdir as _dir
from os import path as _p
from random import randint as _int
from random import randrange as _range
from sys import argv as args

"""
The range should be from 1 to 20
This is to avoid zero as a space lines and
	no make it difficult to break the prime factors

Usage:
	The default test to be written is the factorials file
	Only one file is written by default
	If you want to change to write for rsa, then explicitly specify
	The number of files written at a time can be change by specifying
	the third argument.
	If you twist them around, then the defaults are used

The maximum writeable file(s) are 1000
"""


def rsa_func():
    """Generate numbers for rsa challenge"""
    num = ""
    for _ in range(1, _range(1, 20)):
        num += str(_int(1, 9))
    return num


def file_exists(filename):
    """Check if a file is present or not

    :param filename:

    """
    if _p.exists(filename):
        return False
    else:
        return True


def factors_func():
    """Generate numbers for factors challenge"""
    num = ""
    for _ in range(1, _range(1, 20)):
        for __ in range(1, _range(1, 30)):
            num += str(_int(1, 9))
        num += "\n"

    return num


def write_to_file(content, name: str):
    """Write content to a file

    This function writes the output to a random file
    Incase you want better results, feel free to change

    :param content:
    :param name: str:

    """
    name += str(_int(1, 10000))
    while file_exists(name):
        with open(name, "w") as file_t:
            file_t.write(content)


if __name__ == "__main__":
    """Check what random results are to be used

    By default it generates the factors test files(s)
    """
    try:
        type = args[1]
    except (IndexError, TypeError, ValueError):
        type = "factors"

    try:
        files_c = int(args[2])
    except (IndexError, TypeError, ValueError):
        files_c = 1

    if file_exists("tests"):
        _dir("tests")

    for _ in range(0, files_c):
        if type == "rsa":
            value = rsa_func()
            write_to_file(value, "tests/rsa-")
        else:
            value = factors_func()
            write_to_file(value, "tests/factorial-")
