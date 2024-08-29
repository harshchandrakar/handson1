#include <stdio.h>
#include <sched.h>
#include <unistd.h>


int findScheduler(int policy){

    switch (policy)
    {
    case SCHED_FIFO:
        printf("Its FIFO scheduling \n");
        break;
    case SCHED_RR:
        printf("Its RR scheduling \n");
        break;
    case SCHED_OTHER:
        printf("Its Other scheduling \n");
        break;
    
    default:
        break;
    }
    return 1;
}

int main(){
    int pid = getpid();
    int policy = sched_getscheduler(pid);
    if (policy == -1){
        perror("Can't get policy: \n");
    }else{
        findScheduler(policy);
    }

    int choice;
// it can be executed as root user only
    printf("Choose a scheduling plan \n 1.FIFO \n 2.RR  \n 3.Other \n");
    scanf("%d",&choice);
    struct sched_param s;

    switch (choice)
    {
    case 1:
        s.sched_priority = sched_get_priority_max(SCHED_FIFO);
        sched_setscheduler(pid,SCHED_FIFO,&s);     
        break;
    case 2:
        s.sched_priority =sched_get_priority_max(SCHED_RR);
        sched_setscheduler(pid,SCHED_RR,&s);     
        break;
    case 3:
        s.sched_priority = sched_get_priority_max(SCHED_OTHER);
        sched_setscheduler(pid,SCHED_OTHER,&s);     
        break;
    
    default:
        printf("wrong choioce \n");
        break;
    }
    

    policy = sched_getscheduler(pid);

    findScheduler(policy);
    return 1;

}