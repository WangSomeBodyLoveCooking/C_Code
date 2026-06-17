import numpy as np

def loss_with_l2(y, t, W_list, lam):
    """
    y: 模型输出
    t: 真实标签
    W_list: 所有权重矩阵的列表
    lam: 正则化系数λ
    """
    # 原交叉熵损失
    delta = 1e-7
    origin_loss = -np.sum(t * np.log(y + delta)) / y.shape[0]
    
    # L2正则化项
    l2_sum = 0
    for W in W_list:
        l2_sum += np.sum(W ** 2)
    l2_term = 0.5 * lam * l2_sum
    
    return origin_loss + l2_term

# 测试
y = np.array([[0.7, 0.2, 0.1]])
t = np.array([[1, 0, 0]])
W = np.array([[0.5, 0.3], [0.2, 0.4]])
print("总损失：", loss_with_l2(y, t, [W], lam=0.1))


class Dropout:
    def __init__(self, dropout_ratio=0.5):
        self.dropout_ratio = dropout_ratio
        self.mask = None

    def forward(self, x, train_flg=True):
        if train_flg:
            # 训练阶段：生成掩码，随机删除神经元
            self.mask = np.random.rand(*x.shape) > self.dropout_ratio
            return x * self.mask
        else:
            # 测试阶段：全部保留，乘以保留比例
            return x * (1.0 - self.dropout_ratio)

    def backward(self, dout):
        # 反向传播：被删除的神经元梯度也为0
        return dout * self.mask

# 测试
drop = Dropout(0.5)
x = np.ones((1, 10))
print("训练前向：", drop.forward(x, train_flg=True))
print("测试前向：", drop.forward(x, train_flg=False))