#include <bits/stdc++.h>
using namespace std;

long long f(long long a, long long b, long long c) {
	switch (c%6)
	{
		case 0: return a;
		case 1: return b;
		case 2: return b-a;
		case 3: return -a;
		case 4: return -b;
		case 5: return -b+a;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		long long a, b, c;
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		cout << f(a, b, c) << '\n';
	}
	return 0;
}