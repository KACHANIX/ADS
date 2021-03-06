 #include <fstream>
#include <string> 
#include "edx-io.hpp" 
using namespace std;


int main() { 
	long n, m, k;
	io >> n >> m >> k;

	string *A = new std::string[m];
	for (long i = 0; i < m; i++) {
		io >> A[i];
	}

	long *Pos = new long[n];
	long *Pos2 = new long[n]; 
	long *Controller[2] = { Pos, Pos2 }; 
	int pIn = 0;
	for (long i = 0; i < n; i++) {
		Pos[i] = i;
	}

	int *count = new int[123]; 
	for (int j = m - 1; m - j <= k; j--) { 
		for (int i = 97; i < 123; i++) {
			count[i] = 0;
		}

		for (int i = 0; i < n; i++) { 
			count[A[j][Controller[pIn][i]]]++;
		}

		for (int i = 98; i < 124; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) { 
			Controller[1 - pIn][--count[A[j][Controller[pIn][i]]]] = Controller[pIn][i];
		} 
		pIn = ~pIn & 1;

	} 
	ofstream output("output.txt");
	for (long i = 0; i < n; i++) {
		output << Controller[pIn][i] + 1 << ' ';
	}
	output.close();

	return 0;
}