# 二 文件复制
# 使用with---as结合open使用，可以自动释放内存，
# 不需要手动操作
# with open(r'D:\Learning\gitRepository\C_Code\Python\Learning\文件操作\[Stray]   2023-04-05 15_31_17.png','rb') as rstream:
#     r_container = rstream.read()
#     with open(r'./copy_png.png', 'wb') as wstream:
#         wstream.write(r_container)

# print("文件复制完成")

## 需求：将源文件保存在当前文件夹下(以同名+copy方式)
# 引入os模块
import os
# os.path:
# os.path.dirname(__file__)   # 获取当前文件所在的文件夹名称
# os.getcwd() # 同os.path.dirname()
# os.path.join(path,"")   # 返回一个拼接后的新路径
# os.path.isabe(path) # 判断当前路径是否为绝对路径
# os.path.abspath(file/__file__)  # 返回文件/当前文件的绝对路径

with open(r'D:\Learning\gitRepository\C_Code\Python\Learning\文件操作\[Stray]   2023-04-05 15_31_17.png', 'rb') as rstream:
    container = rstream.read()
    filename = rstream.name  # 获取流文件的文件名
    print(filename)
    pos = filename.rfind('\\')
    targetname = filename[pos+1::]
    print(targetname)
    pos = targetname.rfind('.')
    targetname = targetname[:pos:]
    targetname = targetname + 'copy.png'
    print(targetname)

    dir_path = os.path.dirname(__file__)
    tarpath = os.path.join(dir_path, targetname)
    with open(tarpath, 'wb') as wstream:
        wstream.write(container)

print("复制完成")



