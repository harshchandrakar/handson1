#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>


void main(){

	struct stat sd;

	if ( stat("./file1.txt",&sd) == -1){
		perror("stat:");
	}

	printf("inode: %ld \n" , sd.st_ino);
 	printf("number of hard links: %ju \n,",sd.st_nlink);
 	printf("uid: %u\n" ,sd.st_uid);
 	printf("gid: %u\n",sd.st_gid);
 	printf("size: %jd\n",sd.st_size);
 	printf("block size: %jd\n",sd.st_blksize);
	printf("number of blocks: %jd\n",sd.st_blocks);
 	printf("time of last access: %jd\n",sd.st_atime);
 	printf("time of last modification: %jd\n",sd.st_mtime);
 	printf("time of last change: %jd\n",sd.st_ctime);
}










