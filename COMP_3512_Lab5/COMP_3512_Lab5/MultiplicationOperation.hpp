#pragma once
#include "Operation.hpp"
class MultiplicationOperation : public AbstractOperation {
private:

public:
	static const char OPERATION_CODE = '*';
	MultiplicationOperation() : AbstractOperation(OPERATION_CODE) {}
	int perform(int x, int y) {
		return (x * y);
	}
	virtual ~MultiplicationOperation() {}
};