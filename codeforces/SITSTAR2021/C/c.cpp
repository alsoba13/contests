#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t0, t1, t2;
	cin >> t0 >> t1 >> t2;
	cout << min(abs(t0-t1)+abs(t1-t2), abs(t0-t2)+abs(t1-t2)) << '\n';
	return 0;
}
