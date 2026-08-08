import socket

sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sk.connect(('127.0.0.1', 8086))

while True:
    cmd = input("请输入指令：")
    if not cmd:continue
    
    sk.send(cmd.encode("utf-8"))
    if cmd == 'q':
        break

    data = sk.recv(8)

    data_size = int(data.decode("gbk"))
    print(data_size)

    cur_size = 0
    cur_data = b''
    while cur_size < data_size: # 解决粘包问题
        data = sk.recv(1024)
        cur_data += data

        cur_size+=len(data)
    
    print(cur_data.decode('gbk'))

sk.close()