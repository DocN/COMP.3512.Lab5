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
		case '-':
			operation = new SubtractionOperation();
		case '/':
			operation = new DivisionOperation();
		case '*':
			operation = new MultiplicationOperation();
		}

		return operation;
	}

	int process_form(string formula) {
		string currentTotal = "";

		for (int i = 0; i < formula.length(); i++) {
			char currentChar = formula[i];
			if (currentChar == ' ') {
				bool isNumber = true;
				if (currentTotal.length() == 1) {
					char totalChar = currentTotal[0];
					if (totalChar == '/' || totalChar == '*' || totalChar == '-' | totalChar == '+') {
						isNumber = false;
						Operation * currentOperation = operation_type(totalChar);
						perform(currentOperation);
					}
				}
				if (isNumber) {
					istringstream buffer(currentTotal);
					int value;
					buffer >> value;
					RPNStack.push(value);
				}
			}
		}
		return 0;
	}
};