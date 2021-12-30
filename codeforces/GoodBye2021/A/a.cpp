#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	set<int> numbers;
	for(int i = 0; i<n; i++) {
		int a;
		cin >> a;
		if(numbers.find(a) == numbers.end())
			numbers.insert(a);
		else
			numbers.insert(-a);
	}
	return numbers.size();
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
		//cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
