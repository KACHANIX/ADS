// asd.cpp : Defines the entry point for the console application.
//

#include "edx-io.hpp" 
#include <string>
using namespace std;

int main()
{
	int quantity;
	io >> quantity;
	long* elements = new long[quantity];
	char action;
	int last_element = 0;
	int left = 0;
	for (int i = 0; i < quantity; i++) {
		io >> action;
		if (action == '-') { 
			io << elements[left++] << '\n';
		}
		else {
			long number;
			io >> number;
			elements[last_element] = number;
			last_element++;
		}

	}
	return 0;
}

