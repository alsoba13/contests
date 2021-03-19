#include <bits/stdc++.h>
using namespace std;

long long f() {
	long long n, k;
	cin >> n >> k;
	vector<int> a(n);
	set<int> as;
	for(int i = 0; i<n; i++) {
		cin>>a[i];
		as.insert(a[i]);
	}
	sort(a.begin(), a.end());
	long long mex = 0;
	if(a[0]==0){
		mex = 1;
		for(int i = 1; i<n; i++){
			if(a[i]==a[i-1]+1) mex = a[i]+1;
			else break;
		}
	}
	if(mex==1+a[n-1]){
		return n+k;
	}else{
		if(k>0) as.insert((a[n-1]+mex)/2+(a[n-1]+mex)%2);
		return as.size();
	}
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
