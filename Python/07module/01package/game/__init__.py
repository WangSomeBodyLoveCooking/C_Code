#coding=utf-8
# 绝对导入
# from game.charge import charge
# from game.chat import chat
# from game.map import map
# from game.gg.name.namegg import namegg

# 相对导入（不能超过顶级包目录，如game模块不能超过game目录）
# .:__init__.py文件同级
# ..：上级
from .charge import charge
from .chat import chat
from .map import map 
from .gg.name.namegg import namegg