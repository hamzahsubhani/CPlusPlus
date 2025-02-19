#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()

{
    int fd;
    char buffer[1024];
    fd = open("readme", O_RDONLY);
    
    if (fd == -1)
    {
        perror ("open");
        exit(1);
    }
    ssize_t nr;
    nr = read(fd, buffer, 1024);
    cout << "read read " << nr << "bytes" ;
}
