#include <bits/stdc++.h>
using namespace std;

bool f() {
	int a, b;
	cin >> a >> b;
	for(int i = 0; i<30; i++){
		if ( (a&(1<<i))==(b&(1<<i)) && (a&(1<<i))>0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"Yes":"No") << '\n';
	}
	return 0;
}
