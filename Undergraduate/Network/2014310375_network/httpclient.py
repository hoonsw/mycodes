#import socket
from socket import * 

#setting ip as localhost and port number
serverName="localhost"
serverPort=12000

#socket setting with IPv4 and TCP protocol
clientSocket=socket(AF_INET,SOCK_STREAM)
#connect to server using connect((server IP, port)) function
clientSocket.connect((serverName,serverPort))

#sending a GET request to the server
request = 'GET /requestedFile.html HTTP/1.1\r\n\r\n'
clientSocket.send(request.encode())
answer=clientSocket.recv(2048)
print(answer.decode())

#get server information and http request answer, and requested file(html)
answer1=clientSocket.recv(2048)
answer2=clientSocket.recv(2048)
answer3=clientSocket.recv(2048)

#print the return
print(answer1.decode())
print(answer2.decode())
print(answer3.decode())

#socket close
clientSocket.close()