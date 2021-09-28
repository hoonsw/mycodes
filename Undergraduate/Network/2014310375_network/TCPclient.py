#using socket
from socket import *

#setting ip as localhost and port number
serverName="127.0.0.1"
serverPort=12000

#socket setting with IPv4 and TCP protocol
clientSocket=socket(AF_INET,SOCK_STREAM)
#connect to server using connect((server IP, port)) function
clientSocket.connect((serverName,serverPort))

#get message from terminal 
message=input("input lowercase sentence : ")

#sending the message to the server with encoding
clientSocket.send(message.encode())
#get modified message from the server within 2048 bytes
modifiedMessage=clientSocket.recv(2048)
#print the modified message
print(modifiedMessage.decode())
#socket close
clientSocket.close()