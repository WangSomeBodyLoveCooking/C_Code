import socket
import os
import hashlib
import json

sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sk.connect(("127.0.0.1",8080))

while True:
    cmd = input("请输入指令：")
    if not cmd: continue

    sk.send(cmd.encode('utf-8'))

    if cmd == 'q':break

    head_header = sk.recv(4)
    head_header = int(head_header.decode('utf-8'))
    print(head_header)


    cur_head_size = 0
    cur_head = b''
    while cur_head_size < head_header:
        head = sk.recv(1024)
        cur_head += head
        cur_head_size += len(head)

    cur_head = cur_head.decode('utf-8')
    print(cur_head)
    cur_head = json.loads(cur_head)

    # 将服务端传的文件保存到文件中
    cur_file_size = 0
    file_size = cur_head['file_size']
    file_type = cur_head['file_type']
    file_md5 = cur_head['file_md5']

    with open ('file'+'.'+file_type, 'wb') as w:
        while cur_file_size < file_size:
            file = sk.recv(1024)
            cur_file_size += len(file)
            w.write(file)



