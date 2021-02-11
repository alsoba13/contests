#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, N; 
	cin >> n;
	N = 1<<n;
	vector<int> a(N);
	for(int i = 0; i<N; i++){
		cin >> a[i];
	}
	int i_first=0, i_second=N/2;
	for(int i = 0; i<N/2; i++){
		if(a[i]>a[i_first]) i_first = i;
	}
	for(int i = N/2; i<N; i++){
		if(a[i]>a[i_second]) i_second = i;
	}
	if(a[i_first]<a[i_second]) cout << i_first+1 << endl;
	else cout << i_second+1 << endl;
}