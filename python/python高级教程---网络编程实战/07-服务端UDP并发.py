import socketserver

class RequestHandle(socketserver.BaseRequestHandler):
    def handle(self):
        print(self.request)
        print(self.client_address)


        # self.request[0] # 客户端发来的内容
        # self.request[1] # 客户端socker 对象

        self.request[1].sendto(self.request[0].upper(), self.client_address)
        print((self.request[0].upper()))


sk = socketserver.ThreadingUDPServer(('127.0.0.1', 8086), RequestHandle)
sk.serve_forever()
