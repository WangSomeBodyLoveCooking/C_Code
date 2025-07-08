#coding=utf-8
# from .core.core import main ³¬¶¥¼¶°ü
import sys
import os
BASE_PATH = os.path.dirname(os.path.dirname(__file__))
sys.path.append(BASE_PATH)
from core.core import main

if __name__ == '__main__':
    main()