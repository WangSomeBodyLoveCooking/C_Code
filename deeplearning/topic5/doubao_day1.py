# 练习 3：代码实现 乘法层（正向传播、反向传播）
# 封装乘法运算为类，模拟计算图节点。
class MulLayer:
    def __init__(self):
        self.x = None
        self.y = None
    
    def forward(self,x,y):
        self.x = x
        self.y = y

        return x * y
    
    def backward(self, dout):
        dx = dout*self.y
        dy = dout*self.x

        return (dx, dy)

mul = MulLayer()
print(mul.forward(1,2))
print(mul.backward(1))

# 练习 4：代码实现 加法层（正向传播、反向传播）
class AddLayer:
    def __init__(self):
        pass
    
    def forward(self,x,y):
        self.x = x
        self.y = y

        return x + y
    
    def backward(self, dout):
        dx = dout*1
        dy = dout*1

        return (dx, dy)

add = AddLayer()
print(add.forward(1,2))
print(add.backward(1))


# 练习 9：代码实现组合运算 z = (x+y) *k，完整正向 + 反向
x,y,k = 1,2,3
m1 = MulLayer()
a1 = AddLayer()

# 前向传播
sum1 = a1.forward(x,y)
z = m1.forward(sum1, k)
print(z)

# 反向传播
dout = 1
dsum, dk= m1.backward(1)
dx, dy = a1.backward(dsum)
print(dk, dx, dy)