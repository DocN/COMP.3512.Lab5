#pragma once
#include "Operation.hpp"
class DivisionOperation : public AbstractOperation {
private:

public:
	//type of operation code 
	static const char OPERATION_CODE = '/';

	//DivisionOperation - Constructor that calls parent with the op code
	DivisionOperation() : AbstractOperation(OPERATION_CODE) {}

	/**
	perform - function takes in an x and y value and performs the OPERATION_CODE
	Parameters
		int x - the first value
		int y - the second value
	Return
		int  - the result after the operation of x and y
	*/
	int perform(int x, int y) {
		return (x / y);
	}

	/**
		~DivisionOperation - virtual destructor
	*/
	virtual ~DivisionOperation() {}

};