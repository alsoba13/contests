#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	int n1 = 0;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		n1 += (a[i]==1);
	}
	for(int i = 0; i<q; i++){
		int b, c;
		cin >> b >> c;
		if(b == 1){
			a[c-1]^=1;
			if(a[c-1] == 1) n1++;
			else n1--;
		}else{
			if(c<=n1) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}
