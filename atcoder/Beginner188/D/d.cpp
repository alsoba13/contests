#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; long long C;
	cin >> n >> C;
	map<long long, long long> s;
	for(int i = 0; i<n; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		s[a]+=c;
		s[b+1]-=c;
	}
	long long ans = 0;
	long long p = s.begin()->second;
	long long d = s.begin()->first;
	map<long long, long long>::iterator i = s.begin();
	i++;
	for(;i!=s.end();i++){
		ans += min(p,C)*(i->first-d);
		d = i->first;
		p += i->second;
	}
	cout << ans << endl;
}