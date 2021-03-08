#include <bits/stdc++.h>
using namespace std;

bool f() {
	int N; int a[4];
	cin >> N >> a[0] >> a[1] >> a[2] >> a[3];
	for(int i = 0; i<16; i++){
		vector<bool> corners(4, false);
		for(int j = 0; j<4; j++) if(i&(1<<j)) corners[j] = true;
		bool ok = true;
		for(int j = 0; j<4; j++){
			if(corners[j]+corners[(j-1)>=0?j-1:3]>a[j]) ok = false;
			if(a[j]==N && corners[j]+corners[(j-1)>=0?j-1:3]!=2) ok = false;
			if(N-2+corners[j]+corners[(j-1)>=0?j-1:3]<a[j]) ok = false;
		}
		if(ok){
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
