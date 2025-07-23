#coding=utf-8

import sys
print(sys.argv)
old_file = sys.argv[1]
new_file = sys.argv[2]

with open(old_file, mode='rt', encoding='utf-8') as f, open(new_file, mode='rt', encoding='utf-8') as w:
    w.write(f.read())
