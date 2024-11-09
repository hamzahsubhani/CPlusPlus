/***************************************************************
CSCI 240         Program 1     Fall 2019
Programmer: Hamzah Subhani
Section: 2
Date Due: 1/26/24
Z-ID: 2010017
Purpose: The purpose of this program is to calculate and display
         the gravitational force between two objects.

         The user provides the mass of the two objects and the
         distance between the objects.
***************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double G= 0.667e-10;
    double m1, m2, d;
    cout<<"GRAVITATIONAL FORCE CALCULATOR";
    cout<<"\nEnter the mass of object 1 (in kilograms):";
    cin>>m1;
    cout<<"\nEnter the mass of object 2 (in kilograms):";
    cin>>m2;
    cout<<"\nEnter the distance between the 2 objects (in meters):";
    cin>>d;
    cout<<"\nThe Gravitational force is:  ";
    double force = (G * m1 * m2) / (d * d);
    cout<<force<<" newtons"<<endl;
    return 0;
}
