#include <map>
#include <iostream>
using namespace std;

int f() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	map<int, int> mm;
	for(int i = 0; i<n; i++) {
		mm[s[i]-'A']++;
	}
	int sol = 0;
	for(int i = 'A'; i<='G'; i++) if(mm[i-'A'] < m) sol += m-mm[i-'A'];
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
