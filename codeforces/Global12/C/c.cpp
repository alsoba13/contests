#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, k = 0;
	cin >> n;
	vector<string> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) k += (t[i][j] != '.' ? 1 : 0);
	int mod;
	for (mod = 0; mod < 3; mod++) {
		int c = 0;
		for (int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if ((i + j) % 3 == mod && t[i][j] == 'X') c++;
		if (c <= k/3) break;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 3 == mod && t[i][j] == 'X') t[i][j] = 'O';
	for (int i = 0; i < n; i++)
		cout << t[i] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}