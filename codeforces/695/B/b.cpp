#include <bits/stdc++.h>
using namespace std;

int peak(int a, int b, int c) {
	if(a<b && b>c) return 1;
	if(a>b && b<c) return 1;
	return 0;
}

int peaks(int a, int b, int c, int d, int e) {
	return peak(a, b, c) + peak(b, c, d) + peak(c, d, e);
}

int f() {
	int n;
	cin >> n;
	vector<int> a(n+2);
	for(int i = 0; i<n; i++){
		cin >> a[i+1];
		if(i == 0) a[i] = a[i+1];
		if(i == n-1) a[i+2] = a[i+1];
	}
	int maxwin = 0, ans = 0;
	for(int i = 2; i<n+1; i++) {
		ans += peak(a[i-1], a[i], a[i+1]);
		maxwin = max(maxwin, peaks(a[i-2], a[i-1], a[i], a[i+1], a[i+2])-peaks(a[i-2], a[i-1], a[i+1], a[i+1], a[i+2]));
		maxwin = max(maxwin, peaks(a[i-2], a[i-1], a[i], a[i+1], a[i+2])-peaks(a[i-2], a[i-1], a[i-1], a[i+1], a[i+2]));
	}
	return ans-maxwin;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
