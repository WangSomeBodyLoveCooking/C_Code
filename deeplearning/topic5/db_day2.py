from doubao_day1 import MulLayer,AddLayer
# 练习 7：复杂嵌套：y = ((x1 + x2) * x3) + x4
x1, x2, x3, x4 = 1,2,3,4
ad1 = AddLayer()
mu1 = MulLayer()
ad2 = AddLayer()

# 正向传播
sum_x1_x2 = ad1.forward(x1, x2)
mul_x1_x2_x3 = mu1.forward(sum_x1_x2, x3)
y = ad2.forward(mul_x1_x2_x3, x4)
print(f"y = {y}")

# 反向传播
dmul_x1_x2_x3, dx4 = ad2.backward(1)
dx1_x2, dx3 = mu1.backward(dmul_x1_x2_x3)
dx1, dx2 = ad1.backward(dx1_x2)
print(f"dx1 = {dx1}, dx2 = {dx2}, dx3 = {dx3}, dx4 = {dx4}")



