import numpy as np

# 练习 1 手写 ReLU 类
class Relu:
    def __init__(self):
        self.mask = None
    
    def forward(self, x):
        self.mask = (x <= 0)
        out = x.copy()
        out[self.mask] = 0
        return out
    
    def backward(self, dout):
        dx = dout.copy()
        dx[self.mask] = 0
        return dx

#测试
relu = Relu()
x = np.array([1,-2,3,-4])
y = relu.forward(x)
print("forward:",y)
dy = np.array([0.1,0.2,0.3,0.4])
dx = relu.backward(dy)
print("backward dx:",dx)

print("*"*50, "test1")

# 练习 3：Sigmoid 完整类
class Sigmoid:
    def __init__(self) -> None:
        self.out = None
    
    def forward(self, x):
        out = 1/(1+np.exp(-x))
        self.out = out
        return out
    
    def backward(self, dout):
        dx = dout*(self.out * (1-self.out))
        return dx
    
#测试
sigmoid = Sigmoid()
x = np.array([1,0,-1])
y = sigmoid.forward(x)
print("forward:",y)
dy = np.array([1,1,1])
dx = sigmoid.backward(dy)
print("backward dx:",dx)