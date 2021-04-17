#include <bits/stdc++.h>
using namespace std;

void findFirstLargerFromLeft(vector<long long> a, set<long long> &sols){
	stack<long long> largest;
	for(int i = 0; i<a.size(); i++){
		while(!largest.empty() && a[i]>largest.top()) largest.pop();
		if(!largest.empty()) sols.insert(largest.top() - a[i]);
		largest.push(a[i]);
	}
}

int f() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	set<long long> sols;
	findFirstLargerFromLeft(a, sols);
	reverse(a.begin(), a.end());
	findFirstLargerFromLeft(a, sols);
	return sols.size();
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