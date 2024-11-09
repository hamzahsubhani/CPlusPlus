//**************************************************************************
//
//  complex.cpp
//  CSCI 241 Assignment 10
//
//  Created by Hamzah Subhani ( Z2010017 )
//
//  Tests the functionality of the complex class, which
//  represents complex numbers and supports various operations such as
//  addition, multiplication, and input/output operations.
//
//**************************************************************************

#include <iostream>
#include <iomanip>
#include <tuple> // used for tuple function which conjoins two double data members
#include "complex.h" // header file which contains the complex class for prototypes and data members.

using std::cin;
using std::cout;
using std::endl;
using std::get;
using std::tuple;

/* complex (default constructor)
 *
 * constructs a complex number with specified real and imaginary parts.
 *
 * @param integer real - the real part of the complex number.
 *
 * @param integer imaginary - the imaginary part of the complex number.
 */

complex::complex(double real, double imaginary)
{
    this->real = real; // this -> is pointing to the actual data member, not parameter
    this->imaginary = imaginary;
}

/* complex (alternate constructor)
 *
 * sets the real and imaginary parts of the complex number.
 *
 * @param integer real - the new real part of the complex number.
 *
 * @param imaginary - the new imaginary part of the complex number.
 */

void complex::set_complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

/* tuple
 *
 * retrieves the real and imaginary parts of the complex number as a tuple.
 *
 * @param none
 *
 * @return tuple - pair of doubles which contain the real and imaginary parts of the complex number.
 */

tuple<double, double> complex::get_complex() const
{
    return make_tuple(real, imaginary); // concatenates both doubles
}

/* set_real
 *
 * sets the real part of the complex number to the parameter.
 *
 * @param double r - the new real part of the complex number.
 *
 * @return nothing
 */

void complex::set_real(double r)
{
    real = r;
}

/* get_real
 *
 * retrieves the real part of the complex number.
 *
 * @param none
 *
 * @return double real - real part of the complex number
 */

double complex::get_real() const
{
    return real;
}

/* set_imaginary
 *
 * sets the imaginary part of the complex number.
 *
 * @param double i - The new imaginary part of the complex number.
 *
 * @return nothing
 */

void complex::set_imaginary(double i)
{
    imaginary = i;
}

/* get_imaginary
 *
 * retrieves the imaginary part of the complex number.
 *
 * @param none
 *
 * @return double imaginary - the imaginary part of the complex number.
 */

double complex::get_imaginary() const
{
    return imaginary;
}

/* operator+
 *
 * overloads the addition operator for complex numbers.
 *
 * @param const complex& rhs - the complex number to add (reference to const complex object).
 *
 * @return complex result - new complex object variabe which is the sum of this complex number and rhs.
 */

complex complex::operator+(const complex& rhs) const
{
    complex result;
    
    result.imaginary = this->imaginary + rhs.imaginary;
    result.real = this->real + rhs.real;
    
    return result;
}

/* operator*
 *
 * overloads the multiplication operator for complex numbers.
 *
 * @param const complex& rhs - the complex number to multiply with.
 *
 * @return complex result - complex object variable that is the product of this complex number and rhs.
 */

complex complex::operator*(const complex& rhs) const 
{
    double a = this->real;          // Real part of the first complex number
    double b = this->imaginary;     // Imaginary part of the first complex number
    double c = rhs.real;            // Real part of the second complex number
    double d = rhs.imaginary;       // Imaginary part of the second complex number
    
    complex result;
    
    result.real = (a * c) - (b * d);
    result.imaginary = (a * d) + (b * c);
    
    return result;
}

/* operator==
 *
 * overloads the equality operator for complex numbers.
 *
 * @param const complex& rhs - the complex number to compare with.
 *
 * @return boolean - true if the complex numbers are equal; otherwise, false.
 */

bool complex::operator==(const complex& rhs) const
{
    return (rhs.real == this->real && rhs.imaginary == this->imaginary);
}

/* operator<<
 *
 * overloads the output stream operator for complex numbers.
 *
 * @param ostream& os - the output stream to write to (reference to
 an ostream object)
 *
 * @param const complex& c - the complex number to write.
 *
 * @return the output stream after writing the complex number.
 */

ostream& operator<<(std::ostream& os, const complex& c)
{
    os << '(' << c.real << ", " << c.imaginary << ')';
    return os;
}

/* operator>>
 *
 * overloads the input stream operator for complex numbers.
 *
 * @param istream is - the input stream to read from ( reference to an istream object).
 *
 * @param complex& ch - the complex number to populate ( ref to complex object).
 *
 * @return the input stream after reading the complex number.
 */

istream& operator>>(std::istream& is, complex& ch)
{
    char par, comma;
    double re, imag;
    
    is >> par;   // read the opening parenthesis
    is >> re;    // read the real part
    is >> comma; // read the comma
    is >> imag;  // read the imaginary part
    is >> par;   // read the closing parenthesis
    
    ch.set_complex(re, imag); // setting complex number to read values
    return is;
}

/* main
 *
 * tests the functionality of the complex class data members, methods, constructors, and standalone functions.
 *
 * @param none
 *
 * @return 0 on successful execution.
 */

int main()
{
    complex c1(23, 34); // Create complex number 23 + 34i
    complex c2;         // Default constructor will initialize to some default values
    complex c3(8, 5);   // Create complex number 8 + 5i
    const complex c4(3, 4); // Create constant complex number 3 + 4i
    const complex c5(3, 4); // Create another constant complex number 3 + 4i

    cout << "Testing stream insertion operator and constructors...\n\n";
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl << endl;

    cout << "Testing get methods...\n\n";
    
    cout << "Real part of c4 = " << c4.get_real() << endl;
    cout << "Imaginary part of c4 = " << c4.get_imaginary() << endl;
    
    tuple<double, double> result = c4.get_complex();

    cout << "Real part of c4 = " << get<0>(result) << endl;
    cout << "Imaginary part of c4 = " << get<1>(result) << endl << endl;
    
    cout << "Testing set methods...\n\n";
    
    c2.set_complex(3.7, 2.5);
    cout << "New value of c2 = " << c2 << endl;
    c2.set_real(-1.4);
    cout << "New value of c2 = " << c2 << endl;
    c2.set_imaginary(83);
    cout << "New value of c2 = " << c2 << endl << endl;
    
    cout << "Testing stream extraction operator...\n\n";
    
    cout << "Enter a complex number in the form (a, b) ";
    cin >> c2;
    cout << "New value of c2 = " << c2 << endl << endl;
    
    cout << "Testing addition operator...\n\n";
    
    c3 = c1 + c4;
    cout << "c3 = " << c3 << endl;
    cout << c4 << " + " << c1 << " = " << c4 + c1 << endl;
    cout << c4 << " + " << c4 << " = " << c4 + c4 << endl << endl;

    cout << "Testing multiplication operator...\n\n";

    c3 = c1 * c4;
    cout << "c3 = " << c3 << endl;
    cout << c4 << " * " << c1 << " = " << c4 * c1 << endl;
    cout << c4 << " * " << c4 << " = " << c4 * c4 << endl << endl;

    cout << "Testing equality operator...\n\n";

    c3.set_complex(8, 5);
    cout << c1 << " and " << c3;
    (c1 == c3) ? cout << " are equal\n" : cout << " are not equal\n";

    cout << c4 << " and " << c5;
    (c4 == c5) ? cout << " are equal\n" : cout << " are not equal\n";
    
    return 0;
}


