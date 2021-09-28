#using socket
from socket import *

#setting port number
serverPort=12000
#setting socket as IPv4, UDP protocol
serverSocket = socket(AF_INET,SOCK_DGRAM)
#connect socket with the port
serverSocket.bind(('',serverPort))
#check if server is ready
print("the server is ready to receive")

try:
    while True:
        #no need to make connection socket because of UDP
        message, clientAddress = serverSocket.recvfrom(2048)
        #get byte message and decode to string and make it upper case
        modifiedMessage=message.decode().upper()
        #return the modified message to client by encoding to byte
        serverSocket.sendto(modifiedMessage.encode(),clientAddress)
except KeyboardInterrupt:
    print("press Ctrl-C to terminate while statement")
    pass