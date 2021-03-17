#include <bits/stdc++.h>
using namespace std;

void slv() {
	long long n, k;
	cin >> n >> k;
	while(k>3){
		cout << "1 "; 
		k--;n--;
	}
	if(n%2 == 1){
		cout << 1 << " " << n/2 << " " << n/2 << '\n';
	}else{
		if (n%4==0){
			cout << n/2 << " " << n/4 << " " << n/4 << '\n';
		}else{
			cout << 2 << " " << n/2-1 << " " << n/2-1 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
