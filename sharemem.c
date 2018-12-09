#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(){

    key_t key;
    int shmid;
    char *data;

    key = ftok("hi", 'R');
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);

    data = shmat(shmid, 0 ,0);

    if(!data[0]){
        printf("New Segment Created {empty} \n");
    } else {
        printf("Segment: %s\n", data);
    }

    printf("Do you want to change the contents of the segment?\n");

    char ans[100];
    fgets(ans, sizeof(ans), stdin);

    if(strstr(ans, "yes")){
        printf("Enter new content:\n");
        fgets(ans, sizeof(ans), stdin);
        strcpy(data, ans);
        printf("content now: %s\n", data);
    }

    printf("Do you want to delete the segment?\n");

    fgets(ans, sizeof(ans), stdin);
    if(strstr(ans, "yes")){
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }


    return 0;
}
