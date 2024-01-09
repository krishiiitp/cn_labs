import socket
host = '127.0.0.1'
port = 55555
SIZE = 1024
FORMAT = "utf-8"
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()
clients = []
nicknames = []
def broadcast(message):
    for client in clients:
        client.send(message)
def accept(client):
    try:
        filename = client.recv(SIZE).decode(FORMAT)
        file = open(filename, "r")
        lines = len(file.readlines())
        words = len(file.read().split())
        client.send("Filename received.".encode(FORMAT))
        print(f"[SEND] Sending the file data.")
        file.seek(0)
        lst = file.readlines()
        s = "\n"
        for line in lst: s += line
        print(f"The number of words are {len(s.split())} and the lines are {lines} ")

        print(f"The lines requested are: {s}")
        client.send(s.encode(FORMAT))
        file.close()
        print("Enter 1 if you want to append something to file: ")
        x = input()
        if(x == '1'):
            xx = input("Enter the string you wish to append: ")
            with open(filename, 'a') as f:
                f.write(f"\n{xx}")
        
        client.close()
    except:
        print("error")
def receive():
    while True:
        client, address = server.accept()
        print("Connected with {}".format(str(address)))
        accept(client)

receive()