# 一 文件操作
# 1.1 读文件
# 注：
# 1.文件没有找到，报错FileNotFoundError;`文件必须要是绝对路径`
# 2.文件读完后，文件指针会来到文件末尾；
# 3.如果是图片，则不能使用默认的读取方式，mode = "rb"
# 4.结束文件操作后，需要关闭流

# read()  # 读文件全部内容
# readable()  # 判断文件是否可读，返回布尔值
# readline()  # 按行的方式读取文件
# readlines() # 行方式读取文件，返回一个list
stream = open(R"D:\Learning\gitRepository\C_Code\Python\Learning\文件操作\test.txt", "rt")
isread = stream.readable()
print(isread)   # True

# readline = stream.readline()
# print(readline) # 这是文件练习的练习文档：

# readlines = stream.readlines()
# print(readlines)    # ['这是文件练习的练习文档：\n', '我爱Python']

container = stream.read()
print(container)
# 这是文件练习的练习文档：
# 我爱Python
stream.close()

# 1.2 写文件
# 写操作mode = "w" 该模式下写文件之前会首先清空文件内容

# writable()  # 判断当前文件是否可以写，返回布尔值
# write() # 向文件中写入文件内容，每次写入都会清空文件的内容
# writelines()    # 向文件中写入文件内容，入参为一个List，需要手动指定换行'\n'

# 注：如果不需要清空内容，以追加方式写入，则Mode = 'a'

wstream = open(R'D:\Learning\gitRepository\C_Code\Python\Learning\文件操作\test.txt','wt')
writable = wstream.writable()
print(writable)

container = wstream.write('这是文件练习的练习文档：\n 我爱Python,写文件')
print(container)    # 返回写入的字符数

container = wstream.writelines(['\nHello,\n', 'Worle'])
print(container)    # 返回None

wstream.close()

wstream = open(R'D:\Learning\gitRepository\C_Code\Python\Learning\文件操作\test.txt','a')
writable = wstream.writable()
print(writable)

container = wstream.write('这是文件练习的练习文档：\n 我爱Python,写文件')
print(container)    # 返回写入的字符数

container = wstream.writelines(['\nHello,\n', 'Worle'])
print(container)    # 返回None

wstream.close()
