# Introduction

This project aims to establish client-server communication over a network using Transmission Control Protocol/Internet Protocol (TCP/IP). The connection between client and server is established and maintained until the application programs at each end have finished exchanging messages by giving the "exit" command. The protocol uses segments (packets) as the basic units of data transmission, hence socket programming was implemented in C++ in this project.

This project was completed under the guidance of ACM Student Chapter - IIT Roorkee. Here as client we can send words/phrases (without spaces) to the server and the same can be sent from the server to the client. But there were additions done at my end. The client can seek answers from the server regarding some mathematical calculations mainly addition, subtraction, multiplication, division and modulus of integers.

For adding 3 and 4: ADD3,4  
For subtracting 6 and 2: SUB6,2  
For multiplying 5 and 3: MUL5,3  
For dividing 60 and 4: DIV60,4  
For finding 22 modulus 5: MOD22,5  

Note - If one of the numbers is missing (like ADD,4) then the missing number will be treated as 0. The answer is NOT-DEFINED if any number is divided by 0.

![ClientServerTCP](https://user-images.githubusercontent.com/70306618/109428548-7d508000-7a1d-11eb-8624-64425c388b52.png)

# Further Improvements

Currently the features added work for integers only, this may be improved to work for floating point numbers too. Also other new features can be added on the server side which may assist the client side, like storing and receiving data which can be used by multiple clients.
