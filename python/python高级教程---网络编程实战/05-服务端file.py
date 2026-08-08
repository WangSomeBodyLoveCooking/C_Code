import socket
import os
import hashlib
import json


def get_file_info(file):
    file_size = os.path.getsize(file)
    file_type = file.split('.')[1]
    file_md5 = calculate_small_file_md5(file)
    return file_size, file_type, file_md5

def calculate_small_file_md5(file_path):
    """
    计算小文件的 MD5 值
    :param file_path: 文件路径
    :return: 文件的 MD5 值
    """
    with open(file_path, 'rb') as f:
        data = f.read() # 一次性读取整个文件内容
    return hashlib.md5(data).hexdigest()

sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sk.bind(("127.0.0.1",8080))

sk.listen(5)

conn, addr = sk.accept()

while True:
    cmd = conn.recv(1024)

    if not cmd or cmd == 'q': break

    cmd = cmd.decode("utf-8")
    print(cmd)

    cmd_list = cmd.strip().split()
    cm = cmd_list[0]
    file = cmd_list[1]

    if cm == "get":
        # 获取文件
        # ①获取文件大小
        # ②获取文件类型
        # ③获取文件md5值
        file_size, file_type, file_md5 = get_file_info(file)
        header = {
            'file_size': file_size,
            'file_type': file_type,
            'file_md5': file_md5
        }

        header_str = json.dumps(header)

        head_header = str(len(header_str))
        print(head_header)
        head_header = bytes(head_header, 'utf-8').zfill(4)

        conn.send(head_header)
        conn.send(header_str.encode('utf-8'))

        with open (file, 'rb') as r:
            for i in r:
                conn.send(i)


