#pragma once
#include "AbstractOperation.hpp"
using namespace std;
class SubtractionOperation : public AbstractOperation {
private:

public:
	static const char OPERATION_CODE = '-';
	SubtractionOperation() : AbstractOperation(OPERATION_CODE) { }
	int perform(int x, int y) override {
		return (x - y);
	}	
	virtual ~SubtractionOperation() {}
};