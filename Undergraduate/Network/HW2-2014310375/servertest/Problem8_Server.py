from socket import *
import os
#check file existence
import sys

serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a sever socket
serverPort = 1234
serverSocket.bind(("", serverPort))
serverSocket.listen(1)

#make connection socket
connectionSocket, addr = serverSocket.accept()

#get file request from client
filename=connectionSocket.recv(1024).decode()

#check if file does not exist
if not os.path.exists('./'+filename):
    connectionSocket.send("NoFile".encode())
    sys.exit("file not exist")


#file transfer
#file read
file=open(filename,'rb')
#read file data
data=file.read(1024)
while(data):
    print('sending data')
    #sending data using connection socket
    connectionSocket.send(data)
    data=file.read(1024)
#file close
file.close()


#close socket and system out
connectionSocket.close()
sys.exit("file transfer completed")