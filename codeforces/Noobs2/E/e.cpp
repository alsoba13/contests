#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int g (int n, int l, int h) {
	if(n == 0) return 1;
	vector<int> a(h-l+1, 1);
	for(int t = 0; t<n-1; t++){
		for(int i = 0; i<a.size(); i++){
			for(int j = 0; j<i; j++){
				a[j] = (a[j]+a[i])%MOD;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i<a.size(); i++){
		ans = (ans+a[i])%MOD;
	}
	return ans;
}

int f(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	char c = '1';
	for(int i = 0; i<n; i++){
		if(s[i]!='-') {
			if(s[i]<c) return 0;
			c = max(s[i], c);
		}
	}
	c = '1';
	int cg = 0;
	long long ans = 1;
	for(int i = 0; i<n; i++){
		if (s[i] == '-') cg++;
		else{
			ans = (ans * (g(cg, c-'0', s[i]-'0'))%MOD) % MOD;
			c = s[i];
			cg = 0;
		}
	}
	ans = (ans * (g(cg, c-'0', 9))%MOD) % MOD;
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
