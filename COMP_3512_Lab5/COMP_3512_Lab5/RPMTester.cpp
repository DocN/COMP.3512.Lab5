#include <iostream>
#include "AbstractOperation.hpp"
#include "Operation.hpp"
#include <stack>          // std::stack
#include <iostream>
#include "RPNCalculator.hpp"
using namespace std;

int main() {
	RPNCalculator * test = new RPNCalculator();
	cout << test->process_form("122 123 -") << endl;
	system("pause");
	return 0;
}
