#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int fd;
    int rc;
    char *data = "hello world";
    fd = open("/dev/pts/1", O_WRONLY);
    printf("fd = %d\nrc = %d\n", fd, rc);
    if(fd < 0){
        printf("Error opening file : %d\n",fd);
        exit(-1);
    }
    rc = write(fd, data, strlen(data)+1);
    if(rc < 0){
        printf("Error writing file : %d\n",rc);
        exit(-1);
    }
    close(fd);  // file operation is done, close the file.
    return 0;
}