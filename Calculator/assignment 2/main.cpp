//*******************************************
//CSCI 240      Program 2      Spring 2024
//Programmer: Hamzah Subhani
//Section: 2
//TA: Amy Byrnes
//Due date: 2/2/24
//Z-ID: 2010017
//Purpose: to display the x and y coordinates (vertex) using the quadratic formula. This is based on numbers
//the user chooses for each coefficient listed.
//**************************************
#include <iostream>
#include <iomanip>
using namespace std;
#define Left_column_width 20
#define Right_column_width 11 // both of these define how wide each column will be on the right and left
int main(){
    int A, B , C; //declaring integers to be used in a formula
    double y_vertex;
    double x_vertex; //declaring a precise variable
    cout<<"please enter the A coefficient: ";
    cin>>A;
    cout<<"please enter the B coefficient: ";
    cin>>B;
    cout<<"please enter the C coefficient: ";
    cin>>C;
    cout<<fixed<<setprecision(4);
    cout<<"--------------------------------------"<<endl;
    cout<<"   QUADRATIC EQUATION ANALYZER"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<setw(Left_column_width)<<left<<"A coefficient"<<right<<setw(Right_column_width)<<A<<endl; //aligning left coefficient column with the value the user entered associated with it
    cout<<setw(Left_column_width )<<left<<"B coefficient"<<right<<setw(Right_column_width)<<B<<endl;
    cout<<setw(Left_column_width )<<left<<"C coefficient"<<right<<setw(Right_column_width)<<C<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<< setw(Left_column_width )<<left<<"Vertex"<<endl;
    x_vertex = -(B) / (2.0 * A);
    y_vertex = (A * x_vertex * x_vertex) + ( B * x_vertex) + C; //both the formulas we give the program to preform the calculations
    cout << setw(Left_column_width ) <<left<< "X coordinate "<<right<<setw(Right_column_width)<< x_vertex << endl;
    cout << setw(Left_column_width ) <<left<< "Y coordinate "<<right<<setw(Right_column_width)<< y_vertex << endl;
    cout<<"--------------------------------------"<<endl;
    //aligning the text " x and y coordinate' with the result of the calculation
        return 0;
    
    
    
}
