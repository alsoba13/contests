#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i<n; i++)
		cout << "abc"[i%3];
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}