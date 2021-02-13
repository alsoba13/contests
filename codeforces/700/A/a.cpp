#include <bits/stdc++.h>
using namespace std;

string f(){
	string a; 
	cin >> a;
	for(int i = 0; i<a.size(); i++){
		if(i%2==0){
			a[i] = (a[i]=='a'?'b':'a');
		}else{
			a[i] = (a[i]=='z'?'y':'z');
		}
	}
	return a;
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
