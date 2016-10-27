from socket import *
import time 
	

host = "128.193.54.182"
port =5000

clients = []
s = socket(AF_INET, SOCK_STREAM)
s.bind((host,port))
s.listen(1)

conn, addr = s.accept()
print "Connected by" , addr

i = True

while True : 
	data = conn.recv(1024)
	print " Received ", repr(data)
	reply = raw_input("Reply : ")
	conn.sendall(reply)
	
conn.close()


