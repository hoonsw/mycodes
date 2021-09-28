#import socket module
from socket import *
serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a server socket
serverSocket.bind(('',12000))
serverSocket.listen(1)
host, port = serverSocket.getsockname()

#information of this server
hostName='\n\n'+'server host name : '+gethostname()
IPaddress='\n'+'server IP address : '+gethostbyname(gethostname())+'\n'
filePath='file path is C:\\Users\\rhyth\\Desktop\\Project\\Code\\Python_Project\\2014310375_network\\requestedFile.html'
portNumber='\n'+'port number is : '+str(port)

while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept()
    try:
        message = connectionSocket.recv(2048)
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        f.close()

        #connectionSocket.send(filePath.encode())
        #Send one HTTP header line into socket
        connectionSocket.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
        #Send the content of the requested file to the client
        #send server information

        #connectionSocket.send(str(len(outputdata)).encode())

        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.send(hostName.encode())
        connectionSocket.send(IPaddress.encode())
        connectionSocket.send(filePath.encode())
        connectionSocket.send(portNumber.encode())
        connectionSocket.close()
        print("OK!")
    except IOError:
        #Send response message for file not found
        connectionSocket.send('\n404 Not Found\n'.encode())
        #Close client socket
        connectionSocket.close()
serverSocket.close()
