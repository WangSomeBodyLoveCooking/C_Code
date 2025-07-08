#coding=gbk
from lib.common import log
def login():
    print('登录'.center(30, '*'))
    log("大仙登录了")

def recharge():
    print('充值'.center(30, '*'))
    log("大仙充值了100W")

def transfer():
    print('转账'.center(30, '*'))
    log('大仙给我转了100W')

dic = {
    '0' : ['退出', exit],
    '1' : ['登录', login],
    '2' : ['充值', recharge],
    '3' : ['转账', transfer]
}

def main():
    while 1:
        for key in dic:
            print(key, dic[key][0])
        
        opt = input('请输入选项').strip()
        if opt not in dic:
            print('\033[33m输入错误，请重新输入\033[0m')
        else:
            dic[opt][1]()
