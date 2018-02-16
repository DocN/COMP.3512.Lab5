#pragma once
#include "AbstractOperation.hpp"
#include "AdditionOperation.hpp"
#include "SubtractionOperation.hpp"
#include "MultiplicationOperation.hpp"
#include "DivisionOperation.hpp"
#include "Operation.hpp"
#include <stack>          // std::stack
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class RPNCalculator {
private:
	int result;
	std::stack<int> RPNStack;
	void perform(Operation * operation) {
		int num1 = RPNStack.top();
		RPNStack.pop();
		int num2 = RPNStack.top();
		RPNStack.pop();
		int result = operation->perform(num2, num1);
		RPNStack.push(result);
	}
public:
	RPNCalculator() {
	}
	Operation* operation_type(int type) {
		Operation * operation = NULL;
		switch (type)
		{
		case '+':
		  operation = new AdditionOperation();
		  break;
		case '-':
			operation = new SubtractionOperation();
			break;
		case '/':
			operation = new DivisionOperation();
			break;
		case '*':
			operation = new MultiplicationOperation();
			break;
		}
		
		return operation;
	}

	int process_form(string formula) {
		string currentDigit = "";
		for (int i = 0; i < formula.length(); i++) {
			if(isdigit(formula[i])) {
				currentDigit = currentDigit + formula[i];
			}
			//in the event we have a space
			else if (formula[i] == ' ') {
				if (currentDigit.length() == 0) {
					continue;
				}
				stringstream integerStream(currentDigit);
				int val = 0;
				integerStream >> val;
				RPNStack.push(val);
				currentDigit = "";
			}
			else {
				//check if the operator is a negative part of a number
				bool digitOperator = false;
				if (currentDigit.length() == 0 && formula[i] == '-') {
					if ((i+1) < formula.length()) {
						if (isdigit(formula[i + 1])) {
							digitOperator = true;
							currentDigit = currentDigit + formula[i];
						}
					}
				}
				if (digitOperator == false) {
					Operation * currentOP = NULL;
					if (formula[i] == '+') {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == '-') {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == '*') {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == '/') {
						currentOP = operation_type(formula[i]);
					}
					if (currentOP != NULL) {
						perform(currentOP);
					}
					currentDigit = "";
				}
			}
		}
		return RPNStack.top();
	}
};