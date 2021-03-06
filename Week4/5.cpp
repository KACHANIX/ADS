//#include "stdafx.h"
#include <fstream>
#include <string> 
#include <iostream>
#include <queue>
#include <map>
using namespace std;


int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	map<char, unsigned short> regs = {
	{'a', 0},
	{'b', 0},
	{'c', 0},
	{'d', 0},
	{'e', 0},
	{'f', 0},
	{'g', 0},
	{'h', 0},
	{'i', 0},
	{'j', 0},
	{'k', 0},
	{'l', 0},
	{'m', 0},
	{'n', 0},
	{'o', 0},
	{'p', 0},
	{'q', 0},
	{'r', 0},
	{'s', 0},
	{'t', 0},
	{'u', 0},
	{'v', 0},
	{'w', 0},
	{'x', 0},
	{'y', 0},
	{'z', 0}
	};
	queue<unsigned short> queue = {};
	map<string, long> labels;
	string* actions = new string[100001];

	long ind = -1;
	while (!input.eof()) {
		input >> actions[++ind]; 
		if (actions[ind][0] == ':') {
			labels.insert(pair<string, long>(actions[ind].substr(1), ind));
		}
	}
	if (actions[ind].empty()) {
		ind--;
	}
	input.close(); 
	long P = 0;
	unsigned short num1, num2;

	do {
		switch (actions[P][0])
		{
		case '+':
			num1 = queue.front();
			queue.pop();
			num2 = queue.front();
			queue.pop();
			queue.push((num1 + num2) % 65536);
			P++;
			break;
		case '-':
			num1 = queue.front();
			queue.pop();
			num2 = queue.front();
			queue.pop();
			queue.push((num1 - num2) % 65536);
			P++;
			break;
		case '*':
			num1 = queue.front();
			queue.pop();
			num2 = queue.front();
			queue.pop();
			queue.push((num1 * num2) % 65536);
			P++;
			break;
		case '/':
			num1 = queue.front();
			queue.pop();
			num2 = queue.front();
			queue.pop();
			if (num2 == 0) {
				queue.push(0);
			}
			else {
				queue.push(num1 / num2);
			}
			P++;
			break;
		case '%':
			num1 = queue.front();
			queue.pop();
			num2 = queue.front();
			queue.pop();
			if (num2 == 0) {
				queue.push(0);
			}
			else {
				queue.push(num1 % num2);
			}
			P++;
			break;
		case '>':
			num1 = queue.front();
			queue.pop();
			regs[actions[P][1]] = num1;
			P++;
			break;
		case '<':
			queue.push(regs[actions[P][1]]);
			P++;
			break;
		case 'P':
			if (actions[P].size() == 1) {
				output << queue.front() << '\n';
				queue.pop();
			}
			else {
				output << regs[actions[P][1]] << '\n';
			}
			P++;
			break;
		case 'C':
			if (actions[P].size() == 1) {
				output << (char)(queue.front() % 256);
				queue.pop();
			}
			else {
				output << (char)(regs[actions[P][1]] % 256);
			}
			P++;
			break;
		case ':':
			P++;
			break;
		case 'J':
			P = labels[actions[P].substr(1)] + 1;
			break;
		case 'Z':
			if (regs[actions[P][1]] == 0) {
				P = labels[actions[P].substr(2)] + 1;
			}
			else {
				P++;
			}
			break;
		case 'E':
			if (regs[actions[P][1]] == regs[actions[P][2]]) {
				P = labels[actions[P].substr(3)] + 1;
			}
			else {
				P++;
			}
			break;
		case 'G':
			if (regs[actions[P][1]] > regs[actions[P][2]]) {
				P = labels[actions[P].substr(3)] + 1;
			}
			else {
				P++;
			}
			break;
		case 'Q':
			P = ind;
			P++;
			break;
		default:
			queue.push(stoi(actions[P]));
			P++;
		} 
	} while (P <= ind);
	output.close();

	return 0;
}

