#include <bits/stdc++.h>
using namespace std;

/* worse solution
int f () {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int x;
	cin >> x;
	vector<pair<int,int> > ranges;
	for(int i = 0; i<n-1; i++)
		if(a[i]+a[i+1]<x*2) ranges.push_back(make_pair(i, i+1));
	for(int i = 0; i<n-2; i++)
		if(a[i]+a[i+1]+a[i+2]<x*3) ranges.push_back(make_pair(i, i+2));	
	sort(ranges.begin(), ranges.end());
	int to_delete = 0;
	if (ranges.size() == 0) return n;
	pair<int, int> intersection = ranges[0];
	for(int i = 1; i<ranges.size(); i++) {
		intersection.first = max(intersection.first, ranges[i].first);
		intersection.second = min(intersection.second, ranges[i].second);
		if(intersection.first>intersection.second) {
			to_delete++;
			intersection = ranges[i];
		}
	}
	return n-to_delete-1;
}
*/

int f () {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int x;
	cin >> x;
	vector<bool> sol(n, true);
	for(int i = 0; i<n-1; i++){
		if (sol[i] && sol[i+1] && a[i]+a[i+1]<2*x)
			sol[i+1] = false;
		if (i<n-2 && sol[i] && sol[i+1] && sol[i+2] && a[i]+a[i+1]+a[i+2]<3*x)
			sol[i+2] = false;
	}
	return count(sol.begin(), sol.end(), true);
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
