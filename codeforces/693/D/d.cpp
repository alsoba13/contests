#include <bits/stdc++.h>
using namespace std;

string f(){
	int n;
	cin >> n;
	long long alice = 0, bob = 0;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	for(int i = 0; i<n; i++){
		if (i%2 == a[i]%2){
			if (i%2 == 0) alice += a[i];
			else bob += a[i];
		}
	}
	if (alice > bob) return "Alice";
	if (bob > alice) return "Bob";
	return "Tie";
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}