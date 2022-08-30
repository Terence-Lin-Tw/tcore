#!/usr/bin/python3

import sys, ctypes

import random
random.seed(1)

COMM_ENC = 'ascii'

tclib = ctypes.CDLL('bin/tclib.so')
tclib.get.restype = ctypes.c_char_p

#buf = []

def _ToCStr(S):
    cStr = ctypes.c_char_p(  bytes(S, COMM_ENC)  )
    #buf.append(cStr)

    return cStr

def _ToPyStr(S):
    return S.decode(COMM_ENC)

def _Set(K, V):
    tclib.set(  _ToCStr(K), _ToCStr(V)  )

def _Get(K):
    kBytes = _ToCStr(K)
    v = tclib.get(kBytes)

    return _ToPyStr(v)

def _GenerateKeyValuePairs():
    k = []
    for i in range(10):
        k.append(random.randint(0, 100))
    print(k)

def main():
    _Set('abc', '1234')
    res = _Get('abc')
    print(  '"{}"'.format(res)  )

    res = _Get('abc!')
    print(  '"{}"'.format(res)  )

    _Set('abc', '3333')
    res = _Get('abc')
    print(  '"{}"'.format(res)  )

    res = _Get('def')
    print(  '"{}"'.format(res)  )

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)

    _GenerateKeyValuePairs()
