# Shows how it is possible to call a C++ compiled function
# through python

import ctypes
import time
import os

# Links external library
handle = ctypes.CDLL("./main.so")

# Creates an array of pointers of type c_char_p
# "main" is a symbolic argument. I can call main()
# with any arguments I choose here. this just makes
# is so that main.cpp can have a normal set of argv
argsmaker = ctypes.c_char_p * 3 
args = argsmaker(b"main", b"password", b"wrong_password")

# Checks if inputs are correct and calls function
handle.main.argtypes = [ctypes.c_int, argsmaker]

# DLL case
start = time.time()
handle.main(3, args)
end = time.time()
first = end - start 
print("DLL call time: " + str(first) + "\n")

# Calling the OS to run the same program
start = time.time()
os.system("./main password wrong_password")
end = time.time()
second = end - start
print("OS call time: " + str(second) + "\n")

# Check speed
print("How many times is DLL faster?: " + str(second/first))
