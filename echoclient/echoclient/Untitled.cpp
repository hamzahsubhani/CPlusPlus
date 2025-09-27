#include <iostream>         // for std::cout, std::cerr
#include <cstring>          // for memset(), strlen()
#include <cstdlib>          // for exit(), atoi()
#include <unistd.h>         // for close()
#include <arpa/inet.h>      // for inet_addr(), htons()
#include <sys/types.h>      // for socket types
#include <sys/socket.h>     // for socket(), sendto(), recvfrom()

using namespace std;

int sock;
struct sockaddr_in echoserver; // structure for address of server
struct sockaddr_in echoclient; // structure for address of client
// Create the UDP socket
if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
perror("Failed to create socket"); exit(EXIT_FAILURE); }
// Construct the server sockaddr_in structure
memset(&echoserver, 0, sizeof(echoserver)); // Clear struct
echoserver.sin_family = AF_INET; // Internet IP
echoserver.sin_addr.s_addr = INADDR_ANY; // Any IP address
echoserver.sin_port = htons(atoi(argv[1])); // server port
// Bind the socket
serverlen = sizeof(echoserver);
if (bind(sock, (struct sockaddr *) &echoserver, serverlen) < 0) {
perror("Faled to bind server socket"); exit(EXIT_FAILURE); }
// Run until cancelled
while (true) {
// Receive a message from the client
clientlen = sizeof(echoclient);
if ((received = recvfrom(sock, buffer, 256, 0, (struct sockaddr *) &echoclient, &clientlen)) < 0) {
perror("Failed to receive message"); exit(EXIT_FAILURE); }
cerr << "Client connected: " << inet_ntoa(echoclient.sin_addr) << "\n";
// Send the message back to client
if (sendto(sock, buffer, received, 0, (struct sockaddr *) &echoclient, clientlen) != received) {
perror("Mismatch in number of echo'd bytes"); exit(EXIT_FAILURE); }
}
close(sock);
