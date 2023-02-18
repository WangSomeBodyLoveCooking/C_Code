#coding=UTF-8
#格式化输入
#1. %
info1 = '我的名字是%s,我来自%s' %('王某人', '安徽')
print(info1)

info2 = '我的名字是%(name)s,我来自%(hometown)s' %{'name': '王某人','hometown':'安徽'}  # 字典
print(info2)

#%d接受一个整形
info3 = '身高%d'%(170)
print(info3)

# %传入的都是字符串格式
info4 = '这是一个字典%s'%{'name':123,'height':1870}
print(info4)

#2. format()
info5 = '我的名字是{0},我来自{1}'.format('王某人','安徽')
print(info5)

info6 = '我的名字是{name},我来自{hometown}'.format(name='王某人',hometown='安徽')
print(info6)

info7 = '这是一个字典{0}'.format({'name':'王某人'})
print(info7)

#格式化复制
info8 = '{0:*^10}'.format('王某人')
print(info8)

#f
name1 = input('请输入你的名字')
age = input('你的年龄是')
info9 = f'我的名字是{name1},我的年龄{age}'
print(info9)

