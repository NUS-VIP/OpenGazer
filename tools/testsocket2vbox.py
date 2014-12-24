# Echo client program
import socket
from random import randint

HOST = '127.0.0.1'    # The remote host
PORT = 20320              # The same port as used by the server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
count = 1000

def genCords():
    return str(randint(1,100))+','+str(randint(1,100))+'\n'

while count :
    s.send(genCords())
    count -= 1

s.close()
