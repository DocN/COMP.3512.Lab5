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
		cout << num1 << " " << num2 << endl;
		int result = operation->perform(num1, num2);
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
				stringstream integerStream(currentDigit);
				int val = 0;
				integerStream >> val;
				cout << val << endl;
				RPNStack.push(val);
				currentDigit = "";
			}
			else {
				Operation * currentOP;
				if (formula[i] == '+') {
					currentOP = operation_type(formula[i]);
				}
				else if (formula[i] == '+') {
					currentOP = operation_type(formula[i]);
				}
				else if (formula[i] == '+') {
					currentOP = operation_type(formula[i]);
				}
				else if (formula[i] == '+') {
					currentOP = operation_type(formula[i]);
				}
				perform(currentOP);
				currentDigit = "";
			}
		}
		return RPNStack.top();
	}
};