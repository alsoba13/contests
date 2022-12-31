#include <bits/stdc++.h>
using namespace std;

string f(long long n) {
	long long k;
	cin >> k;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	long long w = 0;
	long long ans_w = 0;
	int ans = -1;
	for(int i = 0; i<k; i++) {
		w += a[i];
	}
	int pi = 0;
	long long w_i = a[0], w_j = w-a[0];
	while(w_i<w_j) {
		pi++;
		w_i += a[pi];
		w_j -= a[pi];
	}
	if(w_i == w_j && w > ans_w) {
		ans = 1;
		ans_w = w;
	}
	for(int i = k; i<n; i++) {
		long long to_add = a[i];
		long long to_remove = a[i-k];

		w_i -= to_remove;
		w_j += to_add;
		w += to_add - to_remove;
		while(w_i<w_j) {
			pi++;
			w_i += a[pi];
			w_j -= a[pi];
		}
		if(w_i == w_j && w > ans_w) {
			ans = i-k+2;
			ans_w = w;
		}
	}
	if(ans == -1) return "SIN ADORNOS";
	return to_string(ans);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		int n;
		cin >> n;
		if(cin.eof()) break;
		cout << f(n) << '\n';
	}
	return 0;
}