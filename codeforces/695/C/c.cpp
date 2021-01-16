#include <bits/stdc++.h>
using namespace std;

long long readBag(int n, vector<int> &a) {
	long long sum = 0;
	for(int i = 0; i<n; i++){
		int a_;
		cin >> a_;
		sum+=a_;
		a.push_back(a_);
	}
	return sum;
}

long long f(vector<int> a[3], int end, long long sums[3]) {
	long long ans = sums[end];
	vector<int> bags;
	for(int i = 0; i<3; i++) if(i!=end) bags.push_back(i);
	ans = sums[end] + sums[bags[0]] + sums[bags[1]] - a[bags[0]][0]*2 - a[bags[1]][0]*2;
	ans = max(ans, sums[end] + sums[bags[0]] - sums[bags[1]]);
	ans = max(ans, sums[end] + sums[bags[1]] - sums[bags[0]]);
	return ans;
}

int main() {
	int n[3];
	vector<int> a[3];
	long long sums[3];
	for(int i = 0; i<3; i++) cin >> n[i];
	for(int i = 0; i<3; i++) sums[i] = readBag(n[i], a[i]);
	for(int i = 0; i<3; i++) sort(a[i].begin(), a[i].end());
	long long ans = 0;
	for(int i = 0; i<3; i++) ans = max(ans, f(a, i, sums));
	cout << ans << endl;
}
