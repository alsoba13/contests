#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	map<int, int> b;
	for(int i = 0; i<n; i++) {
		int a; cin >> a;
		b[a]++;
	}
	int q2=0, q4=0;
	for(map<int, int>::iterator i = b.begin(); i!=b.end(); i++) {
		q4 += i->second / 4;
		q2 += (i->second % 4)/2;
	}
	int ans = min(q4, q2);
	q4 -= ans;
	return ans + 4*q4/6;
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