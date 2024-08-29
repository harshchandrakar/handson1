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
	printf("enter ticket number :\t");
	scanf("%d",&ticket);

	db.ticket_number = ticket;

	write(fd,&db,sizeof(db));

	close(fd);

	return 0;
}
