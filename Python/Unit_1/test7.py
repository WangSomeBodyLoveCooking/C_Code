# 1.python里的进制转换
# 十进制转二进制
print(bin(12))

# 十进制转八进制
print(oct(12))

# 十进制转十六进制
print(hex(12))

# 反过来
print(int('0b1100', 2))
print(int('0o14', 8))
print(int('0xc', 16))

# 2.string内置方法
# pythonh中创建string类型实际上调用了str()方法
# 如：str({'name' : '张大仙', 'age' : 12})

# 索引取值
info = 'good good study, day day up!'
print(info[0], info[-1])

# 切片
print(info[0:5])
print(info[:5])
print(info[5:])
print(info[0:5:2])
print(info[4:0:-1])
print(info[::-1])       # 字符串倒取

# strip( ) lstrip() rstrip()    去掉空格
info = '  ---!!! 张大仙 ---- !!!  '
print(info.strip('-  !'))
print(info.lstrip('- !'))
print(info.rstrip('- !'))


# split( )  rsplit( )   拆分字符串为list
info = '李白-杜甫-白居易-陶渊明'
print(info.split('-'), type(info.split('-')))
print(info.rsplit('-', 2))


# 长度len()
info = 'good!'
print(len(info))


# 成员运算in和not in
info = '胖胖的名字叫胖娃，她来自安徽省淮南市寿县'
print('胖娃' in info)


# lower() 和 upper()
info = 'AbncdFKLDNFVLSKAD'
print(info.lower())
print(info.upper())


# startswith()  endswith()
info = '胖娃子胖乎乎'
print(info.startswith('胖娃子'))



# join()    将列表连接为字符串（必须都是字符串形式）
list = ['1', '2', '网']
print('-'.join(list), type('-'.join(list)))



# replace()     将字符串中字符替换
info = '李白-杜甫-白居易-陶渊明'
res = info.replace('-', '#', 2)
print(res)

# isdigit()    判断字符串是否为纯数字
info = '321432'
print(info.isdigit())


# 练习: 输入账号，密码如果正确则进入系统

while 1:
    num1 = input('请输入账号')
    num2 = input('请输入密码')
    realNum1 = num1.strip()
    realNum2 = num2.strip()
    if realNum1.isdigit():
        if realNum1 == '1605255735' and realNum2 == 'wzx123456':
            print('登录成功')
            break
        else:
            print('账号或密码错误，请重新输入')
    else:
        print('输入的账号不是纯数字,请重新输入')    

# 注：python  if-else   if-elif-else   中间不能有空格，并且写完后需要加上 ':'号