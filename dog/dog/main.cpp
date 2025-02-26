//********************************************************************
//  dog.cpp
//  CSCI 330 Assignment 5
//  Spring Semester 2025
//  created by Hamzah Subhani (Z - 2010017).
//  description: this program mimics the Unix 'cat' command by
//  reading files and/or standard input and outputting to the console.
//********************************************************************

#include <iostream> // cout
#include <sys/stat.h> // for file permissions
#include <fcntl.h> // open, file descriptors
#include <unistd.h> // read, write, close
#include <cstring> // strcmp

using namespace std;

int main(int argc, char* argv[])
{
    // check if there are sufficient arguments passed to the program
    if (argc < 2)
    {
        cerr << "no file passed in" << endl; // error message if no files passed
        return 1; // return on error
    }
    
    bool clearFile = false;
    int opt;

    while ((opt = getopt(argc, argv, "hbo:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                continue;
            case 'b':
                continue;
            case 'o':
                continue;
                break;
            default:
                cerr << "Error" << endl;
                return 1;
        }
    }
    
    
    // loop through all passed arguments
    for (int i = 1; i < argc; ++i)
    {
        const char* filename = argv[i];

        // if the argument is a "-", read from standard input
        if (strcmp(filename, "-") == 0)
        {
            char buffer[1024];  // buffer to store data from standard input. will open even if file is larger than RAM
            ssize_t bytesRead;

            // read input until end of stream
            while ((bytesRead = read(0, buffer, sizeof(buffer))) > 0)
            {
                write(STDOUT_FILENO, buffer, bytesRead);  // write to standard output
            }
        }
        else
        {
            // open file for reading
            int fd = open(filename, O_RDONLY);  // open file with read-only flag
            if (fd == -1)
            {
                cerr << "error opening file: " << filename << endl;
                continue;  // skip to the next file
            }

            // read the file and output to standard output
            char buffer[1024];  // buffer for reading file data
            ssize_t bytesRead;

            // read file contents in chunks
            while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
            {
                write(STDOUT_FILENO, buffer, bytesRead);  // write to standard output
            }

            close(fd);  // close file after reading
        }
    }

    return 0; // successful execution
}
