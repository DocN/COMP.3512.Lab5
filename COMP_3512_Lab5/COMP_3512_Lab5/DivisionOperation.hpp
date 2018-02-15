#pragma once
#include "Operation.hpp"
class DivisionOperation : public AbstractOperation {
private:

public:
	static const char OPERATION_CODE = '/';
	DivisionOperation() : AbstractOperation(OPERATION_CODE) {}
	int perform(int x, int y) {
		return (x / y);
	}
	virtual ~DivisionOperation() {}

};