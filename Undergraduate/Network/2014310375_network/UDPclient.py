#using socket
from socket import *

#setting localhost and port number
serverNAme="127.0.0.1"
serverPort=12000
#setting client socket
clientSocket=socket(AF_INET,SOCK_DGRAM)
#get message from a user and send it to server socket
message=input("input lowercase sentence : ")
clientSocket.sendto(message.encode(),(serverNAme,serverPort))

#get returned message from the server side
modifiedMessage,serverAddress=clientSocket.recvfrom(2048)
#decoding it and print in string
print(modifiedMessage.decode())
#socket end, UDP protocol close
clientSocket.close()