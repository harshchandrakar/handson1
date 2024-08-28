#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	struct 
	{
		int ticket_number;
	} db;

	int fd = open("tickets",O_RDWR |O_CREAT,0644);

	if (fd<0) perror("error opening file: \n");

	int ticket;
	
	int fd2 = read(0,&ticket,sizeof(ticket));

	if (fd2<0) perror("error reading file: \n") ;

	db.ticket_number = ticket;

	write(fd,&db,sizeof(db));

	close(fd);

	return 0;
}
