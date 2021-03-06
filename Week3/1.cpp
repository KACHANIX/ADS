#include <fstream>
using namespace std;
#define NULL nullptr


void radix_sort(long *array, int size, long maxNum) {
	int digit = 1;
	while (maxNum >> digit > 0) {
		digit++;
	}
	digit--;
	long *count = new long[256];
	long *output = new long[size];
	for (int pow = 0; pow <= digit; pow += 8) {
		for (int i = 0; i < 256; i++) {
			count[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			count[(array[i] >> pow) & 255]++;
		}
		for (int i = 1; i < 256; i++) {
			count[i] += count[i - 1];
		}
		for (int i = size - 1; i >= 0; i--) {
			output[count[(array[i] >> pow) & 255] - 1] = array[i];
			count[(array[i] >> pow) & 255]--;
		}
		for (int i = 0; i < size; i++) {
			array[i] = output[i];
		}
	}
}

int main() {
	int firstLen, secondLen;

	ifstream input("input.txt");
	input >> firstLen >> secondLen;

	long *firstArray = new long[firstLen]; 
	long *finalArray = new long[firstLen * secondLen];

	long maxA = 0;
	for (int i = 0; i < firstLen; i++) {
		input >> firstArray[i];
		if (firstArray[i] > maxA) {
			maxA = firstArray[i];
		}
	}
	long maxB = 0; 
	long a;

	for (int i = 0; i < secondLen; i++) {
		input >> a; 
		for (int j = 0; j < firstLen; j++) { 
			finalArray[(i * firstLen) + j] = a * firstArray[j];
		}
		if (a > maxB) {
			maxB = a;
		}
	}
	firstArray = NULL; 
	input.close();

	long maxNum = maxA * maxB;
	
	radix_sort(finalArray, firstLen*secondLen, maxNum);
	 
	long long sum = 0;

	for (int i = 0; i < firstLen * secondLen  ; i += 10) {
		sum += finalArray[i];
	}
	ofstream output("output.txt");
	output << sum;
	output.close();

	return 0;
}