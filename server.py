import socket
hostname = "TheoGeometric" #Put server hostname HERE
localIP     = socket.gethostbyname(hostname) # or server IP HERE
localPort   = 200
bufferSize  = 1024
msgFromServer   = "Hello UDP Client"
bytesToSend   = str.encode(msgFromServer)

# Create a datagram socket
UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
# Bind to address and ip
UDPServerSocket.bind((localIP, localPort))
print("UDP server up and listening")
# Listen for incoming datagrams

save = open("sample.txt", "a+")
UDPServerSocket.settimeout(8)
while(True):
    try:
        bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
        message = bytesAddressPair[0]
        address = bytesAddressPair[1]
        data = message.decode("utf-8")
        if (data != "" and data != " " and data != None):
            print("\r" + data + "                 ", end="")
            save.write(data + "\n")
        # Sending a reply to client
        UDPServerSocket.sendto(bytesToSend, address)
    except socket.timeout:
        print("\nTime OUT")
        break
    
    
save.close()

