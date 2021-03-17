#include <bits/stdc++.h>
using namespace std;

void slv(){
	int n;
	cin >> n;
	vector<int> c(101);
	vector<int> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for(int i = 0; i<=100; i++){
		if(c[i]>0){
			cout << i << " ";
			c[i]--;
		}
	}
	for(int i = 0; i<=100; i++){
		while(c[i]>0){
			cout << i << " ";
			c[i]--;
		}
	}
	cout << '\n';
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
