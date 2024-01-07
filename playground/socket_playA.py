import socket

# 创建本地套接字
server_socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

# 绑定地址
server_address = "/tmp/my_local_socket"
server_socket.bind(server_address)

# 监听连接
server_socket.listen(1)

print("等待连接...")

# 接受连接
client_socket, client_address = server_socket.accept()
print("已连接：", client_address)

# 发送数据
while True:

    message = "from Process A: "
    msg = input("> ")
    if msg == "quit":
        break
    client_socket.send(message.encode())
    client_socket.send(msg.encode())


# 关闭套接字
client_socket.close()
server_socket.close()
