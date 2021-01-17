#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			cout << n-j;
		}
		cout << endl;
	}	
	for(int j = n; j>=0; j--){
		cout << j;
	}
	cout << endl;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n-i; j++){
			cout << n-j;
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
