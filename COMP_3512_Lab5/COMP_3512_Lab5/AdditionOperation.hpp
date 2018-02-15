#pragma once
#include "Operation.hpp"
class AdditionOperation : public AbstractOperation {
private:
	
public:
	static const char OPERATION_CODE = '+';
	AdditionOperation() : AbstractOperation(OPERATION_CODE) {}
	int perform(int x, int y) {
		return (x + y);
	}
	virtual ~AdditionOperation() {}
};