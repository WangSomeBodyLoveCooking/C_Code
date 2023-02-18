#coding=UTF-8
# 直接引用和间接引用
name = '张大仙'     # 直接引用
list= ['a', 'b', name]      # 间接引用
print(list[2])      # 张大仙
print(id(name))     # 54924800

print(id(list[2]))      # 54924800


# 变量的存储方式
# 整形、浮点、字符等类型都是直接引用存储
# 列表和字典是间接引用存储，存放的是值的地址

# 循环引用
l1 = ['a', 'b']
l2 = ['x', 'y']
# l1.append('c')
# print(l1)        # ['a', 'b', 'c']

l1.append(l2)        # ['a' , 'b', ['x', 'y']]
l2  is  l1[2]        # True

l2.append(l1)        # ['x', 'y', ['a', 'b', ['x', 'y']]]
l1 is l2[2]        # True
#这就构成了循环引用（相互引用关系）

del l1        # 相应列表的引用计数减1，但是l2还会引用该列表
del l2        # 相应列表的引用计数