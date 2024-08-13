#include <stdio.h>
#include <unistd.h>

void main() {
	char buffer[20];
	for (int i = 0; i<5 ; i++){
		int n1 = read(0,buffer,20);

		write(0,buffer,n1);

	}

}

