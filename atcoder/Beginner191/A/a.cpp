#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int v, t, s, d;
	cin >> v >> t >> s >> d;
	if (d<t*v || d>s*v) cout << "Yes";
	else cout << "No";
	return 0;
}
