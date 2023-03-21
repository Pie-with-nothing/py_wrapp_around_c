import ctypes
from numpy.ctypeslib import ndpointer
import numpy as np
import time
import matplotlib.pyplot as plt
import sys
from pathlib import Path

path_to_dir = Path(sys.argv[0]).parent
print(str(Path(path_to_dir) / 'testlib.so'))
testlib = ctypes.CDLL(str(Path(path_to_dir) / 'testlib.so'))
photo_size = [1024, 1280]

start = time.time()
'''
testlib.myprint()

q = testlib.simple_function()
print(q)

print(testlib.create_and_summ(23))

right = testlib.summ_of_rights
right.argtypes = [ctypes.c_longlong]
right.restype = ctypes.c_longlong

print(right('1'))

#print(ctypes.c_longlong(562949953421312))
'''
'''
get_num_array = testlib.text_to_arr
get_num_array.argtypes = [ctypes.c_char_p, ctypes.c_long]
get_num_array.restype = ctypes.POINTER(ctypes.c_int * 3 * photo_size[0] * photo_size[1])
num_array = get_num_array("C:/Users/Ivan/Desktop/qwas.txt".encode(), 2)

q = np.ctypeslib.as_array(num_array, shape=(1,))

clear = testlib.clear_arr
clear.argtypes = [ctypes.POINTER(ctypes.c_int * 3 * photo_size[0] * photo_size[1])]
clear(num_array)
'''
get_full_arr = testlib.change_arr
get_full_arr.argtypes = [ctypes.c_char_p, ndpointer(dtype=np.int32, ndim=1, flags="C_CONTIGUOUS")]
get_full_arr.restype = None

num_arr = np.empty(3 * photo_size[0] * photo_size[1], dtype=np.int32)
get_full_arr(str(Path(path_to_dir) / '0.txt').encode(), num_arr)
num_arr.resize(*photo_size, 3)



print(time.time() - start)

plt.imshow(np.flip(num_arr, 2))
plt.show()