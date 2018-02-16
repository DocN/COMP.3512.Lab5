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
		string currentDigit = "";
		//loop through all the chars of the formula string
		for (int i = 0; i < formula.length(); i++) {
			//check if the current char is a digit
			if(isdigit(formula[i])) {
				//if it's a digit then add it to the current digit
				currentDigit = currentDigit + formula[i];
			}
			//in the event we have a space
			else if (formula[i] == ' ') {
				//check if there's anything there
				if (currentDigit.length() == 0) {
					continue;
				}

				//convert the current digit from string to int via streams
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
					//find out what type of operation we're dealing with
					Operation * currentOP = NULL;
					if (formula[i] == AdditionOperation::OPERATION_CODE) {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == SubtractionOperation::OPERATION_CODE) {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == MultiplicationOperation::OPERATION_CODE) {
						currentOP = operation_type(formula[i]);
					}
					else if (formula[i] == DivisionOperation::OPERATION_CODE) {
						currentOP = operation_type(formula[i]);
					}
					if (currentOP != NULL) {
						perform(currentOP);
					}
					currentDigit = "";
				}
			}
		}
		//return the result that's on the top of our stack
		return RPNStack.top();
	}
};