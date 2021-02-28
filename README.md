# Introduction

This project aims to establish client-server communication over a network using Transmission Control Protocol/Internet Protocol (TCP/IP). The connection between client and server is established and maintained until the application programs at each end have finished exchanging messages by giving the "exit" command. The protocol uses segments (packets) as the basic units of data transmission, hence socket programming was implemented in C++ in this project.

This project was completed under the guidance of ACM Student Chapter - IIT Roorkee. Here as client we can send words/phrases (without spaces) to the server and the same can be sent from the server to the client. But there were additions done at my end. The client can seek answers from the server regarding some mathematical calculations mainly addition, subtraction, multiplication, division and modulus of integers.

For adding 3 and 4: `ADD3,4`    
For subtracting 6 and 2: `SUB6,2`    
For multiplying 5 and 3: `MUL5,3`    
For dividing 60 and 4: `DIV60,4`    
For finding 22 modulus 5: `MOD22,5`    

Note - If one of the numbers is missing (like `ADD,4`) then the missing number will be treated as 0. The answer is NOT-DEFINED if any number is divided by 0.

# Running on Linux
Go to the directory in which testServer.cpp and testClient.cpp are present and compile the codes using g++ command.  
```
g++ testServer.cpp -o server.out
g++ testClient.cpp -o client.out
```  
Now open two different terminals, one for the server and one for the client. It is important to first run the server code so that the client can connect to the desired server. We need to provide a port number as argument, here we are choosing port number as 2000. We will be connecting on localhost, that is on the computer itself.

### On server side
`./server.out 2000`

### On client side
`./client.out localhost 2000`

Once it shows "Successful connection", the client and server can communicate with each other.


![ClientServerProject](https://user-images.githubusercontent.com/70306618/109429881-4fbb0500-7a24-11eb-86c8-accdc9f6881b.png)

# Further Improvements

Currently the features added work for integers only, this may be improved to work for floating point numbers too. Also other new features can be added on the server side which may assist the client side, like storing and receiving data which can be used by multiple clients.
