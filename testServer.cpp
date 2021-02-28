#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

string task = "";

string calculate(string str) {
	if (task == "ADD" || task == "SUB" || task == "MUL" || task == "DIV" || task == "MOD")	{
		string a = "0", b = "0";
		int temp = 0;
		for (int i = 3; i < str.length(); i++) {
			if (str[i] == ',') temp = str.length();
			else {
				if (temp < i) {
					a += str[i];
				}
				if (temp > i) b += str[i];
			}
		}
		stringstream aa(a), bb(b);
		long long int num, num1, num2;
		aa >> num1;
		bb >> num2;
		string ans;
		if (task == "DIV" && num2 == 0 || task == "MOD" && num2 == 0) ans = "NOT-DEFINED";
		else {
			if (task == "ADD") num = num1 + num2;
			if (task == "SUB") num = num1 - num2;
			if (task == "MUL") num = num1 * num2;
			if (task == "DIV") num = num1 / num2;
			if (task == "MOD") num = num1 % num2;
			ans = to_string(num);
		}
		return ans;
	}
	else return str;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Missing port number" << endl;
		exit(0);
	}
	int port = atoi(argv[1]);
	char message[1500];

	// define a socketaddr_in struct for server socket (the socket listening)
	sockaddr_in serverSocket;

	// bzero((char *)&serverSocket, sizeof(serverSocket));
	serverSocket.sin_family = AF_INET;
	serverSocket.sin_port = htons(port);
	serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);

	// socket() for server socket
	// int socketID = socket (Family, Type, Protocol)
	int serverSocketID = socket(AF_INET, SOCK_STREAM, 0);

	if (serverSocketID < 0) {
		cerr << "Not successful" << endl;
		exit(0);
	}

	// bind() the socket to a port
	// int status = bind(socketID, &addressPort, sizeOfPort)
	int bindStatus = bind(serverSocketID, (struct sockaddr *) &serverSocket, sizeof(serverSocket));

	if (bindStatus < 0)	{
		cerr << "Not successful bind" << endl;
		exit(0);
	}

	cout << "Waiting for client to connect...\n";

	// listen() for any incoming communication
	// int status = listen(socketID, queueLimit)
	listen(serverSocketID, 1);

	// define a sockaddr_in struct for the connection socket (the socket sending and receiving data)
	sockaddr_in newSocket;
	socklen_t newSocketLen = sizeof(newSocket);

	// accept() the connection
	// int newID = accept(socketID, &clientAddress, &addressLen)
	int newSocketID = accept(serverSocketID, (sockaddr *) &newSocket, &newSocketLen);

	if (newSocketID < 0) {
		cerr << "Not successful accept()" << endl;
		exit(0);
	}

	cout << "Client connected successfully" << endl;

	// send() and recv() bytes
	// int data = send(socketID, MSG, MSGLen, flags)
	// int data = recv(socketID, recvBuf, buflen, flags)

	while (1) {
		task = "";
		string data;
		cout << "Waiting for a message from client" << endl;
		recv(newSocketID, (char *)&message, sizeof(message), 0);
		if (!strcmp(message, "exit")) {
			cout << "Session terminated";
			break;
		}
		for (int i = 0; i < 3; ++i) {
			task += message[i];
		}
		if (task == "ADD" || task == "SUB" || task == "MUL" || task == "DIV" || task == "MOD") {
			data = calculate(message);
		}
		else {
			cout << message << endl;
			cin >> data;
		}
		strcpy(message, data.c_str());
		if (data == "exit") {
			cout << "Session terminated";
			break;
		}
		send(newSocketID, (char *) &message, sizeof(message), 0);
	}

	// close() the socket
	// int status = close(socketID)
	close(newSocketID);
	close(serverSocketID);
}