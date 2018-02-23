#include <iostream>
#include "functions.h"
#include <stack>
#include <deque>
#include <string>

/**
 * This class helps maintain brackets [ (), [], {} ]
 * and changes an expression from infix to 
 * postfix [ +, -, /, * ] in any 
 * runnable program
 *
 * @author Alec Allain
 * @version 2/17/18
 */
class stackQueues {
		
	public:
		/**
 		* This method checks each brackets to make sure there's
 		* a corresponding bracket
 		*
 		* @param input is the string the user gives
 		*/ 
		bool balancedSymbols(std::string input) {

			// temporary placeholder for symbol
			char temp;

			// adds elements to stack
			for (auto it = input.begin(); it != input.end(); it++) {
				if (*it == '{' || *it == '(' || *it == '[') {
                                	myStack.push(*it);
                        	}
				else if (*it == '}' || *it == ')' || *it == ']') {
                                	
					// check to see if top of stack is a match
					// return a true or false for corresponding symbol
					switch(*it) {
						case '}':
							temp = myStack.top();
							myStack.pop();
							if (temp == '(' || temp == '[') {
								std::cout << "unbalanced" << std::endl;
								return false;	
							}else {
								return true;
							}
							break;
						case ')':
							temp = myStack.top();
							myStack.pop();
							if (temp == '{' || temp == '[') {
								std::cout << "Unbalanced" << std::endl;
								return false;
							}else{
								return true;
							}
							break;
						case ']':
							temp = myStack.top();
							myStack.pop();
							if (temp == '{' || temp == '(') {
								std::cout << "Unbalanced" << std::endl;
								return false;
							}else {
								return true;
							}
							break;
					}
                        	}
			}
			
			std::cout << "Here are the symbols on the stack (parsing): " << std::endl;
			while (!myStack.empty()) {
				myStack.push(myStack.top());
				myStack.pop();
			}
			
		}
		
		/**
 		* This method changes an infix math expression to postfix
 		*
 		* @param input is the math equation entered by user
 		*/ 
		std::string iToP(std::string input) {
			
			// prints the post fix
			std::string output;

			// checks through the whole string
			for (int i = 0; i < input.length(); i++) {
				
				// checks for braces
				if (input[i] == '(') {
                                	myStack.push(input[i]);
                        	}else if (input[i] == ')') {
					while (myStack.top() != '(') {
						output += myStack.top();
						myStack.pop();
					}
					myStack.pop();
				// checks for symbols
				}else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {
					output += input[i];
				// checks for numbers
				}else if (input[i] >= 0 || input[i] <= 9) {
					myStack.push(input[i]);
					while (!myStack.empty()) {
						output += myStack.top();
						myStack.pop();
					}
				}
			}
			// gives postfix expression
			return output;
		}

	private:

		std::stack<char, std::deque> myStack;
};
