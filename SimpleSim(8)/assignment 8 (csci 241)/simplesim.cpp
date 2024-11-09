//********************************************************************
//
// simplesim.cpp
// CSCI 241 Assignment 8
//
// Created by Hamzah Subhani (2010017)
//
//********************************************************************

#include <iostream>
#include <iomanip>
#include "simplesim.h" // header file
#include "sml.h" // header file

using std::cin;
using std::cout;
using std::endl;
using std::internal;
using std::setfill;
using std::setw;
using std::showpos;
using std::noshowpos;

/**simplesim
 *
 * Initializes the Simplesim's memory to default values.
 *
 *@ param none
 *
 *@ return nothing
 */
simplesim::simplesim()
{
    for (int i = 0; i < 100; i++)
    {
        memory[i] = DEFAULT;
    }

    accumulator = 0; // intializing all registers to 0.
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;
}

/**load_program
 *
 * Loads an SML program into the Simplesim's memory.
 *
 * @ param none
 *
 * @return Returns true if a valid program is successfully loaded into
 *         memory; otherwise, false.
 */
bool simplesim::load_program()
{
    int count = 0;          // Instruction count.
    int instruction = 0;    // Holds instruction read.

    // While not EOF and we have not encountered the sentinel value...
    while (cin >> instruction && instruction != -99999)
    {
        // Check for an invalid word. If invalid, print error message
        // and return false.
        if (instruction < -9999 || instruction > 9999)
        {
            cout << "*** ABEND: pgm load: invalid word ***" << endl;
            return false;
        }

        // Check for too large a program. If count is outside the
        // boundaries of the memory array, print error message and
        // return false.
        if (count >= 100)
        {
            cout << "*** ABEND: pgm load: pgm too large ***" << endl;
            return false;
        }

        // Add the instruction to the memory array at subscript count.
        memory[count] = instruction;

        // Increment instruction count by 1.
        count++;
    }

    return true; // Successful if no errors occurred.
}

/** execute_program
 *
 * Executes an SML program loaded into the Simplesim's memory.
 *
 * @ param none
 *
 * @ return nothing
 */
void simplesim::execute_program()
{
    bool done = false;

    while (!done)
    {
        if (instruction_counter < 0 || instruction_counter >= 100)
        {
            cout << "*** ABEND: addressability error ***" << endl; // checks for valid memory location
            dump();
            return;
        }
        
        // load the instruction_register with that word from memory and split the instruction_register by placing its leftmost two digits into the operation_code register and its rightmost two digits into the operand register
    
        instruction_register = memory[instruction_counter];
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;
        int new_value; // used for result from multiple arithemtic operations

        switch (operation_code)
        {
            case READ: // for reading the input
                cin >> memory[operand];
                if (memory[operand] < -9999 || memory[operand] > 9999)
                {
                    cout << "*** ABEND: illegal input ***" << endl;
                    memory[operand] = 0;
                    return;
                }
                // Print formatted READ output with leading zeros
                cout << "READ: " << setw(5) << internal << setfill('0') << showpos << memory[operand] << endl;
                break;

            case WRITE: // for writig output out
                // Print formatted WRITE output with leading zeros
                cout << setw(5) << internal << setfill('0') << showpos << memory[operand] << endl;
                break;

            case ADD: // adds accumulator and operand from memory array
                new_value = accumulator + memory[operand];
                if (new_value < -9999)
                {
                    cout << "*** ABEND: underflow ***" << endl; // if value is under limit
                    return;
                }
                if (new_value > 9999)
                {
                    cout << "*** ABEND: overflow ***" << endl; // if value is over limit
                    return;
                }
                accumulator = new_value; // for all arithmetic, the new value will be added based on conditions
                break;

            case SUBTRACT: //subtracts accumulator from operand from memory array
                new_value = accumulator - memory[operand];
                if (new_value < -9999)
                {
                    cout << "*** ABEND: underflow ***" << endl;
                    return;
                }
                if (new_value > 9999)
                {
                    cout << "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = new_value;
                break;

            case MULTIPLY: // multiplies accumulator and operand from memory array
                new_value = accumulator * memory[operand];
                if (new_value < -9999)
                {
                    cout << "*** ABEND: underflow ***" << endl;
                    return;
                }
                if (new_value > 9999)
                {
                    cout << "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = new_value;
                break;

            case DIVIDE: // divides accumulator from operand from memory array
                if (memory[operand] == 0)
                {
                    cout << "*** ABEND: attempted division by 0 ***" << endl;
                    return;
                }
                new_value = accumulator / memory[operand];
                if (new_value < -9999)
                {
                    cout << "*** ABEND: underflow ***" << endl;
                    return;
                }
                if (new_value > 9999)
                {
                    cout << "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = new_value;
                break;

            case BRANCH:
                instruction_counter = operand;
                break;

            case BRANCHNEG:
                if (accumulator < 0)
                {
                    instruction_counter = operand;
                }
                else
                {
                    instruction_counter++; // increment instruction counter 
                }
                break;

            case BRANCHZERO:
                if (accumulator == 0)
                {
                    instruction_counter = operand;
                }
                else
                {
                    instruction_counter++;
                }
                break;

            case HALT:
                done = true;
                break;

            default:
                cout << "*** ABEND: invalid opcode ***" << endl;
                return;
        }

        if (!done && operation_code != BRANCH && operation_code != BRANCHNEG && operation_code != BRANCHZERO) // if none of the branch codes were met
        {
            instruction_counter++;
        }
    }

    cout << "*** Simplesim execution terminated ***\n";
}

/**dump
 *
 * Prints the contents of the Simplesim's registers and memory.
 *
 * @ param none
 *
 * @ return nothing
 */
void simplesim::dump() const
{
    // Print registers.
    cout << endl;
    cout << "REGISTERS: " << endl;
    cout << "accumulator:            " << showpos << internal << setfill('0') << setw(5) << accumulator << endl;
    cout << "instruction_counter:    " << noshowpos << setfill('0') << setw(2) << instruction_counter << endl;
    cout << "instruction_register:   " << showpos << setfill('0') << setw(5) << instruction_register << endl;
    cout << "operation_code:         " << noshowpos << setw(2) << operation_code << endl;
    cout << "operand:                " << setw(2) << operand << endl;
    cout << endl;

    // Print memory.
    cout << "MEMORY: " << endl;
    cout << "       0     1     2     3     4     5     6     7     8     9\n"; // for rows
    for (int i = 0; i < 100; i++)
    {
        if (i % 10 == 0 && i != 0) // for columns
        {
            cout << noshowpos << setw(2) << i << " ";
        }
        else if (i == 0)
        {
            cout << " " << noshowpos << i << " ";
        }
        cout << setw(5) << showpos << memory[i] << " "; // prints memory components
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
}
