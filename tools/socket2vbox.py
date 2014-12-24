#!/bin/python
import sys,os
import time
from random import randint
import socket


def socketserver():
    HOST = ''     # Symbolic name meaning all available interfaces
    PORT = 20320          # OpenGazer default socket port
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(5)
    conn, addr = s.accept()
    print 'Connected by', addr
    while 1:
        data = conn.recv(1024)
        if not data: break
        send(data)
    conn.close()


def send(msg):
    cmd = "vboxmanage guestproperty set vb-win7 /opengazer/fix \"%s\""%msg 
    print cmd
    os.system(cmd)

def genCords():
    return randint(1,100),randint(1,100)

def serialize(cords):
    ts = time.time()
    return str(ts)+': '+str(cords[0])+','+str(cords[1])


socketserver()
