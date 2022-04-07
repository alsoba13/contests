#include <bits/stdc++.h>
using namespace std;

int f(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	int ko = 0;
	vector<int> cnt(26,0);
	for(int i = 0; i<n; i++) {
		int l = s[i]-'a';
		if(cnt[l] == 1) {
			if(ko)for(int j = 0; j<26; j++) cnt[j] = 0;
			ans += ko-1;
			ko = 0;
		}else{
			ko++;
			cnt[l]++;
		}
	}
	return ans+ko;
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
