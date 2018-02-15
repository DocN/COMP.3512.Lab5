#pragma once
class Operation
{
public:
	virtual ~Operation() {}
	virtual char get_code() = 0;
	virtual int perform(int, int) = 0;
	//virtual void OverrideMe() = 0;
};

