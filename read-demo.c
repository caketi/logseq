#include <fcntl.h>
int main(){
    int fd, count;
    char buf[1000];
    fd = open("mydata", O_RDONLY);
    count = read(fd, buf, 1000);
    write(1, buf, count);
    close(fd);
}