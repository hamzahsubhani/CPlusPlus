//**************************************************************************
//
//  complex.h
//  CSCI 241 Assignment 10
//
//  Created by Hamzah Subhani ( Z2010017 )
//
//  creates a class called complex to hold various method prototypes and private data members.
//
//
//
//**************************************************************************

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <tuple> // used for tuple function which conjoins two double data members.

using namespace std;

class complex
{
private:
    // data members
    double real;
    double imaginary;
    
public:
    // method prototypes
    complex(double = 0, double = 0);
    void set_complex(double, double);
    tuple<double, double> get_complex() const;
    void set_real (double);
    double get_real() const;
    void set_imaginary(double);
    double get_imaginary() const;
    complex operator+(const complex& ) const;
    complex operator*(const complex& ) const;
    bool operator==(const complex& ) const;
    // standalones which need friend syntax
    friend ostream& operator<<(std::ostream&, const complex&);
    friend istream& operator>>(std::istream&, complex&);
};

    













#endif // to prevent it being #included further
