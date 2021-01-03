#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, sol1, sol2;
	cin >> N;
	vector<int> entries(N);
	for (int i = 0; i < N; i++)
		cin >> entries[i];
	for (int i = 0; i < N; i++) 
		for (int j = i + 1; j < N; j++) {
			if (entries[i] + entries[j] == 2020) 
				sol1 = entries[i] * entries[j];
			for (int k = j + 1; k < N; k++) 
				if (entries[i] + entries[j] + entries[k] == 2020) 
					sol2 = entries[i] * entries[j] * entries[k];
		}
	cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}
