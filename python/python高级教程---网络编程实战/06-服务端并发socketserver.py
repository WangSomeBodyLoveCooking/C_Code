import socketserver

class RequestHandle(socketserver.BaseRequestHandler):
    def handle(self):
        print(self.request)     # self.request => conn
        print(self.client_address)      # self.client_address => addr

        # 5. 数据传输 (bytes类型) 若无数据发送，也会阻塞
        while True:
            try:
                data = self.request.recv(1024) #  1024:一次最多接受多少字节     注：服务端也可以先发送数据，这取决于你 conn.send()
            except:
                print("客户端异常退出")
                break   # window异常退出抛异常
        
            if not data:   # 注：空时为mac或Linux客户端强制退出
                break
        
            data = data.decode("utf-8")
            print("客户端发过来的数据：", data)
        
            self.request.send(data.upper().encode("utf-8"))
        
            # 6. 结束服务(回收操作系统资源)
        self.request.close()


# socketserver.ForkingTCPServer  这个只能在Linux上使用，因为调用os.fork()启动进程，windows不支持该方法
sk = socketserver.ThreadingTCPServer(('127.0.0.1', 8086), RequestHandle)
sk.serve_forever()
# == 
# while True:
    # conn, addr = sk.accept()
# 每获取到一个对象，起一个线程(conn, addr)，将连接对象在线程中提供服务
# 原理：每个线程都会创建一个RequestHandle对象，调用handle方法，获取连接对象和地址