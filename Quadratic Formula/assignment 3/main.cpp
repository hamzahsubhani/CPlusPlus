/*******************************************
// CSCI 240      Program 3    Spring 2024
// Programmer: Hamzah Subhani
// Section: 2
// TA: Amy Byrnes
// Due date: 2/9/24
// Z-ID: 2010017
// Purpose: to display the x and y coordinates (vertex) using the quadratic formula. This analyzer also uses the entered values to determine the discriminant, the roots based on the behavior of the discriminant, and the concavity of the parabola.
*******************************************/
#include<iostream>
#include<iomanip>
#include<cmath>

#define LEFT_COLUMN_WIDTH 20
#define RIGHT_COLUMN_WIDTH 11

using namespace std;

int main()
{
    int a, b, c;
    double Discriminant;
    double Root1;
    double Root2;
    double X_Vertex;
    double Y_Vertex;

    cout << "enter the a coefficient (non-zero value): ";
    cin >> a;

    if (a==0)
    {
        cout << "Error: the a-coefficient MUST be non-zero. Try again: ";
        cin >> a;
    }

    cout << "enter the b coefficient: ";
    cin >> b;
    cout << "enter the c coefficient: ";
    cin >> c;

    cout << fixed << setprecision(3);

    cout << "--------------------------------------" << endl;
    cout << "   QUADRATIC EQUATION ANALYZER" << endl;
    cout << "--------------------------------------" << endl;
    cout << setw(LEFT_COLUMN_WIDTH) << left << "a coefficient" << right << setw(RIGHT_COLUMN_WIDTH) << a << endl;
    cout << setw(LEFT_COLUMN_WIDTH) << left << "b coefficient" << right << setw(RIGHT_COLUMN_WIDTH) << b << endl;
    cout << setw(LEFT_COLUMN_WIDTH) << left << "c coefficient" << right << setw(RIGHT_COLUMN_WIDTH) << c << endl;
    cout << "--------------------------------------" << endl;
    cout << setw(LEFT_COLUMN_WIDTH) << left << "Vertex" << endl;

    Discriminant = (b * b - 4 * a * c);
    Root1 = (-b + sqrt(Discriminant)) / (2 * a);
    Root2 = (-b - sqrt(Discriminant)) / (2 * a);
    X_Vertex = -(b) / (2.0 * a);
    Y_Vertex = (a * X_Vertex * X_Vertex) + (b * X_Vertex) + c;

    cout << setw(LEFT_COLUMN_WIDTH) << left << "X coordinate " << right << setw(RIGHT_COLUMN_WIDTH) << X_Vertex << endl;
    cout << setw(LEFT_COLUMN_WIDTH) << left << "Y coordinate " << right << setw(RIGHT_COLUMN_WIDTH) << Y_Vertex << endl;
    cout << "--------------------------------------" << endl;

    if (a > 0)
    {
        cout << setw(LEFT_COLUMN_WIDTH) << left << " The parabola opens UPWARD" << endl;
    }
    if (a < 0)
    {
        cout << "The parabola opens DOWNWARD" << endl;
    }

    cout << "--------------------------------------" << endl;

    if (Discriminant > 0)
    {
        cout << setw(LEFT_COLUMN_WIDTH) << left << "The parabola has TWO roots" << endl;
        cout << setw(LEFT_COLUMN_WIDTH) << left << "Root 1 - X Coordinate" << right << setw(RIGHT_COLUMN_WIDTH) << Root1 << endl;
        cout << setw(LEFT_COLUMN_WIDTH) << left << "Root 2 - X Coordinate" << right << setw(RIGHT_COLUMN_WIDTH) << Root2 << endl;
    }
    if (Discriminant == 0)
    {
        cout << setw(LEFT_COLUMN_WIDTH) << left << "The parabola has ONE root" << endl;
        cout << setw(LEFT_COLUMN_WIDTH) << left << "Root 1 - X Coordinate" << right << setw(RIGHT_COLUMN_WIDTH) << Root1 << endl;
    }
    if (Discriminant < 0)
        cout << setw(LEFT_COLUMN_WIDTH) << left << "The parabola has NO roots" << endl;
}
