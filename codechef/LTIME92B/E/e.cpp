#include <bits/stdc++.h>
using namespace std;

bool f(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i*i<=m; i++){
		if(m%i==0){
			if(i<=n && m/i<=n) return true;
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
