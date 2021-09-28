#import socket module
from socket import *
#import thread
from _thread import *
import threading

def multithread(connectionSocket):
    while True:
            try:
                #file name requested from client
                message = connectionSocket.recv(1024).decode()
                filename = message.split()[1]
                #requested file open
                f = open(filename[1:])
                outputdata = f.read()
                f.close()
                #Send one HTTP header line into socket
                outputdata = 'HTTP/1.1 200 OK\r\n\r\n' + outputdata
                #Send the content of the requested file to the client
                for i in range(0, len(outputdata)):
                    connectionSocket.send(outputdata[i].encode())
                connectionSocket.close()
                print("OK!")
            except IOError:
                #Send response message for file not found
                outputdata = 'HTTP/1.1 404 Not Found\r\n\r\n'
                #Close client socket
                for i in range(0, len(outputdata)):
                    connectionSocket.send(outputdata[i].encode())
                connectionSocket.close()

def Main():
    serverSocket = socket(AF_INET, SOCK_STREAM)
    #Prepare a sever socket
    serverPort = 1234
    serverSocket.bind(("", serverPort))
    serverSocket.listen(5)
    while True:
        #Establish the connection
        print('Ready to serve...')
        connectionSocket, addr = serverSocket.accept()
        #start multithreading
        start_new_thread(multithread,(connectionSocket,))
    serverSocket.close()

if __name__ == '__main__':
    Main()