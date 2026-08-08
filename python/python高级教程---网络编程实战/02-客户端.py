import socket

# 1. 创建socket对象
sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 客户端IP和端口不会写死，因此不需要绑定

# 2.建立连接
sk.connect(('127.0.0.1', 8086))

# 3. 传输数据
while True:
    msg = input("请输入>>>").strip()

    if msg == 'q':
        break

    sk.sendto(msg.encode("utf-8"), ('127.0.0.1', 8086))

    data, addr = sk.recvfrom(1024)
    print(data.decode("utf-8"))

# 4. 关闭连接(必须有)
sk.close()