#include <bits/stdc++.h>
using namespace std;

int f() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(2,0);
	for(int i = 0; i<n; i++)
		cnt[s[i]-'0']++;
	if(cnt[0]!=cnt[1]) return min(cnt[0], cnt[1]);
	return cnt[0]-1;
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
