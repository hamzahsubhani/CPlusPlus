/********************************************************************
 * a4 - z2010017.cc
 * CSCI 330 Assignment 4
 * Spring Semester 2025
 * Created by Hamzah Subhani (Z - 2010017).
 *
 * This program writes a user-specified message to a file. The user
 * provides a filename and a message as command-line arguments. An
 * optional '-c' flag allows clearing the file before writing. The
 * program temporarily grants write permissions to the file, writes
 * the message, and then restores permissions.
 ********************************************************************/

#include <iostream>     // cerr, cout
#include <fcntl.h>      // open
#include <unistd.h>     // write, close
#include <sys/stat.h>   // stat, chmod
#include <cerrno>      // perror
#include <cstring>     // strlen

using std::cerr;
using std::cout;
using std::endl;
using std::string;

/********************************************************************
 * main ()
 * parses command-line arguments, checks file permissions, and writes
 * a message to the specified file. If '-c' is specified, the file is
 * cleared before writing.
 * parameters -  argc - number of command-line arguments. argv - array of command-line argument strings.
 * return 0 if successful, 1 on error.
 ********************************************************************/
int main(int argc, char *argv[])
{
    // check for minimum number of arguments
    if (argc < 3)
    {
        cerr << "Need 3 arguments, have: " << argc << endl;
        return 1;
    }

    // parse command-line arguments
    bool clearFile = false;
    char *filename = nullptr;
    char *message = nullptr;
    int opt;

    while ((opt = getopt(argc, argv, "c")) != -1)
    {
        switch (opt)
        {
            case 'c':
                clearFile = true; // truncate
                break;
            default:
                cerr << "Error with -c: invalid usage" << endl;
                return 1;
        }
    }

    // ensure filename and message are provided
    if (optind + 1 < argc)
    {
        filename = argv[optind];
        message = argv[optind + 1];
    }
    else
    {
        cerr << "Error: Need both filename and message" << endl;
        return 1;
    }

    // check file existence and permissions
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0)
    {
        if ((file_stat.st_mode & S_IRWXU) || (file_stat.st_mode & S_IRWXG) || (file_stat.st_mode & S_IRWXO))
        {
            cerr << "Error: File " << filename << " has existing permissions." << endl;
            return 1;
        }
    }
    else
    {
        // create file with no permissions if it does not exist
        int fd = open(filename, O_CREAT | O_WRONLY, 0000);
        if (fd == -1)
        {
            perror("Error creating file");
            return 1;
        }
        close(fd);
    }

    // temporarily grant write permissions
    if (chmod(filename, 0200) == -1)
    {
        perror("Error granting write permissions");
        return 1;
    }

    // open file for writing
    int fd;
    if (clearFile)
    {
        fd = open(filename, O_WRONLY | O_TRUNC); // truncate if -c
    }
    else
    {
        fd = open(filename, O_WRONLY | O_APPEND); // append if no -c
    }

    if (fd == -1)
    {
        perror("Error opening file");
        chmod(filename, 0000);
        return 1;
    }

    // write message to file
    if (write(fd, message, strlen(message)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        chmod(filename, 0000);
        return 1;
    }

    // append newline character
    if (write(fd, "\n", 1) == -1)
    {
        perror("Error writing newline to file");
        close(fd);
        chmod(filename, 0000);
        return 1;
    }

    // close file and restore permissions
    close(fd);
    if (chmod(filename, 0000) == -1)
    {
        perror("Error restoring file permissions");
        return 1;
    }

    return 0;
}
