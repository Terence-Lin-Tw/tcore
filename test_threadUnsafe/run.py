#!/usr/bin/python3

import ctypes, random as r, threading as thr
tclib = ctypes.CDLL('bin/tclib.so')

def _Increase(LoopNo):
    for i in range(0, LoopNo):
        tclib.increase()

def _MultiThread(ThreadNo, LoopNo):
    threads = [thr.Thread(target=_Increase, args=[LoopNo]) for x in range(0, ThreadNo)]
    for thread in threads: thread.start()
    for thread in threads: thread.join()

    print('Expect {}x{}, get {}'.format(ThreadNo, LoopNo, tclib.get_result()))

    return (ThreadNo*LoopNo) == tclib.get_result()

def main():
    thrNo, loopNo = 1, 1
    while(  _MultiThread(thrNo, loopNo)  ):
        tclib.reset()
        (thrNo, loopNo) = (thrNo*10, loopNo) if r.random() < 0.5 else (thrNo, loopNo*10)

    print('Thread was unsafe with {} thread(s) and {} loops'.format(thrNo, loopNo))

if __name__ == '__main__':
    main()
