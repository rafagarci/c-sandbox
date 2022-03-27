# Shows how it is possible to call a C++ compiled function
# through python

import ctypes

# Links external library
handle = ctypes.CDLL("./main.so")

# Creates an array of pointers of type c_char_p
argsmaker = ctypes.c_char_p * 2 
args = argsmaker(b"password", b"wrong_password")

# Checks if inputs are correct and calls function
handle.main.argtypes = [ctypes.c_int, argsmaker]
handle.main(2, args)
