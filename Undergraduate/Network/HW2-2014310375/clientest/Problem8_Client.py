from socket import *
import os
#check file existence
import sys

serverName="localhost"
serverPort=1234

#socket setting with ipv4 and tcp protocol
clientSocket=socket(AF_INET,SOCK_STREAM)
#connect to server using connect function
clientSocket.connect((serverName,serverPort))

requested = input("request file : ")
clientSocket.send(requested.encode())
answer=clientSocket.recv(1024)

dire=os.getcwd()

if answer.decode()=="NoFile":
    print("File does not exist")
    clientSocket.close()
    sys.exit()
else:
    with open(dire+"\\"+requested,'wb') as file:
        while 1:
            answer=clientSocket.recv(1024)
            
            if not answer:
                break

            file.write(answer)

clientSocket.close()
sys.exit("file transfer clear")
            