#include <iostream>
using namespace std;

int f() {
	int a, b, n;
	cin >> n >> a >> b;
	return (n%2)*a + n/2*min(2*a,b);
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
