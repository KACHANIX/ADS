#include "edx-io.hpp" 
#include <fstream>
#include <string> 
#include <iostream> 
using namespace std;


int main()
{ 
	int quantity;
	io >> quantity;
	long *numbers = new long[quantity];
	for (int i = 0; i < quantity; i++) {
		io >> numbers[i]; 
	}
	bool answer = true;
	for (int i = quantity / 2 - 1; i >= 0 && answer; i--) {

		if ((i + 1) * 2 - 1 < quantity && numbers[(i + 1) * 2 - 1] < numbers[i])
			answer = false;

		if ((i + 1) * 2 < quantity && numbers[(i + 1) * 2] < numbers[i])
			answer = false; 
	}
	if (answer)
		io << "YES";
	else
		io << "NO";
	return 0;
}

