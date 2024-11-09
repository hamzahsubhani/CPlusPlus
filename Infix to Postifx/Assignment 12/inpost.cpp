//***************************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 12
//
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************

#include <string> // string type
#include <cctype> // isdigit, islower
#include "inpost.h" // header file for convert and precedence
#include "mystack.h" // header file for mystack class

/* convert
 *
 * converts an infix expression to postfix notation using a stack by reading through a string. Then builds a postfix expression as a string.
 *
 * @param const string &infix - a const referecne to a string representing the infix expression to be converted.
 *
 * @return string postfix - contains the converted postfix expression. if the input infix expression is empty or invalid, an empty string is returned.
 *
 * @note this function works only assumingly that it will need the help of finding the operator with priority based on precedence.
 */

string convert (const string& infix)
{
    string postfix; // string to write and append to
    mystack s; // creating stack object
    size_t indx = 0; // index for iterating through the infix expression

    while (indx < infix.length()) // loop through each character in the infix expression
    {
        if (islower(infix[indx])) // if the character is a lowercase letter
        {
            postfix += infix[indx]; // append the letter to the postfix string.
            postfix += ' '; // append a space after the letter.
            indx++; // move to the next character.
        }
        
        else if (isdigit(infix[indx])) // if the character is a digit
        {
            while (isdigit(infix[indx])) // loop through all consecutive digits
            {
                postfix += infix[indx];
                indx++;
            }
            postfix += ' ';
        }
        
        else if (infix[indx] == ' ') //  if the character is a space
        {
            indx++;
        }
        
        else if (infix[indx] == '(') // if the character is an opening parenthesis
        {
            s.push(infix[indx]); // push the parenthesis onto the stack.
            indx++;
        }
        
        else if (infix[indx] == ')') // if the character is a closing parenthesis.
        {
            while (!s.empty() && s.top() != '(') // pop from stack until the opening parenthesis is found.
            {
                postfix += s.top(); // append the top of stack to postfix.
                postfix += ' ';
                s.pop(); // remove operator from the stack.
            }
            if (!s.empty()) // remove the opening parenthesis from the stack.
            {
                s.pop();
            }
            
            indx++;
        }
        
        else // character is an operator.
        {
            while (!s.empty() && precedence(infix[indx]) <= precedence(s.top())) // Compare precedence of operators.
            {
                postfix += s.top(); // Append the operator to postfix.
                postfix += ' '; // Append a space after the operator.
                s.pop(); // Remove the operator from the stack.
            }
            
            s.push(infix[indx]); // push current operator onto the stack.
            indx++;
        }
    }
    
    while (!s.empty()) // pop all remaining operators from the stack.
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    
    if (!postfix.empty() && postfix.back() == ' ') // remove the trailing space if possible
    {
        postfix.pop_back();
    }
    
    return postfix; // return final postfix expression
}

/* precedence
 *
 * determines the precedence level of a given operator. 3 is highest, 1 is lowest
 *
 * @param char op - operator character whose precedence is being checked
 *
 * @return integer representing the precedence level of the operator, -1 if invalid
 *
 */

int precedence (char op)
{
    switch (op)
    {
        case '~':
        case '^': // exponentation and unary negation have the highest precedence.
            return 3;
        case '*':
        case '/': // multiplication and division have medium precedence.
            return 2;
        case '+':
        case '-': // addition and subtraction have the lowest precedence.
            return 1;
        default: // invalid operator.
            return -1;
    }
}
