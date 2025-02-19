#include <iostream> // cerr, cout
#include <fcntl.h>  // open
#include <unistd.h> // write, close
#include <sys/stat.h> // stat, chmod
#include <cerrno> // perror
#include <cstring> // strlen

using std::endl;
using std::cerr;
using std::cout;
using std::string;

int main(int argc, char *argv[])
{
    // check for minimum number of arguments
    if (argc < 3) {
        cerr << "Need 3 arguments, have: " << argc << endl;
        return 1;
    }

    // parse command-line arguments
    bool clearFile = false;
    char *filename = nullptr;
    char *message = nullptr;

    int opt;
        while ((opt = getopt(argc, argv, "c")) != -1) {
            switch (opt) {
                case 'c':
                    clearFile = true;
                    break;
                default:
                    cerr << "Error with -c: invalid usage" << endl;
                    return 1;
            }
        }

        // check that there are enough arguments after options
        if (optind + 1 < argc) {
            filename = argv[optind];
            message = argv[optind + 1];
        } else {
            cerr << "Error: Need both filename and message" << endl;
            return 1;
        }

    // check if the file exists and has existing permissions
    struct stat file_stat;
    
    // if file exists but has no permissions, continue to grant write
    if (stat(filename, &file_stat) == 0) {
        if ((file_stat.st_mode & S_IRWXU) || (file_stat.st_mode & S_IRWXG) || (file_stat.st_mode & S_IRWXO)) {
            cerr << "Error: File " << filename << " has existing permissions." << endl;
            return 1;
        }
    } else { // file doesn't exist, create it with no permissions
        int fd = open(filename, O_CREAT | O_WRONLY, 0000);
        if (fd == -1) {
            perror("Error creating file");
            return 1;
        }
        close(fd);
    }

        
    // temporarily grant write permissions to the file for USER
    if (chmod(filename, 0200) == -1) {
        perror("Error granting write permissions");
        return 1;
    }

    
    int fd;
    if (clearFile) // -c
    {
        // ensure file is opened with truncation flag to clear it
        fd = open(filename, O_WRONLY | O_TRUNC); // truncate file if -c is set
        if (fd == -1) {
            perror("Error opening file with truncate");
            chmod(filename, 0000); // restore permissions before exiting
            return 1;
        }
    } else {
        fd = open(filename, O_WRONLY | O_APPEND); // no -c optional parameter
        if (fd == -1) {
            perror("Error opening file in append mode");
            chmod(filename, 0000); // restore permissions before exiting
            return 1;
        }
    }

    if (fd == -1) {
        perror("Error opening file");
        chmod(filename, 0000); // restore permissions before exiting
        return 1;
    }

    // write the message to the file
    if (write(fd, message, strlen(message)) == -1) {
        perror("Error writing to file");
        close(fd);
        chmod(filename, 0000);
        return 1;
    }

    // add newline character
    if (write(fd, "\n", 1) == -1) {
        perror("Error writing newline to file");
        close(fd);
        chmod(filename, 0000);
        return 1;
    }

    // close file and reset permissions
    close(fd);
    if (chmod(filename, 0000) == -1) { // if resetting fails
        perror("Error restoring file permissions");
        return 1;
    }
    return 0;
}
