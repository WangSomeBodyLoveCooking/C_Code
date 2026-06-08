import numpy as np

# 激活层
class Sigmoid:
    def __init__(self):
        self.y = None

    def forward(self, x):
        self.y = 1/(1+np.exp(-x))
        return self.y
    
    def backward(self, dout):
        dx = dout * self.y * (1-self.y)
        return dx

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
    
# Affine层
class Affine:
    def __init__(self, w, b):
        self.w = w
        self.b = b
        self.x = None
        self.dw = None
        self.db = None
    
    def forward(self, x):
        self.x = x
        out = np.dot(x, self.w) + self.b
        return out
    
    def backward(self, dout):
        
        dx = np.dot(dout, self.w.T)
        self.dw = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis=0)
        return dx
    
# 输出+损失层
def softmax(x):
    c = np.max(x, axis=1, keepdims=True)
    tem = np.exp(x - c)
    total = np.sum(tem, axis=1, keepdims=True)
    return tem/total

def cross_loss(y,t):
    h = 1e-6
    return -np.sum(t*np.log(y+h)) / y.shape[0]

class SoftmaxWithLoss:
    def __init__(self):
        self.y = None
        self.t = None
        self.loss = None
    
    def forward(self, x, t):
        self.t = t
        self.y = softmax(x)
        self.loss = cross_loss(self.y,t)
        return self.loss
    
    def backward(self, dout= 1):
        dx = (self.y - self.t)/self.y.shape[0]
        return dx
    
# 两层实现
class TwoLayerNet:
    def __init__(self, init_size, hidden_size, out_size, init_weight_rat=0.01):
        self.params = {}
        self.params["w1"] = np.random.randn(init_size, hidden_size) * init_weight_rat
        self.params["b1"] = np.zeros(hidden_size)
        self.params["w2"] = np.random.randn(hidden_size, out_size) * init_weight_rat
        self.params["b2"] = np.zeros(out_size)

        self.layers = [
            Affine(self.params["w1"], self.params["b1"]),
            Relu(),
            Affine(self.params["w2"], self.params["b2"]),
        ]

        self.last_layer = SoftmaxWithLoss()

    def predict(self, x):
        y = x.copy()
        for layer in self.layers:
            y = layer.forward(y)    ##***********y要更新不能用x
        return y
    
    def loss(self, x, t):
        y = self.predict(x)
        loss_v = self.last_layer.forward(y, t)
        return loss_v
    
    def gradient(self, x, t):
        # 正向传播获取参数
        self.loss(x, t)

        # 反向传播获取梯度
        dout = self.last_layer.backward()

        for layer in reversed(self.layers):
            dout = layer.backward(dout)

        grad = {}
        grad["w1"] = self.layers[0].dw
        grad["b1"] = self.layers[0].db
        grad["w2"] = self.layers[2].dw
        grad["b2"] = self.layers[2].db
        return grad
    
    def accuracy(self, x, t):
        y = np.argmax(self.predict(x), axis=1)
        t = np.argmax(t, axis=1)
        return np.sum(y == t) / float(x.shape[0])#*******
    
def numerial_diff(f, x):
    grad = np.zeros_like(x)
    h = 1e-6
    iter = np.nditer(x, flags="multi_index", op_flags="readwrite")
    while not iter.finished:
        index = iter.multi_index
        tem = x[index]
        x[index] = tem + h
        fx1 = f(x)
        x[index] = tem - h
        fx2 = f(x)

        grad[index] = (fx1-fx2)/(2*h)
        x[index] = tem

    return grad



input_size = 784
hidden_size = 50
out_size = 10

net = TwoLayerNet(input_size, hidden_size, out_size)

# 梯度检查
def cal_gradient_for_nd(net, x ,t):
    pass 

x_train = np.random.rand(60000, 784)
t_train = np.eye(10)[np.random.randint(0, 10, 60000)]
x_test = np.random.rand(10000, 784)
t_test = np.eye(10)[np.random.randint(0, 10, 10000)]


# 输入数据

lr = 0.01
batch_size = 100
iter_cout = 100000
per_lun = x_train.shape[0]/batch_size

train_loss_list = []
accuracy_train_list = []
accuracy_test_list = []

for i in range(iter_cout):
    # 挑选批次数据
    rd = np.random.choice(x_train.shape[0], batch_size)
    x_input = x_train[rd]
    t_input = t_train[rd]

    loss = net.loss(x_input, t_input)
    train_loss_list.append(loss)

    grad = net.gradient(x_input, t_input)

    for k in net.params.keys():
        net.params[k] -= lr*grad[k]

    if i % per_lun == 0:
        train_acc = net.accuracy(x_input, t_input)
        accuracy_train_list.append(train_acc)
        test_acc = net.accuracy(x_test, t_test)
        accuracy_test_list.append(test_acc)

        print(f"第{i}次迭代，训练集精度{train_acc}, 测试集精度{test_acc}")







