# 1. sigmoid + 阶跃函数实现
import numpy as np
import matplotlib.pylab as plt
def sigmoid(X):
    return 1/(1+np.exp(-X))

def step(X):
    return np.array(X>0,dtype = np.int32)

# 2. Relu函数
def relu(X):
    return np.maximum(X,0)


X = np.arange(-5,5,0.1)
Y1 = sigmoid(X)
Y2 = step(X)
Y3 = relu(X)
plt.plot(X,Y1,label='sigmoid', linewidth=2)
plt.plot(X,Y2,label='step')
plt.plot(X,Y3,label='relu')
plt.ylim(-0.1,1.1)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("sigmoid_step_relu")
plt.legend()  # 显示图例
plt.grid(True, alpha=0.3) # 加网格更清晰
plt.show()

# 3. 多层神经网络的实现---前向传播
# 2*3*2*2 结构
def init_network():
    net_work = {}
    net_work["W1"] = np.array([[0.1,0.2,0.3],[0.4,0.5,0.6]])
    net_work["B1"] = np.array([1,2,3])
    net_work["W2"] = np.array([[0.1,0.2],[0.3,0.4],[0.5,0.6]])
    net_work["B2"] = np.array([1,2])
    net_work["W3"] = np.array([[0.1,0.2],[0.3,0.4]])
    net_work["B3"] = np.array([1,2])
    return net_work

def forword_pass(X,net_work):
    W1 = net_work["W1"]
    B1 = net_work["B1"]
    W2 = net_work["W2"]
    B2 = net_work["B2"]
    W3 = net_work["W3"]
    B3 = net_work["B3"]

    A1 = np.dot(X,W1) + B1
    Z1 = sigmoid(A1)
    A2 = np.dot(Z1,W2) + B2
    Z2 = sigmoid(A2)
    Y = np.dot(Z2,W3) + B3
    return Y

X = np.array([1,1])
net_work = init_network()
Y = forword_pass(X,net_work)
print(Y)

# 4. soft_max函数
def soft_max(X):
    max_num = np.max(X)
    X = X - max_num
    return np.exp(X)/np.sum(np.exp(X))

X = np.arange(-5,5,0.1)
Y = soft_max(X)
plt.plot(X,Y,linewidth=2)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("soft_max")
plt.legend()  # 显示图例
plt.grid(True, alpha=0.3) # 加网格更清晰
plt.show()

