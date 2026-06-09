import numpy as np
# 练习 2：实现 Momentum 优化器类（标准工业写法）
class Momentum:
    def __init__(self, lr = 0.01, momentum=0.9):
        self.v = None
        self.lr = lr
        self.momentum = momentum

    def update(self, params, grad):
        if self.v is None:
            self.v = {}
            for key,value in params.items():
                self.v[key] = np.zeros_like(value)
        
        for key in params.keys():
            self.v[key] = self.momentum*self.v[key] - self.lr*grad[key]
            params[key] += self.v[key]

# 练习 3：单步测试 Momentum 更新
# 复用两层网络
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

# 测试代码
net = TwoLayerNet(784, 50, 10)
opt = Momentum()

# 构造批量数据
x_batch = np.random.rand(100, 784)
t_batch = np.eye(10)[np.random.randint(0, 10, 100)]

grads = net.gradient(x_batch, t_batch)
opt.update(net.params, grads)
print("Momentum 单步更新完成")

# 练习 5：对比 SGD 与 Momentum 损失曲线
class SGD:
    def __init__(self, lr=0.01):
        self.lr = lr

    def update(self, params, grad):
        for key in params.keys():
            params[key] -= self.lr*grad[key]


# 构造批量数据
x_train = np.random.rand(6000, 784)
t_train = np.eye(10)[np.random.randint(0, 10, 6000)]



def train(net, optimizer, x_train, t_train, batch_size, iters):
    loss_list = []
    for i in range(iters):
        batch_mask = np.random.choice(len(x_train), batch_size)
        x_batch = x_train[batch_mask]
        t_batch = t_train[batch_mask]

        grad = net.gradient(x_batch, t_batch)
        optimizer.update(net.params, grad)
        loss_list.append(net.loss(x_batch, t_batch))
    return loss_list

net1 = TwoLayerNet(784, 50, 10)
opt_Moment = Momentum()

net2 = TwoLayerNet(784, 50, 10)
opt_Sgd = SGD()

loss_momentum = train(net1, opt_Moment, x_batch, t_batch, 100, 200)

loss_sgd = train(net2, opt_Sgd, x_batch, t_batch, 100, 200)

# 绘图对比
import matplotlib.pyplot as plt
plt.plot(loss_sgd, label="SGD")
plt.plot(loss_momentum, label="Momentum")
plt.legend()
plt.xlabel("iter")
plt.ylabel("loss")
plt.show()

# 练习 9：完整训练 + 准确率对比
def train_with_acc(net, optimizer, x_train, t_train, x_test, t_test, batch_size, iters):
    train_acc_list = []
    for i in range(iters):
        batch_mask = np.random.choice(len(x_train), batch_size)
        x_batch = x_train[batch_mask]
        t_batch = t_train[batch_mask]
        grads = net.gradient(x_batch, t_batch)
        optimizer.update(net.params, grads)
        
        if i % 50 == 0:
            train_acc = net.accuracy(x_train, t_train)
            train_acc_list.append(train_acc)
            print(f"迭代{i} | 训练准确率: {train_acc:.4f}")
    return train_acc_list

# 构造测试集
x_test = np.random.rand(1000, 784)
t_test = np.eye(10)[np.random.randint(0, 10, 1000)]

net_mom = TwoLayerNet(784, 50, 10)
acc_list = train_with_acc(net_mom, Momentum(lr=0.08), x_train, t_train, x_test, t_test, 100, 300)