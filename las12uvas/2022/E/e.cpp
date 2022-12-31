#include <bits/stdc++.h>
using namespace std;

long long f(int n) {
	string s = to_string(n);
	vector<long long> p(10);
	for(int i = 0; i<10; i++) cin >> p[i];
	vector<long long> sum(10, 0);
	for(int i = 0; i<4; i++) {
		sum[s[i]-'0']++;
	}
	long long sol = 1000000100;
	for(int i = 0; i<10; i++) {
		if(sum[i] == 0) continue;
		sol = min(sol, p[i]/(sum[i]*3));
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		cout << f(n) << '\n';
	}
	return 0;
}