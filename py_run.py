#!/usr/bin/python3

import sys, ctypes

import random
random.seed(1)

COMM_ENC = 'ascii'

CLEAR_BUFFER = True
mBuffer = []

def _InitTcLib():
    import os.path

    LIB_NAME = 'bin/tclib.so'
    if not os.path.isfile(LIB_NAME):
        LIB_NAME = '/home/bit/tcore/' + LIB_NAME

    tcLib = ctypes.CDLL('/home/bit/tcore/bin/tclib.so')
    tcLib.get.restype = ctypes.c_char_p

    return tcLib

def _ToCStr(S):
    cStr = ctypes.c_char_p(  bytes(S, COMM_ENC)  )
    mBuffer.append(cStr)

    return cStr

def _ToPyStr(S):
    return S.decode(COMM_ENC)

def _Set(TcLib, K, V):
    TcLib.set(  _ToCStr(K), _ToCStr(V)  )

def _Get(TcLib, K):
    kBytes = _ToCStr(K)
    v = TcLib.get(kBytes)

    return _ToPyStr(v)

def _CheckPairs(TcLib, D):
    l = list(D.keys())
    for k in l:
        pyValue = D[k]
        cValue = _Get(TcLib, k)
        if pyValue != cValue: return False

    return True

def main():
    tcLib = _InitTcLib()

    from py_generateKeyValuePairs import _GenerateKeyValuePairs
    d = _GenerateKeyValuePairs(1000000)
    for k in d:
        _Set(tcLib, k, d[k])

    for _ in range(10):
        check = _CheckPairs(tcLib, d)
        print('{}'.format('Equal' if check else 'Not equal'))

    # clear
    global mBuffer
    if CLEAR_BUFFER: mBuffer.clear()
    mBuffer = None
    del mBuffer

    import gc
    gc.collect()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)

    input()
