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
	//class variables
	std::stack<int> RPNStack;

	/**
		perform - The perform function takes in an operation and 
		uses it for RPN calculation and returns the result to the Stack
		Parameter(s) 
			Operation * operation - accepts an operation object to determine the type of operation to perform
		Return
			void
	*/
	void perform(Operation * operation) {
		int num1 = RPNStack.top();
		RPNStack.pop();
		int num2 = RPNStack.top();
		RPNStack.pop();
		int result = operation->perform(num2, num1);
		RPNStack.push(result);
	}
public:
	/**
		RPNCalculator - Default constructor
	*/
	RPNCalculator() {}

	/**
		operation_type - fuction takes in a type of operation and sets up an operation object for doing math
		Parameter(s) 
			int type - The type we want to create an operation object for
		Return
			Operation* - A pointer to the operation object
	*/
	Operation* operation_type(int type) {
		Operation * operation = NULL;
		//case statement for deciding which type of operation object to create
		switch (type)
		{
		case AdditionOperation::OPERATION_CODE:
		  operation = new AdditionOperation();
		  break;
		case SubtractionOperation::OPERATION_CODE:
			operation = new SubtractionOperation();
			break;
		case DivisionOperation::OPERATION_CODE:
			operation = new DivisionOperation();
			break;
		case MultiplicationOperation::OPERATION_CODE:
			operation = new MultiplicationOperation();
			break;
		}

		return operation;
	}

	/**
		process_form - Takes in a formula string of RPN notation and processes it.
		Parameter(s)
			string formula - A string formula that we're processing with the RPN calculator
		Return
			int - the result of the processed formula
	*/
	int process_form(string formula) {
		istringstream iss(formula);
		string token;
		while (iss >> token) {
			istringstream iss2(token);

			int n;
			if (iss2 >> n) {
				RPNStack.push(n);
			}
			else {
				Operation * operation = operation_type(token[0]);
				perform(operation);
			}
		}
		return RPNStack.top();
	}
};