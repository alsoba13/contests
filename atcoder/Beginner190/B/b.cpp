#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s, d;
	cin >> n >> s >> d;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		if(x<s && y>d) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
