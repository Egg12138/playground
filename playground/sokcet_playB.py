import socket

# 创建本地套接字
client_socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

# 连接到服务器
server_address = "/tmp/my_local_socket"
client_socket.connect(server_address)

# 接收数据
while True:
    data = client_socket.recv(1024)
    message = data.decode()
    print("rx: ", message)

# 关闭套接字
client_socket.close()
