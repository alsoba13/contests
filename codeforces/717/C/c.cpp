#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i<n; i++) cin >> a[i];
	set<int> sums;
	for(int i = 0; i<n; i++) {
		sum += a[i];
		set<int> sums2 = set<int>(sums);
		sums2.insert(a[i]);
		for(set<int>::iterator j = sums.begin(); j != sums.end(); j++) {
			sums2.insert(a[i]+*j);
		}
		sums = sums2;
	}
	if(sum%2 == 1 || sums.find(sum/2)==sums.end()) {
		cout << "0\n"; 
		return 0;
	}
	cout << "1\n";
	for(int i = 0; i<n; i++){
		if((sum-a[i])%2 == 1 || sums.find((sum-a[i])/2)==sums.end()){
			cout << i+1 << endl;
			return 0;
		}
	}
	assert(false);
}
