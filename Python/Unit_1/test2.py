#coding=UTF-8
# 4.字典类型（使用大括号{ }）
### 字典名 + '=' {'key名' ： key值}
dic = {
    'name' : '张大仙', 
    'age' : 73, 
    'height' : 180,
    'salary' : 180
    }

print(type(dic))

#字典取值：通用key来取值；而列表通过索引来取值
### 字典名['key名']
print(dic['name'])
print(dic['age'])

# 注：字典和列表可以混合使用
person = [
    {'name' : '张大仙', 'age' : 28, 'hobby' : ['打游戏']},
    {'name' : '胖胖', 'age' : 28, 'hobby' : ['吃', '睡', '玩']},
    {'name' : '王子祥', 'age' : 29, 'hobby' : ['学习', '睡觉']}
]

print(person[1]['hobby'][0])    # 吃
print(person[1]['age'])     # 28
print(id(person[1]['hobby'][0]))        # 56842256
print(type(person[1]['hobby'][0]))      # str




# 5.布尔类型bool
a = True;
b = False;
print(a)        # True
print(type(a))      # bool

c = None
print(type(c))      # NoneType