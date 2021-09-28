from socket import *
import os
#check file existence
import sys

#setting socket
serverName="localhost"
serverPort=1234

#socket setting with ipv4 and tcp protocol
clientSocket=socket(AF_INET,SOCK_STREAM)
#connect to server using connect function
clientSocket.connect((serverName,serverPort))

#get requested file name from user
requested = input("request file : ")
#send the name after encoding
clientSocket.send(requested.encode())
#get back request 
answer=clientSocket.recv(1024)

#take now directory value
dire=os.getcwd()

#if there is no file with that name
if answer.decode()=="NoFile":
    print("File does not exist")
    #socket close
    clientSocket.close()
    #system close
    sys.exit()
else:
    #get file from the server
    with open(dire+"\\"+requested,'wb') as file:
        while 1:
            answer=clientSocket.recv(1024)
            # no request then break
            if not answer:
                break
            #make file
            file.write(answer)
#close socket
clientSocket.close()
sys.exit("file transfer clear")
            