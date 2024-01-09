import socket
nickname = input("Choose your name: ")
host = '127.0.0.1'
port = 55555
SIZE = 1024
FORMAT = "utf-8"
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 55555))
def receive():
    x = input("Enter file name: ")
    try:
        file = open(x, "r")
        data = file.read()
        client.send(x.encode(FORMAT))
        msg = client.recv(SIZE).decode(FORMAT)
        print(f"[SERVER]: {msg}")
        client.send(data.encode(FORMAT))
        msg = client.recv(SIZE).decode(FORMAT)
        print(f"[SERVER]: {msg}")
        file.close()
        print(f"[SERVER]: Connection is now being closed.".encode(FORMAT))
    except:
        print("[SERVER]: error/ File does not exist. ")
    client.close()
receive()
