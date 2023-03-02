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
