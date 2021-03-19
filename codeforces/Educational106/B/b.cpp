#include <bits/stdc++.h>
using namespace std;

bool f() {
	string s;
	cin >> s;
	int n = s.size();
	int first_ones = n+1;
	int first_zeros = -1;
	for(int i = 1; i<n; i++){
		if(s[i]=='1' && s[i-1]=='1'){
			first_ones = i-1;
			break;
		}
	}
	for(int i = n-2; i>=0; i--){
		if(s[i]=='0' && s[i+1]=='0'){
			first_zeros = i+1;
			break;
		}
	}
	return first_ones>first_zeros;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
