# Shows how it is possible to call a C++ compiled function
# through python

from ctypes import CDLL, c_char_p

handle = CDLL("./main.so")
password = c_char_p(b"password")
password2 = c_char_p(b"Incorrect password")

handle.main(password)
handle.main(password2)
