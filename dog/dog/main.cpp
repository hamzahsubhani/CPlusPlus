//********************************************************************
//  main.cpp
//  CSCI 330 Assignment 5
//  Spring Semester 2025
//  created by Hamzah Subhani (Z - 2010017).
//  description: this file includes getopt in the main loop which handles command line arguments and option characters. it will call the other functions based on what the user passes in.
//********************************************************************

#include "dog.h" //function declarations
#include <iostream>
#include <unistd.h> // read, write, close
#include <cstring> // strcmp
#include <getopt.h> // parse command line arguments
#include <fcntl.h> // open

using namespace std;

int main(int argc, char* argv[])
{
    int bufferSize = 1024; // size of buffer used for reading data
    int totalBytes = -1; // max number of bytes to read
    int caesarShift = 0; // 0 if not selected
    int binaryShift = 0; // 0 if not selected
    bool hexOutput = false; // true if -h used
    bool binaryOutput = false; // true if -b used

    int opt;
    while ((opt = getopt(argc, argv, "a:n:c:s:hb")) != -1)
    {
        switch (opt)
        {
            case 'a': // modify buffer size
                bufferSize = atoi(optarg);
                break;
            case 'n': // applied buffer size
                totalBytes = atoi(optarg);
                break;
            case 'c': // caesar shift
                caesarShift = atoi(optarg);
                if (binaryShift)
                {
                    cerr << "Error: Cannot specify both -c and -s options." << endl;
                    return 1;
                }
                break;
            case 's': // general shift
                binaryShift = atoi(optarg);
                if (caesarShift)
                {
                    std::cerr << "Error: Cannot specify both -c and -s options." << endl;
                    return 1;
                }
                break;
            case 'h': // hexadecimal output
                hexOutput = true;
                if (binaryOutput)
                {
                    std::cerr << "Error: Cannot specify both -h and -b options." << endl;
                    return 1;
                }
                break;
            case 'b': // binary output
                binaryOutput = true;
                if (hexOutput)
                {
                    std::cerr << "Error: Cannot specify both -h and -b options." << endl;
                    return 1;
                }
                break;
            default:
                cerr << "Usage: " << argv[0] << " [-a N] [-n N] [-c k] [-s k] [-h] [-b] [file...]" << endl;
                return 1;
        }
    }

    // process files
    for (int i = optind; i < argc; ++i)
    {
        const char* filename = argv[i];
        int fd; // file descriptor

        if (strcmp(filename, "-") == 0)
        {
            fd = STDIN_FILENO; // read from standard input
        }
        else
        {
            fd = open(filename, O_RDONLY); // open the file for reading
        }

        if (fd == -1)
        {
            perror("Error opening file");
            continue; // skip to the next file if there's an error
        }

        char* buffer = new char[bufferSize];
        ssize_t bytesRead;
        ssize_t totalRead = 0;
        
        //send to respective functions to handle
        while ((bytesRead = read(fd, buffer, bufferSize)) > 0 && (totalBytes == -1 || totalRead < totalBytes))
        {
            if (totalBytes != -1 && totalRead + bytesRead > totalBytes)
            {
                bytesRead = totalBytes - totalRead;
            }

            if (caesarShift)
            {
                caesar_cipher(buffer, bytesRead, caesarShift);
            }
            else if (binaryShift)
            {
                binary_rotation(buffer, bytesRead, binaryShift);
            }

            if (hexOutput)
            {
                hex(buffer, bytesRead);
            }
            else if (binaryOutput)
            {
                binary(buffer, bytesRead);
            }
            else // write if no option used
            {
                write(STDOUT_FILENO, buffer, bytesRead);
            }

            totalRead += bytesRead;
        }

        delete[] buffer;
        if (fd != STDIN_FILENO)
        {
            close(fd); //close after done executing
        }
    }

    return 0;
}
