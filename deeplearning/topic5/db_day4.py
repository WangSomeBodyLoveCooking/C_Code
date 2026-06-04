import numpy as np
# 练习 1：Affine 层完整代码（矩阵乘法 + 偏置）
class Affine:
    def __init__(self, w, b):
        self.w = w
        self.b = b
        self.dw = None
        self.db = None
        self.x = None
    
    def forward(self, x):
        out = np.dot(x, self.w) + self.b
        self.x = x
        return out
    
    def backward(self, dout):
        dx = np.dot(dout, self.w.T)
        self.dw = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis=0)
        return dx

# 练习 2：测试 Affine 层正向传播
# 初始化参数：输入2维 → 输出3维
W = np.random.randn(2, 3)
b = np.zeros(3)
affine = Affine(W, b)

# 批量输入：2个样本，每个2维
x = np.array([[1, 2], [3, 4]])
out = affine.forward(x)
print("输出形状:", out.shape)  # (2,3)


# 练习 3：测试 Affine 层反向传播（计算 W/b 梯度）
# 上游梯度
dout = np.ones_like(out)
dx = affine.backward(dout)

print("dx形状:", dx.shape)    # (2,2) 与输入x一致
print("dW形状:", affine.dw.shape)  # (2,3) 与权重W一致
print("db形状:", affine.db.shape)  # (3,) 与偏置b一致


print("*"*50)

# 练习 2：测试 Affine 层正向传播
# 初始化参数：输入2维 → 输出3维
W = np.random.randn(4, 3)
b = np.zeros(3)
affine = Affine(W, b)

# 批量输入：2个样本，每个2维
x = np.array([1,2,3,4])
# x升维
x = x.reshape(1, -1)
out = affine.forward(x)
print("输出形状:", out.shape)  # (2,3)


# 练习 3：测试 Affine 层反向传播（计算 W/b 梯度）
# 上游梯度
dout = np.ones_like(out)
dx = affine.backward(dout)

print("dx形状:", dx.shape)    # (2,2) 与输入x一致
print("dW形状:", affine.dw.shape)  # (2,3) 与权重W一致
print("db形状:", affine.db.shape)  # (3,) 与偏置b一致


# 练习 5：Softmax-with-Loss 层完整代码
def softmax(x):
    x = x - np.max(x, axis=1, keepdims=True)
    return np.exp(x) / np.sum(np.exp(x), axis=1, keepdims=True)

def cross_entropy_error(y, t):
    delta = 1e-7
    return -np.sum(t * np.log(y + delta)) / y.shape[0]

class SoftmaxWithLoss:
    def __init__(self):
        self.t = None
        self.y = None

    def forward(self, x, t):
        y = softmax(x)
        self.y = y
        self.t = t
        loss = cross_entropy_error(y, t)
        return loss
    
    def backward(self, dout=1):
        return (self.y - self.t)/self.y.shape[0]
    
# 模拟输出+One-Hot标签
x = np.array([[1, 2, 3]])
t = np.array([[0, 0, 1]])

layer = SoftmaxWithLoss()
layer.forward(x, t)
dx = layer.backward()
print("dx = y - t:\n", dx)