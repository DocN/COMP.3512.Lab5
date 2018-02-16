#pragma once
#include "Operation.hpp"
using namespace std;
class AbstractOperation : public Operation
{
private:
	//class variables
	char operation_type; 
public: 
	/**
		AbstractOperation - Constructor that takes in operation type char
	*/
	AbstractOperation(char operation) {
		operation_type = operation;
	}
	/**
		AbstractOperation - Destructor
	*/
	~AbstractOperation() {}

	/**
		get_code - getter for operation_type
		Parameters
		Return
			char - the operation type 
	*/
	char get_code() {
		return operation_type;
	}
};