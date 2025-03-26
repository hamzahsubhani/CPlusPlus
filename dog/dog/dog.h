//********************************************************************
//  dog.h
//  CSCI 330 Assignment 5
//  Spring Semester 2025
//  created by Hamzah Subhani (Z - 2010017).
//  description: contains all functions that will be called whether the user uses -c (cipher), -h hex), -s (binary shift), -b (binary)
//********************************************************************
#ifndef DOG_H
#define DOG_H

#include <unistd.h>

// function declarations
void caesar_cipher(char* buffer, ssize_t bytesRead, int shift);
void binary_rotation(char* buffer, ssize_t bytesRead, int shift);
void hex(char* buffer, ssize_t bytesRead);
void binary(char* buffer, ssize_t bytesRead);

#endif 
