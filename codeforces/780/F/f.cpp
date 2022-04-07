#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n; string s;
	cin >> n >> s;
	vector<int> cnt(n+1, 0);
	for(int i = 0; i<n; i++){
		cnt[i+1] = cnt[i] + (s[i]=='+');
	}
	int ans = 0;
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			int p, m;
			p = cnt[j+1]-cnt[i];
			m = j-i+1-p;
			if(m<p) continue;
			if((m-p)%3==0) ans++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}