//***************************************************************************
//
//  eval.cpp
//  CSCI 241 Assignment 14
//
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************
#include "eval.h"
#include "mystack.h"

/* evaluate
 *
 * Evaluates a postfix expression represented as a string based on certain conditions, if they are, the expression is pushed onto a stack which will hold all the final expressions.
 *
 * @param const string& postfix -  string representing the postfix expression to evaluate
 *
 * @return int - evaluated result of the postfix expression
 */

int evaluate (const string& postfix)
{
    mystack eval_stack; // stack that will hold postfix notation at the end
    string op; // character to be evaluated
    stringstream ss(postfix); // string stream to convert integers to strings

    while (ss >> op) // while reading input
    {
        int value;

        if (isdigit(op[0])) // if character is a digit
        {
            eval_stack.push(stoi(op)); // converts string to integer
        }
        else if (isalpha(op[0])) // if character is a letter
        {
            value = op[0] - 'a'; // new value to be pushed on stack
            eval_stack.push(value);
        }
        else if (op == "~")
        {
            if (!eval_stack.empty())
            {
                int value = eval_stack.top(); // get the top value
                eval_stack.pop(); // remove it from stack
                eval_stack.push(-value); // push negated value
            }
        }
        else
        {
            int rightop = eval_stack.top(); // get right operand
            eval_stack.pop(); // remove it from stack
            int leftop = eval_stack.top(); // get left operand
            eval_stack.pop(); // remove it from stack

            // left and right op will be altered based on the arithmetic
            if (op == "+")
            {
                eval_stack.push(leftop + rightop);
            }
            else if (op == "-")
            {
                eval_stack.push(leftop - rightop);
            }
            else if (op == "*")
            {
                eval_stack.push(leftop * rightop);
            }
            else if (op == "/")
            {
                if (rightop != 0)
                {
                    eval_stack.push(leftop / rightop);
                }
                else
                {
                    cout << "*** Division by 0 ***" << endl;
                    eval_stack.push(0); // push 0 because dividing by 0 is not possible
                }
            }
            else if (op == "^")
            {
                int result = 1;

                for (int i = 0; i < rightop; i++)
                {
                    result *= leftop; // calculate power result manually
                }

                eval_stack.push(result); // push the result onto the stack
            }
        }
    }

    return eval_stack.top(); // evaluated result
}
