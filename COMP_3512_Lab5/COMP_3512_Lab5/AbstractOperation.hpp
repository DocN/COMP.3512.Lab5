#pragma once
#include "Operation.hpp"
class AbstractOperation : public Operation
{
private:
	char operation_type; 
public: 
	AbstractOperation(char operation) {
		operation_type = operation;
	}
	~AbstractOperation() {}
	char get_code() {
		return operation_type;
	}
	
};