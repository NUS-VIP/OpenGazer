import socket
from subprocess import PIPE,Popen
import subprocess
import time
from struct import *

def get():
    cmd = "VBoxControl --nologo guestproperty wait /opengazer/fix"
    os.system(cmd)

class VBox2Socket:

    def __init__(self):
        pass
    
    def startSocketServer(self):
        HOST = ''     # Symbolic name meaning all available interfaces
        PORT = 20320          # OpenGazer default socket port
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((HOST, PORT))
        s.listen(1)
        conn, addr = s.accept()
        print 'Connected by', addr
        self.conn = conn
        self.client = addr
        self.sock = s

    def stopSocketServer(self):
        self.conn.close()

    def send(self):
        x,y = self.get2()
        data = pack('ii',x,y)
        #print calcsize('ii') #8 bytes
        self.conn.send(data)

    def send2(self):
        self.conn.send("hello")
        
    def get2(self):
        p = Popen(['VBoxControl','--nologo','guestproperty','wait','/opengazer/fix'],stdout=PIPE)
        out,err = p.communicate()
        return self.parseOutput(out)
        #print "err=",err

    def parseOutput(self,value):
        value = value.split()[3]
        #print "value=",value
        if not (value.strip()):
            return
        cordlst = value.split(';')
        for cord in cordlst[0:-1]:
            try :
                x,y=cord.split(',')
                print 'got cords:('+x+','+y+')'
                return eval(x),eval(y)
            except :
                print cord
                print 'broken cords'

vbs = VBox2Socket()
vbs.startSocketServer()
while True:
    vbs.send()
vbs.stopSocketServer()

    
    

