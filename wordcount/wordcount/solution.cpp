#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // For isspace()

using namespace std;

bool wc(const string& file_name, int& lines, int& words, int& characters) {
    ifstream infile(file_name); // Open file for reading
    
    if (!infile.is_open()) {
        return false; // Return false if the file cannot be opened
    }

    lines = 0;      // Initialize line count
    words = 0;      // Initialize word count
    characters = 0; // Initialize character count

    bool in_word = false; // Flag to track if we are inside a word
    
    char ch;
    while (infile.get(ch)) {
        characters++; // Increment character count

        if (ch == '\n') {
            lines++; // Increment line count on encountering a newline
        }

        if (isspace(ch)) {
            in_word = false; // End of word
        } else if (!in_word) {
            words++; // Start of a new word
            in_word = true; // Mark that we are inside a word
        }
    }

    // If the file ends without a newline, increment line count
    if (characters > 0 && ch != '\n') {
        lines++;
    }

    infile.close(); // Close the file
    return true;    // Return true if everything goes fine
}
/*
int main() {
    int l, w, c;
    string name;

    for (int i = 1; i <= 8; i++) {
        l = w = c = -1;
        name = "in" + to_string(i) + ".txt";
        
        if (wc(name, l, w, c)) {
            cout << "in" << i << ".txt: lines = " << l
                 << ", words = " << w
                 << ", characters = " << c << endl;
        } else {
            cout << "Unable to open in" << i << ".txt\n";
        }
    }

    return 0;
}
*/
