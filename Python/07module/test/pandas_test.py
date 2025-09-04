#coding=utf-8
import pandas as pd
f1 = pd.read_csv('data2.csv')   # 读取csv文件read_csv()
print(f1.head())   # 查看前几行数据
print(f1.shape)    # 查看数据的形状（返回行数、列数）
print(f1.columns)  # 查看列名列表
print(f1.index)    # 查看索引列
print(f1.dtypes)    # 查看索引列
