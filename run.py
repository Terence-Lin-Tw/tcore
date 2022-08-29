#!/usr/bin/python3

import sys, ctypes

COMM_ENC = 'ascii'

tclib = ctypes.CDLL('bin/tclib.so')
tclib.get.restype = ctypes.c_char_p

buf = []

def _ToCStr(S):
    cStr = ctypes.c_char_p(  bytes(S, COMM_ENC)  )
    buf.append(cStr)

    return cStr

def _ToPyStr(S):
    return S.decode(COMM_ENC)

def _Set(K, V):
    kBytes = _ToCStr(K)
    vBytes = _ToCStr(V)

    tclib.set(kBytes, vBytes)

def _Get(K):
    kBytes = _ToCStr(K)
    v = tclib.get(kBytes)

    return _ToPyStr(v)

def main():
    _Set('abc', '1234')
    res = _Get('abc')
    print(  '"{}"'.format(res)  )

    res = _Get('abc!')
    print(  '"{}"'.format(res)  )

    _Set('abc', '')
    res = _Get('abc')
    print(  '"{}"'.format(res)  )

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
