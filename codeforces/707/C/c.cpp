#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i+1;
	}
	map<int, pair<int, int> > s;
	for(int i = 0; i<min(4000, n); i++){
		for(int j = i+1; j<min(4000, n); j++){
			if(s.find(a[i].first+a[j].first)==s.end()){
				s[a[i].first+a[j].first] = make_pair(i, j);
			}else{
				pair<int, int> xy = s[a[i].first+a[j].first];
				int x = xy.first;
				int y = xy.second;
				if(x != i && x != j && y != i && y != j){
					cout << "YES\n" << a[x].second << " " << a[y].second << " " << a[i].second << " " << a[j].second << "\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}
