#include "edx-io.hpp" 
//#include "stdafx.h"
#include <string> 
#include <iostream>
using namespace std;


int main()
{
	int quantity;
	io >> quantity;
	char command;

	long* elements = new long[quantity];
	int last = -1;
	int left = 0;
	
	long *mins = new long[quantity];
	int min_last = -1;
	int min_left = 0;

	for (long i = 0; i < quantity; i++) {
		io >> command;

		if (command == '+') {
			io >> elements[++last];
			while (min_last - min_left >= 0 && mins[min_last] > elements[last]) {
				min_last--;
			}
			mins[++min_last] = elements[last];
		}
		else if (command == '-') {

			if (elements[left] == mins[min_left]) {
				min_left++;
			}
			left++;
		}
		else{
			io << mins[min_left] << '\n';
		}
	}
	return 0;
}

