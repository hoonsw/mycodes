#using socket
from socket import *

#setting localhost and port number
serverName="127.0.0.1"
serverPort=12000

#setting socket as IPv4 and TCP protocol
clientSocket=socket(AF_INET,SOCK_STREAM)
#making connect to server
clientSocket.connect((serverName,serverPort))

#get string from a user
message=input("")

#send the string to the chat server with byte encoding 
clientSocket.send(message.encode())
#return the number of characters and reversed string information
answerMessage=clientSocket.recv(2048)
#print the string after decoding
print(answerMessage.decode())
#socket close
clientSocket.close()