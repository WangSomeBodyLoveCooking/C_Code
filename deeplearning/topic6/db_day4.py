# 练习 5：手写训练阶段 BN 正向传播（简化版）
import numpy as np

def batch_norm_forward(x, gamma, beta, eps = 1e-7):
    # 1. 计算批次均值、方差
    mu = x.mean(axis=0)
    var = x.var(axis=0)

    x_hat = (x - mu)/np.sqrt(var+eps)

    out = gamma*x_hat+beta
    return out

# 测试：批次100样本，每个样本10维
x = np.random.randn(100, 10)
gamma = np.ones(10)
beta = np.zeros(10)
y = batch_norm_forward(x, gamma, beta)
print("标准化后均值：", y.mean(axis=0).round(4))  # 接近0
print("标准化后方差：", y.var(axis=0).round(4))   # 接近1