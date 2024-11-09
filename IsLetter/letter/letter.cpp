#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int score;
    char letter_grade = 'X';

    // Get the score from the user
    cout << "What is the test score? ";
    cin >> score;

    // Determine the letter grade (write your code after this line)
    if (score >= 92)
    {
        letter_grade = 'A';
        cout << endl << "The score " << score << " earns the grade " << letter_grade << endl;
    }
    else if (score >= 84)
    {
        letter_grade = 'B';
        cout << endl << "The score " << score << " earns the grade " << letter_grade << endl;
    }
    else if (score >= 76)
    {
        letter_grade = 'C';
        cout << endl << "The score " << score << " earns the grade " << letter_grade << endl;
    }
    else if (score >= 68)
    {
        letter_grade = 'D';
        cout << endl << "The score " << score << " earns the grade " << letter_grade << endl;
    }
    else
    {
        letter_grade = 'F';
        cout << endl << "The score " << score << " earns the grade " << letter_grade << endl;
    }

    // Display the score and letter grade

    return 0;
}
