#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	cout << max(a[0]+a[1]+a[2], b[0]+b[1]+b[2]) - 3*'0' << endl;
	return 0;
}