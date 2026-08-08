import socket

# 1. 创建socket对象（基于网络的套接字家族，使用了流式协议）
sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   #流式协议（TCP协议）注：socket.SOCK_DGRAM为UDP协议

# 2. 绑定地址
## 注意ip地址的输入：
## 若输入局域网的Ip地址，则只允许本局域网内设备的客户端访问该服务端；
## 若输入本机回环地址127.0.0.1，则只允许本机设备的客户端访问该服务端（局域网其他主机无法访问）；
## 若输入0.0.0.0（代表本机IP地址），则认为服务端地址为本机所拥有的任意ip（公网或局域网），即客户端访问本机任意IP都可以；
## 若想跨局域网通信，则服务端地址需要设置为公网IP；

## 端口范围：0~65535 ---- 1024之前的端口为系统保留，尽量不要使用
# sk.bind(('192.168.0.164', 8086))
sk.bind(('127.0.0.1', 8086))

# 3. 监听连接请求（开始营业）
sk.listen(5)    # 5:半连接池大小
print("服务端启动成功，在8086端口等待客户端连接")

# 4. 取出连接请求，开始服务
while True: # 能循环依次为多个客户端服务（但不是并发）
    conn, addr = sk.accept() # 返回一个元素（连接对象，客户端地址）；若无客户端连接进来，则代码会阻塞在这

    print("连接对象：", conn)
    print("客户端IP+端口", addr)

    # 5. 数据传输 (bytes类型) 若无数据发送，也会阻塞
    while True:
        try:
            data = conn.recv(1024) #  1024:一次最多接受多少字节     注：服务端也可以先发送数据，这取决于你 conn.send()
        except:
            print("客户端异常退出")
            break   # window异常退出抛异常

        if not data:   # 注：空时为mac或Linux客户端强制退出
            break

        data = data.decode("utf-8")
        print("客户端发过来的数据：", data)


        conn.send(data.upper().encode("utf-8"))


    # 6. 结束服务(回收操作系统资源)
    conn.close()

# sk.close() # 关闭服务端，一般不会操作