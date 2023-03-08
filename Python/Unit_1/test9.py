# 字典
# 字典的定义方法
# 1.
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
print(dict1)
# 2.
dict2 = dict({'name' : 1, 'age' : 2, 'height' : 3})
print(dict2)
# 3.
dict3 = dict(name = 1, age = 2, height = 3)
print(dict3)
# 4. 字典的值全为None
list = ['name', 'age', 'height']
dict4 = {}
for key in list:
    dict4[key] = None
print(dict4)

dict5 = {}.fromkeys(list)
print(dict5)

# 字典的类型转换    必须成对出现
list = [['name', 12], ['age', 12]]
res = dict(list)
print(res)

# 字典的基本方法
# 增
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
dict1['f'] = 4
print(dict1)
# print(dict['e'])    #报错
print(dict1.get('e'))   # none

# 删
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
del(dict1['name'])
print(dict1)

dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
print(dict1.pop('name'))
print(dict1)

dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
print(dict1.popitem())
# print(dict1.popitem('name'))        # 报错
print(dict1)

dict1.clear()
print(dict1)

# 改
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
dict2 = {'a' : 1, 'b' : 2, 'height' : 4}
dict1.update(dict2)
print(dict1)

dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
dict1.setdefault('a')
print(dict1)

# 查
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
print(dict1['name'])

print(len(dict1))

# in  or  not  in

# keys   values    items
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
print(dict1.keys())
print(dict1.values())
print(dict1.items())

for key in dict1.keys():
    print(key)


for value in dict1.values():
    print(value)


for item in dict1.items():
    print(item)

# 解压赋值
res = ('站大仙', 12)
name, age = res
print(name, age)

#####
dict1 = {'name' : 1, 'age' : 2, 'height' : 3}
for key, value in dict1.items():
    print(key,value)



