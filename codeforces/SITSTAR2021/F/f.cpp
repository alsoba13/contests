#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	long long a = (1<<n);
	for(int i = 0; i<a; i++){
		string b = "";
		for(int k = 0; k<n-1; k++) b += ((i>>k)&1)==1?"1":"2";
		b += '2';
		if(stoll(b)%a==0) {
			cout << b << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
