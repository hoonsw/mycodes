#using socket
from socket import *

#decide a port to communicate
#socket communication using IPv4 and TCP protocol
serverPort=12000
serverSocket=socket(AF_INET,SOCK_STREAM)

# connect socket and port using bind function
serverSocket.bind(('',serverPort))
# allow only one connection
serverSocket.listen(1)
# if successful, print that the server is ready
print('The server is ready to receive')

try:
    while True:
        #accept() returns tuple of (socket, address)
        connectionSocket, clientAddress=serverSocket.accept()
        #get information from connected socket until 2048 bytes
        message=connectionSocket.recv(2048)
        #message is byte code. so decoding and making it upper case
        modifiedMessage=message.decode().upper()
        #sending upper cased message to connection socket.
        connectionSocket.send(modifiedMessage.encode())
        #socket close
        connectionSocket.close()
except KeyboardInterrupt:
    print("pree Ctrl-C to termincate while statement")
    pass