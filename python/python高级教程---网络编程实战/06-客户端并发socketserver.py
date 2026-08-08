import socket

# 1. 创建socket对象
sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 客户端IP和端口不会写死，因此不需要绑定

# 2.建立连接
sk.connect(('127.0.0.1', 8086))

# 3. 传输数据
while True:
    msg = input("请输入>>>").strip()

    if not msg: # 解决数据为空的问题，造成缓存中无数据发往服务端，导致阻塞
        continue

    sk.send(msg.encode("utf-8"))
    if msg == 'q':
        break

    data = sk.recv(1024)
    print(data.decode("utf-8"))

# 4. 关闭连接(必须有)
sk.close()