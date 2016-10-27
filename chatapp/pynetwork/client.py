from socket import *
s = socket(AF_INET, SOCK_STREAM)
s.connect(("128.193.54.182",6000))

while True:
	message = raw_input("Your Message");
	s.send(message)
	print "Getting reply"
	reply = s.recv(1024)
	print "Received" , repr(reply)
		


s.close()
