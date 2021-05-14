#include <bits/stdc++.h>
using namespace std;

int ask(int t, int i, int j, int x){
	cout << "? " << t << " " << i+1 << " " << j+1 << " " << x << "\n";
	cout.flush();
	int res;
	cin >> res;
	return res;
}

pair<int, int> ask_pair(int f, int s, int n){
	pair<int, int> candidates;
	candidates.first = ask(1, f, s, n-1);
	if (candidates.first == n-1){
		candidates.first = ask(1, s, f, n-1);
	}
	candidates.second = ask(2, f, s, 1);
	if (candidates.second == 2){
		candidates.second = ask(2, s, f, 1);
	}
	return candidates;
}

void slv() {
	int n;
	cin >> n;
	vector<int> a(n);
	pair<int, int> candidates01, candidates12;
	candidates01 = ask_pair(0,1,n);
	candidates12 = ask_pair(1,2,n);
	if(candidates01.first == candidates12.first || candidates01.first == candidates12.second){
		a[1] = candidates01.first;
		a[0] = candidates01.second;
	}else{
		a[0] = candidates01.first;
		a[1] = candidates01.second;
	}
	if(candidates12.first != a[0] && candidates12.first != a[1]){
		a[2] = candidates12.first;
	}else{
		a[2] = candidates12.second;
	}
	int mi=0, Mi=0;
	for(int i = 1; i<3; i++){
		if(a[i]<a[mi]) mi = i;
		if(a[i]>a[Mi]) Mi = i;
	}
	for(int i = 3; i<n; i++){
		int res;
		if(a[mi]<n+1-a[Mi]){
			res = ask(1, mi, i, n-1);
			if(res == a[mi]){
				res = ask(2, i, mi, 1);
			}
		}else{
			res = ask(2, i, Mi, 1);
			if(res == a[Mi]){
				res = ask(1, Mi, i, n-1);
			}
		}
		a[i] = res;
		if(a[i]<a[mi]) mi = i;
		if(a[i]>a[Mi]) Mi = i;
	}
	cout << "! ";
	for(int i = 0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout.flush();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
