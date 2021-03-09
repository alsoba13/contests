#include <bits/stdc++.h>
using namespace std;

bool is_ok(vector<int> &c, int k, int sobran){
	for(int i = 0; i<26; i++){
		if(c[i]%k!=0){
			if(sobran>=k-c[i]%k){
				sobran -= k-c[i]%k;
			}else return false;
		}
	}
	return true;
}

string f() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(n%k!=0) return "-1";
	vector<int> c(26);
	for(int i = 0; i<n; i++){
		c[s[i]-'a']++;
	}
	if(is_ok(c, k, 0)) return s;
	for(int i = n-1; i>=0; i--){
		c[s[i]-'a']--;
		for(int cc = s[i]+1; cc <= 'z'; cc++){
			c[cc-'a']++;
			if(is_ok(c, k, n-(i+1))){
				string t;
				for(int j = 0; j<i; j++)
					t+=s[j];
				t+=cc;
				string t2;
				for(int j = 0; j<26; j++)
					for(int jj = c[j]%k; jj<k && jj>0; jj++)
						t2 += (j+'a');
				for(int j = t2.size(); j<n-i-1; j++)
					t2 += 'a';
				sort(t2.begin(), t2.end());
				t+=t2;
				return t;
			}
			c[cc-'a']--;
		}
		
	}
	assert(false);
	return "-1";
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
