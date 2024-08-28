#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_whence= SEEK_SET;
	lock.l_pid = getpid();

	int fd = open("tickets",O_RDWR);

	if (fd<0) perror("error in opening: \n");

	struct {
		int ticket_number;
	} db;
	
	printf("Entering Write lock... \n"); 
	fcntl(fd,F_SETLK,&lock);

	if (0> read(fd,&db,sizeof(db))) perror("error in reading: \n");
	
	lseek(fd,-sizeof(db),SEEK_CUR);

	db.ticket_number+=1;

	if (0>write(fd,&db,sizeof(db))) perror("error in write : \n");

	printf("Ticket number after increment: %d \n", db.ticket_number);

	printf("Press enter to exit lock....");

	getchar();

	lock.l_type =F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	return 0;
}
	
		
