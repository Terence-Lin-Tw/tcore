#!/usr/bin/python3

import ctypes

tclib = ctypes.CDLL('bin/tclib.so')

# # t = 'hello?'
# # s = ctypes.c_char_p(  bytes(t, encoding='utf-8')  )
# # r = tclib.str(s)
# # print(r)

# tclib.func(2)
# tclib.func(4)
# tclib.func(9)



from threading import Thread
from time import sleep

def increase():
    for i in range(0, 20000):
        tclib.increase()

threads = []
for i in range(0, 400):
    threads.append(Thread(target=increase))
for thread in threads:
    thread.start()
for thread in threads:
    thread.join()

print(f'Final counter: {tclib.get_result()}')
