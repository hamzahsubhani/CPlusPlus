//********************************************************************
//  dog_features
//  CSCI 330 Assignment 5
//  Spring Semester 2025
//  created by Hamzah Subhani (Z - 2010017).
//  description: contains all function DEFINITIONS that will be preformed on a file whether the user uses -c (cipher), -h hex), -s (binary shift), -b (binary)
//********************************************************************
#include "dog.h"
#include <iostream>
#include <iomanip>

/**********************************************************
 * caesar_cipher
 * -----------------------
 * Encrypts the given buffer using a Caesar cipher shift.
 *
 * Parameters:
 *   buffer - The buffer containing data to be encrypted.
 *   bytesRead - The number of bytes read from the buffer.
 *   shift - The number of positions to shift each letter.
 *
 * Returns:
 *   Void
 **********************************************************/

void caesar_cipher(char* buffer, ssize_t bytesRead, int shift)
{
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        if (isalpha(buffer[i]))
        {
            char base;
            if (islower(buffer[i]))
            {
                base = 'a';
            }
            else
            {
                base = 'A';
            }
            buffer[i] = base + (buffer[i] - base + shift) % 26;
        }
    }
}

/**********************************************************
 * binary_rotation
 * -------------------------
 * Performs binary rotation on the buffer.
 *
 * Parameters:
 *   buffer - The buffer containing data to be modified.
 *   bytesRead - The number of bytes read from the buffer.
 *   shift - The shift amount for binary rotation.
 *
 * Returns:
 *   Void
 **********************************************************/

void binary_rotation(char* buffer, ssize_t bytesRead, int shift)
{
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        buffer[i] = (buffer[i] + shift) % 256;
    }
}

/**********************************************************
 * hex
 * ------------
 * Converts  buffer data into hexadecimal representation, writes it to standard output.
 *
 * Parameters:
 *   buffer - The buffer containing data to be converted.
 *   bytesRead - The number of bytes read from the buffer.
 *
 * Returns:
 *   Void
 **********************************************************/

void hex(char* buffer, ssize_t bytesRead)
{
    const char hexChars[] = "0123456789abcdef";

    for (ssize_t i = 0; i < bytesRead; i++)
    {
        unsigned char byte = buffer[i];
        unsigned char highNibble = (byte >> 4) & 0x0F;
        unsigned char lowNibble = byte & 0x0F;

        char hexByte[2];
        hexByte[0] = hexChars[highNibble];
        hexByte[1] = hexChars[lowNibble];

        write(STDOUT_FILENO, hexByte, 2);
    }
}

/**********************************************************
 * Function: binary
 * ----------------
 * Converts buffer data into binary representation, writes it to standard output.
 *
 * Parameters:
 *   buffer - The buffer containing data to be converted.
 *   bytesRead - The number of bytes read from the buffer.
 *
 * Returns:
 *   Void
 **********************************************************/

void binary(char* buffer, ssize_t bytesRead)
{
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        for (int j = 7; j >= 0; --j)
        {
            char bit;
            if ((buffer[i] >> j) & 1) // Check if the bit is set
            {
                bit = '1';
            }
            else
            {
                bit = '0';
            }
            write(STDOUT_FILENO, &bit, 1); // Write the bit to standard output
        }
    }
}
