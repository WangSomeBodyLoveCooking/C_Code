import socket
import subprocess

sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sk.bind(('127.0.0.1', 8086))

sk.listen(5)

print("服务端已经启动，在8086端口监听")

while True:
    conn, addr = sk.accept()
    print(conn, addr)
    while True:
        try:
            data = conn.recv(1024)
        except:
            break
        if not data:break


        # 执行cmd命令
        cmd = data.decode("utf-8")

        res = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        out_res = res.stdout.read()
        err_res = res.stderr.read()

        data_size = len(out_res)+len(err_res)
        print(data_size)

        head = bytes(str(data_size), 'gbk').zfill(8)    # 先传头部，解决粘包
        print(head)

        conn.send(head)
        conn.send(out_res)
        conn.send(err_res)
      
    conn.close()

        