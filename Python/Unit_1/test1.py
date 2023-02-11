# 1.python注释
# '''
# python注释的三种方法：
# ① #的单行注释
# ② ''' '''的多行注释（注：还可以为 """ """）
# '''

# 2. python基本语法：变量
# 变量三个组成部分：①变量名  ②赋值运算符 =  ③变量值（包括Id和type）其中id可以用id(变量名)
# type(变量名)查看
# 例如：
name = "胖胖"
age = 29
height = 1.68
print(id(name))
print(type(name))

## 关于is 和 == 
# is比较两变量的id是否相同
# == 比较两变量的值是否相通





## 3.python的垃圾回收机制（通过引用计数来实现）

## 引用计数增加
a = 100
b = a
c = a
# 此时100的引用计数为3

## 引用计数减少
del a
del b
c = 123
# 此时100的引用计数为0
# python的垃圾回收机制会一直扫描内存空间，删除引用计数为0的内存
