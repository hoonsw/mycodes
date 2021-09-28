#using socket
from socket import *

#setting port number and socket with IPv4, TCP protocol
serverPort=12000
serverSocket=socket(AF_INET,SOCK_STREAM)

#connecting socket with port and get one client
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
#ready to start chat server
print('chat server ready')

try:
    while True:
        #making connect with client
        connectionSocket, clientAddress=serverSocket.accept()
        #receive message from client
        message=connectionSocket.recv(2048)
        #decoding the message and store the length of the string using len() 
        numofString=len(message.decode())
        #string of the number of characters
        counting="The number of characters: {}".format(numofString)

        #reverse the message from the client
        reversedMessage=message.decode()[::-1]
        #string of the reversed message
        reverseofString="The reversed string(s): \""+reversedMessage+"\""
        #combine all these strings together 
        answerMessage=counting+"\n"+reverseofString
        #return the answerMessage to the chat client
        connectionSocket.send(answerMessage.encode())
        #socket close
        connectionSocket.close()
    
except KeyboardInterrupt:
    print("press Ctrl-C to termincate while statement")
    pass