# 列表详解
# 1.索引
list = ['李白', '杜甫', '白居易', '陶渊明']
print(list[0], list[-1])

# 2. 追加 append()
list.append(5)
print(list)

# 3. 插入 insert()
list = ['李白', '杜甫', '白居易', '陶渊明']
list.insert(2, '自来也')
print(list)

# 4. extend()
list = ['李白', '杜甫', '白居易', '陶渊明']
l = ['鸣人', '佐助', '小樱', '我爱罗']
list.extend(l)
print(list)

list = ['李白', '杜甫', '白居易', '陶渊明']
for i in range(4):
    list.append(l[i])
print(list)


# 5. 删除
# ① del
list = ['李白', '杜甫', '白居易', '陶渊明']
del(list[2])
print(list)

# ② pop()   存在返回值
list = ['李白', '杜甫', '白居易', '陶渊明']
res = list.pop(3)
print(res, list)

# ③ remove()
list = ['李白', '杜甫', '白居易', '陶渊明']
list.remove('李白')
print(list)


# 6. 切片
list = ['李白', '杜甫', '白居易', '陶渊明']
print(list[1:3])

# 7. len()
list = ['李白', '杜甫', '白居易', '陶渊明']
print(len(list))

# 8. 循环
list = ['李白', '杜甫', '白居易', '陶渊明']
str = '12312'
for i in list:
    print(i)

# court()
list = ['李白', '杜甫', '白居易', '陶渊明']
print(list.count('李白'))

# index()
list = ['李白', '杜甫', '白居易', '陶渊明']
print(list.index('李白'))

# reverse()
list = ['李白', '杜甫', '白居易', '陶渊明']
print(list[::-1])
list.reverse()
print(list)

# sort()
list = ['a', 'v', 'c', 'b']
list.sort()
print(list)
list.sort(reverse = True)
print(list)



# 复习
#Python格式化输入输出
# 1. 格式化输入input()
# python2的提供raw_input与3的input()相同
# 2的input()会根据用户数入直接判断类型

# age = input('请输入年龄')
# print(age, type(age))
# age = int(age)
# print(age, type(age))

# 2. 格式化输出
# %
info = '姓名%s, 年龄%s'%('胖娃', '28')
print(info)

info = '姓名%(name)s, 年龄%(age)s'%{'name':'胖娃', 'age':'28'}
print(info)

# format()
info = '姓名{0},年龄{1}'.format('胖胖', '28')
print(info)

info = '姓名{name},年龄{age}'.format(name='胖胖', age='28')
print(info)

info = '{0:*^10}'.format('开始')
print(info)

# f
name = '胖娃'
age = 28
info = f'姓名{name},年龄{age}'
print(info)

dic = {'name' : '张大仙', 'age' : 84, 'height' : 200}
for i in dic:
    print(dic[i])       