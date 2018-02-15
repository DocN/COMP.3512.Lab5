#pragma once
#include "AbstractOperation.hpp"
class SubtractionOperation : public AbstractOperation {
private:

public:
	static const char OPERATION_CODE = '-';
	SubtractionOperation() : AbstractOperation(OPERATION_CODE) {}
	int perform(int x, int y) {
		return (x - y);
	}	
	virtual ~SubtractionOperation() {}
};