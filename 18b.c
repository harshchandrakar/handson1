#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {

	struct flock lock;
    int train;

    struct {
		int ticket_number;
	} db;

    printf("select train number(1,2,3): \t");
    scanf("%d",&train);
	lock.l_type = F_RDLCK;
	lock.l_start = (train-1)*sizeof(db);
	lock.l_len = sizeof(db);
	lock.l_whence= SEEK_SET;
	lock.l_pid = getpid();

	int fd = open("db",O_RDWR);

	if (fd<0) perror("error in opening: \n");
	
	printf("Entering Read lock... \n"); 
	fcntl(fd,F_SETLKW,&lock);


    lseek(fd,(train-1)*sizeof(db),SEEK_SET);
    read(fd,&db,sizeof(db));
    printf("Current ticket number is : %d \n",db.ticket_number);

	printf("Press enter to exit lock....\n");

	getchar();
    getchar();

	lock.l_type =F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	return 0;
}
	
		
