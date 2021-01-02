#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> &a, vector<int> &b, int x, int n) {
	for(int i = 0; i<x; i++) if (a[i] > b[n-x+i]) return false;
	return true;
}

int bs(vector<int> &a, vector<int> &b, int find_max){
	int n = a.size(), hi = n, lo = 0, mid, res;
	while (lo<=hi) {
		int mid = (lo+hi)/2;
		bool ok = find_max ? f(b, a, mid, n) : f(a, b, mid, n);
		if(ok) {
			res = mid;
			lo = mid+1;
		}else hi = mid-1;
	}
	return res;
}

int main() {
	int t = 0; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n),b;
		for(int i = 0; i<n; i++) cin >> a[i];
		for(int j = 1, i = 0; j<=2*n; j++)
			if (a[i]==j) i++;
			else b.push_back(j);
		cout << bs(a, b, 0) - (n - bs(a, b, 1)) + 1 << endl;
	}
	return 0;
}