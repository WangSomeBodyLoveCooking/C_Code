# 复用之前代码
import numpy as np

# ========== 复用完整网络层 + 两层神经网络（同第五周最终版） ==========
class Sigmoid:
    def __init__(self):
        self.out = None
    def forward(self, x):
        self.out = 1 / (1 + np.exp(-x))
        return self.out
    def backward(self, dout):
        return dout * self.out * (1 - self.out)

class Affine:
    def __init__(self, W, b):
        self.W = W
        self.b = b
        self.x = None
        self.dW = None
        self.db = None
    def forward(self, x):
        self.x = x
        return np.dot(x, self.W) + self.b
    def backward(self, dout):
        dx = np.dot(dout, self.W.T)
        self.dW = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis=0)
        return dx

def softmax(x):
    x = x - np.max(x, axis=1, keepdims=True)
    return np.exp(x) / np.sum(np.exp(x), axis=1, keepdims=True)

def cross_entropy_error(y, t):
    return -np.sum(t * np.log(y + 1e-7)) / y.shape[0]

class SoftmaxWithLoss:
    def __init__(self):
        self.loss = None
        self.y = None
        self.t = None
    def forward(self, x, t):
        self.t = t
        self.y = softmax(x)
        self.loss = cross_entropy_error(self.y, self.t)
        return self.loss
    def backward(self, dout=1):
        batch_size = self.t.shape[0]
        return (self.y - self.t) / batch_size

class TwoLayerNet:
    def __init__(self, input_size, hidden_size, output_size):
        self.params = {}
        self.params['W1'] = 0.01 * np.random.randn(input_size, hidden_size)
        self.params['b1'] = np.zeros(hidden_size)
        self.params['W2'] = 0.01 * np.random.randn(hidden_size, output_size)
        self.params['b2'] = np.zeros(output_size)
        self.layers = [
            Affine(self.params['W1'], self.params['b1']),
            Sigmoid(),
            Affine(self.params['W2'], self.params['b2'])
        ]
        self.last_layer = SoftmaxWithLoss()
    def predict(self, x):
        for layer in self.layers:
            x = layer.forward(x)
        return x
    def loss(self, x, t):
        y = self.predict(x)
        return self.last_layer.forward(y, t)
    def accuracy(self, x, t):
        y = np.argmax(self.predict(x), axis=1)
        t = np.argmax(t, axis=1)
        return np.sum(y == t) / float(x.shape[0])
    def gradient(self, x, t):
        self.loss(x, t)
        dout = self.last_layer.backward()
        for layer in reversed(self.layers):
            dout = layer.backward(dout)
        grads = {}
        grads['W1'] = self.layers[0].dW
        grads['b1'] = self.layers[0].db
        grads['W2'] = self.layers[2].dW
        grads['b2'] = self.layers[2].db
        return grads
    
# 练习 2：手写 SGD 参数更新代码（单步更新）
# 给定参数、梯度、学习率，完成一次 SGD 更新：
# 模拟参数、梯度
W = np.array([[0.1, 0.2], [0.3, 0.4]])
dW = np.array([[0.01, 0.02], [0.03, 0.04]])
lr = 0.1

# SGD 更新规则
W = W - lr * dW
print("更新后权重：\n", W)

# 练习 5：封装通用 SGD 优化器类（标准写法）
class SGD:
    def __init__(self, lr = 0.01):
        self.lr = lr

    def updatepara(self, params, grads):
        for key in params.keys():
            params[key] -= self.lr*grads[key]

# 测试
optimizer = SGD(lr=0.1)
net = TwoLayerNet(784, 50, 10)
x_batch = np.random.rand(100, 784)
t_batch = np.eye(10)[np.random.randint(0,10,100)]
grads = net.gradient(x_batch, t_batch)
optimizer.updatepara(net.params, grads)

# 练习 7：观察损失震荡现象
# 构造模拟数据
x_train = np.random.rand(6000, 784)
t_train = np.eye(10)[np.random.randint(0,10,6000)]

net = TwoLayerNet(784, 50, 10)
optimizer = SGD(lr=0.1)
batch_size = 100
iters = 200
loss_list = []

for i in range(iters):
    batch_mask = np.random.choice(6000, batch_size)
    x_batch = x_train[batch_mask]
    t_batch = t_train[batch_mask]
    grads = net.gradient(x_batch, t_batch)
    optimizer.updatepara(net.params, grads)
    loss = net.loss(x_batch, t_batch)
    loss_list.append(loss)

# 绘制损失曲线
import matplotlib.pyplot as plt
plt.plot(loss_list)
plt.xlabel("iter")
plt.ylabel("loss")
plt.title("Mini-batch SGD Loss")
plt.show()

# 练习 9：基于 SGD 优化器，封装完整训练函数
def train_sgd(net, optimizer, x_train, t_train, batch_size, iters):
    for i in range(iters):
        batch_mask = np.random.choice(len(x_train), batch_size)
        x_batch = x_train[batch_mask]
        t_batch = t_train[batch_mask]
        grads = net.gradient(x_batch, t_batch)
        optimizer.updatepara(net.params, grads)
        loss = net.loss(x_batch, t_batch)
        loss_list.append(loss)
        if i % 50 == 0:
            acc = net.accuracy(x_train, t_train)
            print(f"迭代{i:3d} | loss:{loss:.4f} | acc:{acc:.4f}")
    return loss_list

# 调用
net = TwoLayerNet(784, 50, 10)
opt = SGD(lr=0.1)
x_train = np.random.rand(6000,784)
t_train = np.eye(10)[np.random.randint(0,10,6000)]
train_sgd(net, opt, x_train, t_train, batch_size=100, iters=300)