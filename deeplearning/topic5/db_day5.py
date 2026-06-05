import numpy as np
# 前置：汇总所有依赖层代码
# 激活函数层
class Sigmoid:
    def __init__(self):
        self.y = None
    
    def forward(self, x):
        self.y = 1 / (1 + np.exp(-x))
        return self.y
    
    def backward(self, dout):
        return dout * self.y * (1-self.y)

class Relu:
    def __init__(self):
        self.mask = None

    def forward(self, x):
        self.mask = (x <= 0)
        tem = x.copy()
        tem[self.mask] = 0
        return tem
    
    def backward(self, dout):
        tem = dout.copy()
        tem[self.mask] = 0
        return tem
    
# Affine层
class Affine:
    def __init__(self, w, b):
        self.w = w
        self.b = b
        self.x = None
        self.dw = None
        self.dx = None

    def forward(self, x):
        self.x = x
        y = np.dot(x, self.w) + self.b
        return y
    
    def backward(self, dout):
        dx = np.dot(dout, self.w.T)
        self.dw = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis=0)
        return dx

# 输出层+损失层
def softmax(x):
    c = np.max(x, axis=1, keepdims=True)
    tem = np.exp(x - c)
    total = np.sum(tem, axis=1, keepdims=True)
    return tem / total

def cross_loss(y, t):
    h = 1e-6
    return -np.sum(t*np.log(y+h))/y.shape[0]

class SoftmaxWithLoss:
    def __init__(self):
        self.y = None
        self.t = None

    def forward(self, x, t):
        self.t = t
        self.y = softmax(x)
        loss = cross_loss(self.y, self.t)
        return loss
    
    def backward(self, dout=1):
        return (self.y - self.t)/self.y.shape[0]
    
def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)
    it = np.nditer(x, flags=['multi_index'], op_flags=['readwrite'])
    while not it.finished:
        idx = it.multi_index
        tmp_val = x[idx]
        
        # f(x+h)
        x[idx] = tmp_val + h
        fxh1 = f(x)
        
        # f(x-h)
        x[idx] = tmp_val - h
        fxh2 = f(x)
        
        grad[idx] = (fxh1 - fxh2) / (2*h)
        x[idx] = tmp_val
        it.iternext()
    return grad

# 练习 1：编写 BP 版 TwoLayerNet
class TwoLayerNet:
    def __init__(self, init_num, hidden_num, out_num , init_weight_rat = 0.01):
        self.params = {}
        self.params["w1"] = np.random.randn(init_num, hidden_num)*init_weight_rat
        self.params["b1"] = np.zeros(hidden_num)
        self.params["w2"] = np.random.randn(hidden_num, out_num)*init_weight_rat
        self.params["b2"] = np.zeros(out_num)

        self.layers = [
            Affine(self.params["w1"],self.params["b1"]),
            Relu(),
            Affine(self.params["w2"],self.params["b2"]),
        ]

        self.last_layer = SoftmaxWithLoss()

    def predict(self, x):
        for layer in self.layers:
            x = layer.forward(x)

        return x
        
    def loss(self, x, t):
        y = self.predict(x)
        loss_value = self.last_layer.forward(y,t)
        return loss_value
        
    def gradient(self, x, t):
            # 正向传播
            self.loss(x,t)

            # 反向传播
            dout = self.last_layer.backward()
            for layer in reversed(self.layers):  #必须翻转
                dout = layer.backward(dout)

            grad = {}
            grad["w1"] = self.layers[0].dw
            grad["b1"] = self.layers[0].db
            grad["w2"] = self.layers[2].dw
            grad["b2"] = self.layers[2].db
            return grad

# 练习 2：初始化 MNIST 规格网络
net = TwoLayerNet(init_num=784,hidden_num=50,out_num=10)
print(net.params["w1"].shape, net.params["w2"].shape)

# 练习 3：构造单样本数据，执行一次 BP 梯度
# 1个样本784维，标签one-hot10维
x = np.random.rand(1,784)
t = np.eye(10)[[3]]
grads_bp = net.gradient(x,t)
print("W1梯度形状",grads_bp["w1"].shape)

# 练习 4：封装数值梯度函数用于校验
def num_grad_wrapper(net,x,t):
    def loss(w):
        return net.loss(x,t)

    grads = {}
    for i in net.params.keys():
        grads[i] = numerical_gradient(loss, net.params[i])

    return grads

# 练习 5：梯度校验，计算 BP 梯度与数值梯度平均误差
# 取少量参数对比，防止计算过慢
x = np.random.rand(2,784)
t = np.eye(10)[np.random.randint(0,10,2)]
grad_bp = net.gradient(x,t)
# 随机截取一小块权重做误差比对
err = np.mean(np.abs(grad_bp["w1"][:5,:5] - num_grad_wrapper(net,x,t)["w1"][:5,:5]))
print("梯度平均误差：",err)
# 正常：1e-5左右

# 练习 9：单步 BP 参数更新
lr=0.1
grads=net.gradient(x,t)
for k in net.params:
    print(k, net.params[k].shape, grads[k].shape)
    net.params[k] -= lr*grads[k]