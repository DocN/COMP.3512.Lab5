#pragma once
using namespace std;
class Operation
{
public:
	//operation destructor
	virtual ~Operation() {}
	/**
		get_code - template for get_code 
	*/
	virtual char get_code() = 0;
	/**
		perform - template for perform
	*/
	virtual int perform(int, int) = 0;
};

