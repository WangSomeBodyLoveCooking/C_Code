# import numpy as np
# import matplotlib.pyplot as plt

# # 练习 1：复现所有核心函数（激活 / Softmax / 损失 / 梯度）
# # 激活函数
# def step_func(x):
#     return np.where(x > 0, 1, 0)

# def sigmoid(x):
#     return 1/(1+np.exp(-x))

# def relu(x):
#     return np.maximum(0, x)

# # 2. 输出层函数
# def softmax(x):
#     c = np.max(x)
#     tem = np.exp(x-c)
#     total = np.sum(tem)
#     return tem/total

# # 3.损失函数---平方差
# def mse_loss(y,t):
#     if y.ndim == 1:
#         y = y.reshape(1,y.size)
#         t = t.reshape(1,t.size)

#     batch = y.shape[0]
#     return 0.5*np.sum((y - t)**2)/batch

# # 3. 交叉熵损失
# def cross_entropy_error(y, t):
#     if y.ndim == 1:
#         y = y.reshape(1,y.size)
#         t = t.reshape(1,t.size)

#     batch = y.shape[0]
#     delay = 1e-6
#     return -np.sum(t*np.log(y+delay)) / batch
    
# # 4. 数值梯度（核心）
# def numerical_gradient(f, x):
#     row = None
#     col = None
#     if x.ndim != 1 :
#         row, col = x.shape
#     x = x.flatten() # 扁平化

#     grad = np.zeros_like(x)
#     h = 1e-4
#     for i in range(x.size):
#         tem = x[i]
#         x[i] = tem + h
#         fxh1 = f(x)
#         x[i] = tem -h
#         fxh2 = f(x)
#         grad[i] = (fxh1-fxh2)/(2*h)
#         x[i] = tem

#     if row and col:
#         grad = grad.reshape(row,col)
#     return grad

# # 练习 2：初始化两层网络参数（MNIST 专用）
# def init_network():
#     net_work = {}
#     net_work["W1"] = np.random.randn(784,50)*0.01
#     net_work["b1"] = np.zeros(50)  # 用0初始化更稳定
#     net_work["W2"] = np.random.randn(50,10)*0.01
#     net_work["b2"] = np.zeros(10)
#     return net_work

# # 练习 3：实现网络前向传播
# def forward(network, x):
#     W1,W2 = network["W1"], network["W2"]
#     b1,b2 = network["b1"], network["b2"]
#     a1 = np.dot(x, W1) + b1  # 补全偏置！原始代码漏了 +b1
#     z1 = relu(a1)
#     a2 = np.dot(z1, W2) + b2  # 补全偏置！原始代码漏了 +b2
#     y = softmax(a2)
#     return y
    
# # 练习 4：定义神经网络专用损失函数
# def loss_function(network, x, t):
#     y = forward(network, x)
#     return cross_entropy_error(y,t)

# # 练习 5：模拟 MNIST 单张数据 + One-Hot 标签
# x = np.random.rand(784)
# t = np.eye(10)[3]
# print("One-Hot标签:", t)

# # ========================
# # 练习 6：修复版 - 计算网络参数梯度（核心修正）
# # ========================
# def compute_network_gradients(network, x, t):
#     grads = {}
#     # 1. 计算 W1 的梯度（固定其他参数）
#     def f_W1(W1):
#         net = network.copy()
#         net['W1'] = W1.reshape(784,50)  # 恢复形状
#         return loss_function(net, x, t)
#     grads['W1'] = numerical_gradient(f_W1, network['W1'])

#     # 2. 计算 b1 的梯度
#     def f_b1(b1):
#         net = network.copy()
#         net['b1'] = b1
#         return loss_function(net, x, t)
#     grads['b1'] = numerical_gradient(f_b1, network['b1'])

#     # 3. 计算 W2 的梯度
#     def f_W2(W2):
#         net = network.copy()
#         net['W2'] = W2.reshape(50,10)
#         return loss_function(net, x, t)
#     grads['W2'] = numerical_gradient(f_W2, network['W2'])

#     # 4. 计算 b2 的梯度
#     def f_b2(b2):
#         net = network.copy()
#         net['b2'] = b2
#         return loss_function(net, x, t)
#     grads['b2'] = numerical_gradient(f_b2, network['b2'])

#     return grads

# # 执行练习6
# network = init_network()
# gradients = compute_network_gradients(network, x, t)

# # 打印结果
# print("\n===== 练习 6 梯度计算结果 =====")
# print("W1 梯度形状:", gradients["W1"].shape)
# print("b1 梯度形状:", gradients["b1"].shape)
# print("W2 梯度形状:", gradients["W2"].shape)
# print("b2 梯度形状:", gradients["b2"].shape)
# print("\n梯度计算完成！")

import numpy as np

# 1. 激活函数
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# 2. 输出层函数
def softmax(x):
    c = np.max(x)
    exp_a = np.exp(x - c)
    return exp_a / np.sum(exp_a)

# 3. 交叉熵损失
def cross_entropy_error(y, t):
    delta = 1e-7
    return -np.sum(t * np.log(y + delta))

# 4. 数值梯度（核心）
def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)
    for idx in range(x.size):
        tmp_val = x[idx]
        x[idx] = tmp_val + h
        fxh1 = f(x)
        x[idx] = tmp_val - h
        fxh2 = f(x)
        grad[idx] = (fxh1 - fxh2) / (2*h)
        x[idx] = tmp_val
    return grad

def init_network():
    # 784→50→10 (输入→隐藏→输出)
    network = {}
    network['W1'] = np.random.randn(784, 50) * 0.01  # 权重
    network['b1'] = np.zeros(50)                     # 偏置
    network['W2'] = np.random.randn(50, 10) * 0.01
    network['b2'] = np.zeros(10)
    return network

# 初始化网络
network = init_network()
print("W1形状:", network['W1'].shape)  # (784,50)
print("W2形状:", network['W2'].shape)  # (50,10)

def forward(network, x):
    W1, W2 = network['W1'], network['W2']
    b1, b2 = network['b1'], network['b2']
    
    a1 = np.dot(x, W1) + b1
    z1 = sigmoid(a1)
    a2 = np.dot(z1, W2) + b2
    y = softmax(a2)
    return y  # 输出概率

# 输入：参数(展平为一维)、数据x、标签t
# 输出：损失值
def loss_function(params, x, t):
    # 把一维参数还原为网络权重/偏置
    W1 = params[:784*50].reshape(784,50)
    b1 = params[784*50 : 784*50+50].reshape(50)
    W2 = params[784*50+50 : 784*50+50+50*10].reshape(50,10)
    b2 = params[-10:].reshape(10)
    
    # 临时网络
    net = {'W1':W1, 'b1':b1, 'W2':W2, 'b2':b2}
    y = forward(net, x)
    return cross_entropy_error(y, t)

# 模拟1张28x28图像(784维)
x = np.random.rand(784)
# 模拟标签：数字3 → One-Hot编码
t = np.eye(10)[3]
print("One-Hot标签:", t)

# 把网络所有参数展平为一维
params = np.concatenate([network['W1'].flatten(),
                         network['b1'].flatten(),
                         network['W2'].flatten(),
                         network['b2'].flatten()])

# 计算梯度（损失对所有参数的导数）
grad = numerical_gradient(lambda p: loss_function(p, x, t), params)

print("参数总数:", params.size)
print("梯度总数:", grad.size)  # 和参数数量完全一致

# 把梯度还原为W1/b1/W2/b2，用于更新参数
grad_W1 = grad[:784*50].reshape(784,50)
grad_b1 = grad[784*50 : 784*50+50].reshape(50)
grad_W2 = grad[784*50+50 : -10].reshape(50,10)
grad_b2 = grad[-10:].reshape(10)

print("grad_W1形状:", grad_W1.shape)  # 与W1完全相同

lr = 0.1  # 学习率
# 用梯度更新权重
network['W1'] -= lr * grad_W1
network['b1'] -= lr * grad_b1
network['W2'] -= lr * grad_W2
network['b2'] -= lr * grad_b2

def train_step(network, x, t, lr=0.1):
    # 展平参数
    params = np.concatenate([net.flatten() for net in network.values()])
    # 计算梯度
    grad = numerical_gradient(lambda p: loss_function(p, x, t), params)
    # 还原梯度
    grad_W1 = grad[:784*50].reshape(784,50)
    grad_b1 = grad[784*50:784*50+50].reshape(50)
    grad_W2 = grad[784*50+50:-10].reshape(50,10)
    grad_b2 = grad[-10:].reshape(10)
    # 更新参数
    network['W1'] -= lr * grad_W1
    network['b1'] -= lr * grad_b1
    network['W2'] -= lr * grad_W2
    network['b2'] -= lr * grad_b2
    return network

# 更新前损失
loss_before = loss_function(params, x, t)
# 训练1步
network = train_step(network, x, t)
# 更新后损失
params_new = np.concatenate([net.flatten() for net in network.values()])
loss_after = loss_function(params_new, x, t)

print(f"更新前损失: {loss_before:.3f}")
print(f"更新后损失: {loss_after:.3f}")  # 损失一定减小！