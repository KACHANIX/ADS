// asd.cpp : Defines the entry point for the console application.
//

#include "edx-io.hpp" 
#include <string>
using namespace std;

int main()
{
	int quantity;
	io >> quantity;

	for (int i = 0; i < quantity; i++) {
		string line;
		io >> line;
		bool res = true;
		string curr_line = "";
		for (int j = 0; j < line.length(); j++) {
			char last_el;
			switch (line[j])
			{
			case '(':
				curr_line += "(";
				break;
			
			case '[':
				curr_line += "[";
				break;

			case ']': 
				if (curr_line.length() == 0 || curr_line[curr_line.length() - 1] != '[') {
					res = false;
				}
				curr_line = curr_line.substr(0, curr_line.length() - 1);
				break;

			case ')': 
				if (curr_line.length() == 0 || curr_line[curr_line.length() - 1] != '(') {
					res = false;
				}
				curr_line = curr_line.substr(0, curr_line.length() - 1);
				break;
			}
		}
		if (curr_line.length() != 0) {
			res = false;
		}
		string  answer = (res) ? "YES" : "NO";

		io << answer << '\n';
	}
	return 0;
}

