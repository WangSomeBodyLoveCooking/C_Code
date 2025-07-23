#coding=utf-8
import os
# 以下所有操作都在os.getcwd()路径下，可为绝对和相对路径
print(os.getcwd()) #获取当前工程的文件夹目录(vscode的打开工程)
os.chdir('./07module/05os') # 将getcwd结果移动到目标文件夹
print(os.getcwd()) #获取当前工程的文件夹目录(vscode的打开工程)
print(os.listdir('.'))
os.mkdir('test')    # 在路径下创建文件夹
# os.makedirs(r'test1\test2\test3')
# d:\Learning\gitRepository\C_Code\Python
# d:\Learning\gitRepository\C_Code\Python\07module\05os
# ['os.py']

# os.remove('test/123') #删除一个文件
os.rmdir('test')  #删除单级空目录，若目录不为空则无法删除，报错
os.system('tree')   # 执行终端命令
# 卷 Data 的文件夹 PATH 列表
# 卷序列号为 0E3E-7A4E
# D:.
# └─test1
#     └─test2
#         └─test3

print(os.environ) # 获取环境变量的值（返回字典）
print(os.environ.get('ORIGINAL_XDG_CURRENT_DESKTOP'))    # 获取环境变量key的值
print(os.getenv('ORIGINAL_XDG_CURRENT_DESKTOP')) # 作用同上
# {'ORIGINAL_XDG_CURRENT_DESKTOP': 'undefined', 'TMP': 'C:\\Users\\WZX\\AppData\\Local\\Temp', 'COMPUTERNAME': 'LAPTOP-QI9VLRRL', 'USERDOMAIN': 'LAPTOP-QI9VLRRL', 'PSMODULEPATH': 'C:\\Program Files\\WindowsPowerShell\\Modules;C:\\Windows\\system32\\WindowsPowerShell\\v1.0\\Modules', 'COMMONPROGRAMFILES': 'C:\\Program Files\\Common Files', 'ZXVE_NEW_UDS': '0x00000001', 'PROCESSOR_IDENTIFIER': 'Intel64 Family 6 Model 141 Stepping 1, GenuineIntel', 'PROGRAMFILES': 'C:\\Program Files', 'PROCESSOR_REVISION': '8d01', 'PATH': 'C:\\Windows\\system32;C:\\Windows;C:\\Windows\\System32\\Wbem;C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\;C:\\Windows\\System32\\OpenSSH\\;C:\\Program Files (x86)\\NVIDIA Corporation\\PhysX\\Common;C:\\Program Files\\NVIDIA Corporation\\NVIDIA NvDLISR;D:\\Program Files\\Git\\cmd;C:\\Program Files (x86)\\mingw64\\bin;D:\\AllDownload\\ChromeDownLoad\\Cmake\\cmake-3.24.2-windows-x86_64\\bin;D:\\Python27;D:\\Python37;D:\\Python37\\Scripts;D:\\Python27\\Scripts;D:\\software\\Vim\\vim91;C:\\Users\\WZX\\.cargo\\bin;C:\\Users\\WZX\\AppData\\Local\\Microsoft\\WindowsApps;D:\\Microsoft VS Code\\bin;D:\\software\\PyCharm 2019.3.3\\bin', 'SYSTEMROOT': 'C:\\Windows', 'VSCODE_IPC_HOOK': '\\\\.\\pipe\\20bf4656af073820efa0864f04b47808-1.74.0-main-sock', 'VSCODE_HANDLES_UNCAUGHT_ERRORS': 'true', 'PROGRAMFILES(X86)': 'C:\\Program Files (x86)', 'DRIVERDATA': 'C:\\Windows\\System32\\Drivers\\DriverData', 'TEMP': 'C:\\Users\\WZX\\AppData\\Local\\Temp', 'APPLICATION_INSIGHTS_NO_DIAGNOSTIC_CHANNEL': 'true', 'COMMONPROGRAMFILES(X86)': 'C:\\Program Files (x86)\\Common Files', 'VSCODE_CWD': 'D:\\Microsoft VS Code', 'PROCESSOR_ARCHITECTURE': 'AMD64', 'PATHEXT': '.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC', 'ALLUSERSPROFILE': 'C:\\ProgramData', 'VSCODE_CODE_CACHE_PATH': 'C:\\Users\\WZX\\AppData\\Roaming\\Code\\CachedData\\5235c6bb189b60b01b1f49062f4ffa42384f8c91', 'LOCALAPPDATA': 'C:\\Users\\WZX\\AppData\\Local', 'HOMEPATH': '\\Users\\WZX', 'USERDOMAIN_ROAMINGPROFILE': 'LAPTOP-QI9VLRRL', 'PROGRAMW6432': 'C:\\Program Files', 'USERNAME': 'WZX', 'LOGONSERVER': '\\\\LAPTOP-QI9VLRRL', 'PROMPT': '$P$G', 'COMSPEC': 'C:\\Windows\\system32\\cmd.exe', 'PROGRAMDATA': 'C:\\ProgramData', 'ONEDRIVE': 'C:\\Users\\WZX\\OneDrive', 'ZXVE_CLIENT_AGENT_UUID': '65698842-4E1D-4A32-B493-0C31166CE289', 'ZES_ENABLE_SYSMAN': '1', 'PYCHARM': 'D:\\software\\PyCharm 2019.3.3\\bin;', 'VSCODE_AMD_ENTRYPOINT': 'vs/workbench/api/node/extensionHostProcess', 'WINDIR': 'C:\\Windows', 'VSCODE_PID': '21296', 'CHROME_CRASHPAD_PIPE_NAME': '\\\\.\\pipe\\LOCAL\\crashpad_21296_WAEALBBKSKHZFPXB', 'APPDATA': 'C:\\Users\\WZX\\AppData\\Roaming', 'HOMEDRIVE': 'C:', 'OS': 'Windows_NT', 'SYSTEMDRIVE': 'C:', 'ZXVE_IRAI': 'C:\\Program Files (x86)\\uSmartView\\client\\uSmartView.exe', 'NUMBER_OF_PROCESSORS': '16', 'PROCESSOR_LEVEL': '6', 'VSCODE_NLS_CONFIG': '{"locale":"zh-cn","availableLanguages":{"*":"zh-cn"},"_languagePackId":"f45d28db2b892ef5d3a7efebc519f640.zh-cn","_translationsConfigFile":"C:\\\\Users\\\\WZX\\\\AppData\\\\Roaming\\\\Code\\\\clp\\\\f45d28db2b892ef5d3a7efebc519f640.zh-cn\\\\tcf.json","_cacheRoot":"C:\\\\Users\\\\WZX\\\\AppData\\\\Roaming\\\\Code\\\\clp\\\\f45d28db2b892ef5d3a7efebc519f640.zh-cn","_resolvedLanguagePackCoreLocation":"C:\\\\Users\\\\WZX\\\\AppData\\\\Roaming\\\\Code\\\\clp\\\\f45d28db2b892ef5d3a7efebc519f640.zh-cn\\\\5235c6bb189b60b01b1f49062f4ffa42384f8c91","_corruptedFile":"C:\\\\Users\\\\WZX\\\\AppData\\\\Roaming\\\\Code\\\\clp\\\\f45d28db2b892ef5d3a7efebc519f640.zh-cn\\\\corrupted.info","_languagePackSupport":true}', 'COMMONPROGRAMW6432': 'C:\\Program Files\\Common Files', '__COMPAT_LAYER': 'RunAsAdmin', 'PUBLIC': 'C:\\Users\\Public', 'ELECTRON_RUN_AS_NODE': '1', 'USERPROFILE': 'C:\\Users\\WZX'}
# undefined
# undefined

print(os.stat(r'./os.py'))
# nt.stat_result(st_mode=33206, st_ino=0L, st_dev=0L, st_nlink=0, st_uid=0, st_gid=0, st_size=1075L, st_atime=1752321822L, st_mtime=1752321822L, st_ctime=1752158128L)
# st_atime---上次访问时间, st_mtime=上次修改时间, st_ctime=创建时间(wind)
print(os.stat(r'./os.py').st_atime) # 为时间戳格式

print(os.name)    # 返回系统类型
#nt(windows)    posix(Linux)

print(os.path.split(r'D:\Learning\gitRepository\C_Code\Python\07module\05os\os.py'))  # 返回一个元组，该元组包含两部分，一部分是路径尾，一部分是路径尾前面的路径
# ('D:\\Learning\\gitRepository\\C_Code\\Python\\07module\\05os', 'os.py')

print(os.path.dirname(r'D:\Learning\gitRepository\C_Code\Python\07module\05os\os.py')) # 返回父级路径，其实就是os.pyth.split()的第一个元素
print(os.path.basename(r'D:\Learning\gitRepository\C_Code\Python\07module\05os\os.py')) # 与os.pyth.dirname()相反，其实就是os.pyth.split的第二个元素

# 练习：计算文件夹的大小