#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


/* Fantastic day, on my Powerbook G4 have programmed my first UNIX AF_INET socket for bind, next is to allocate a heap, after proof-of-concept for a vanilla strcpy stack overflow, tested in GDB */

/* Thankfully spent some time coalescing with the British GCHQ, got the idea from a former GCHQ instructor who did a series called pwnallthethings, by far a very authoritative reference as to information security principles in the most realistic, pragmatic sense */

/* Thanks. github.com/r0ss1n1 */

/* Charles Thomas Wallace Truscott */

/* Mac OS X 10.4 Tiger */

/* You can read about me at satanicritualabuse.wordpress.com */

int test(void);

int main(void) {

	int sock_file_descriptor;
	int new_sock_file_descriptor;
	int port_number;
	int client_length;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	char p[2000];
	int q;
	char r[500];
	int s;

	sock_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

	if (sock_file_descriptor < 0) {
		printf("Invoking the socket failed\n");
	}

	port_number = 1234;

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port_number);	

	if(bind(sock_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		printf("Invoking bind failed\n");
	}

	listen(sock_file_descriptor, 5);
	client_length = sizeof(client_address);

	new_sock_file_descriptor = accept(sock_file_descriptor, (struct sockaddr *) &client_address, (socklen_t *) &client_length);

	if (new_sock_file_descriptor < 0) {
		printf("Invoking accept failed\n");
	}

	read(new_sock_file_descriptor, p, 1000);
	strcpy(r, p);
	s = write(new_sock_file_descriptor, "ACKNOWLEDGEMENT\n");

	if (s < 0) {
		printf("Error writing to socket (sending protocol response)\n");
	}

	for(q = 0; q <= 300; ++q) {
		printf("%c", p[q]);
	}

	
	return 0;
}

int test(void) {

	printf("You win\n");


}
