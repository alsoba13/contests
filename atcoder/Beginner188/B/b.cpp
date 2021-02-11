#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
	cin >> n;
	int ans = 0;
	vector<int> a(n), b(n);
	for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++) cin>>b[i];
	for(int i = 0; i<n; i++) ans += a[i]*b[i];
	cout << (ans==0?"Yes":"No") << endl;
}