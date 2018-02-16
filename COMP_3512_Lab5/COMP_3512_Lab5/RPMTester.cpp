#include <iostream>
#include "AbstractOperation.hpp"
#include "Operation.hpp"
#include <stack>          // std::stack
#include <iostream>
#include "RPNCalculator.hpp"
using namespace std;

int main() {
	RPNCalculator * test = new RPNCalculator();
	//example cases
	cout << "Example Test Cases " << endl;
	cout << "2 3 4 * -" << endl;
	cout << test->process_form("2 3 4 * -") << endl;
	cout << "2 3 - 4 *" << endl;
	cout << test->process_form("2 3 - 4 *") << endl;
	
	cout << "Enter your formula: " << endl;
	string formula;
	getline(std::cin, formula);
	cout << "You entered " << formula << endl;
	cout << "The result is " << endl;
	cout << test->process_form(formula) << endl;

	system("pause");
	return 0;
}
