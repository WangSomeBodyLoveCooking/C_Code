#coding=utf-8
import time
from conf.setting import LOG_PATH
def log(msg):
    with open(LOG_PATH , mode='at', encoding='utf-8') as w:
        w.write(f'{time.strftime("%Y-%m-%d %H:%M:%S")}{msg}\n')
