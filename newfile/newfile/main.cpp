#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()
{
    
    
    int fd;
    
    fd = open ("doesnt exist", O_WRONLY | O_CREAT, 0644);
    const char text[] = "this is what i want to write";
    cout << "fd = " << fd << endl;
     
    cout << "ssize of " << sizeof(text) << endl;
    cout << "strlen = " << strlen(text) << endl;
    
    write(fd, text, strlen(text));
    
    
    return 0;
}
