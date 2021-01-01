#include <bits/stdc++.h>
using namespace std;

int f() {
	string w;
	cin >> w;
	int c = 0;
	for (int i = 1; i < w.size(); i++) {
		if(w[i-1] == w[i] || w[max(i-2, 0)] == w[i]){
			w[i] = 'A';
			c++;
		}
	}
	return c;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
