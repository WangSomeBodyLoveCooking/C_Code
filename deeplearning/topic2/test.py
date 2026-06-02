# python实现感知机的与门、与非门和非门电路
# 1. 与门简单版
def AND(x1,x2):
    w1 = 0.5
    w2 = 0.5
    tmp = 0.8
    return int(w1*x1+w2*x2 > tmp)

print(AND(0,0))
print(AND(1,0))
print(AND(0,1))
print(AND(1,1))
print('*'*50)

# 2. 权重、偏置版本
import numpy as np
def AND_new(x1,x2):
    X = np.array([x1,x2])
    W = np.array([0.5,0.5])
    b = -0.8
    return int(np.sum(X*W)+b > 0)

print(AND(0,0))
print(AND(1,0))
print(AND(0,1))
print(AND(1,1))
print('*'*50)

def NAND(x1,x2):
    X = np.array([x1,x2])
    W = np.array([-0.5,-0.5])
    b = 0.8
    return int(np.sum(X*W)+b > 0)
print(NAND(0,0))
print(NAND(1,0))
print(NAND(0,1))
print(NAND(1,1))
print('*'*50)

def OR(x1,x2):
    X = np.array([x1,x2])
    W = np.array([0.5,0.5])
    b = -0.3
    return int(np.sum(X*W)+b > 0)
print(OR(0,0))
print(OR(1,0))
print(OR(0,1))
print(OR(1,1))
print('*'*50)

# 3. 异或门的实现
def XOR(x1,x2):
    x1_new = NAND(x1,x2)
    x2_new = OR(x1,x2)
    return AND_new(x1_new,x2_new)
print(XOR(0,0))
print(XOR(1,0))
print(XOR(0,1))
print(XOR(1,1))
print('*'*50)
