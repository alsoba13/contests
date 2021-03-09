#include <bits/stdc++.h>
using namespace std;

bool ok (string time, int H, int M){
	string reversed=time;
	reverse(reversed.begin(), reversed.end());
	for(int i=0; i<time.size(); i++){
		if(reversed[i]==':') continue;
		if(reversed[i]=='3') return false;
		if(reversed[i]=='4') return false;
		if(reversed[i]=='6') return false;
		if(reversed[i]=='7') return false;
		if(reversed[i]=='9') return false;
		if(reversed[i]=='2') reversed[i]='5';
		else if(reversed[i]=='5') reversed[i]='2';
	}
	if((reversed[0]-'0')*10+(reversed[1]-'0')>=H) return false;
	if((reversed[3]-'0')*10+(reversed[4]-'0')>=M) return false;
	return true;
}

string f() {
	int H, M;
	cin >> H >> M;
	string time;
	cin >> time;
	while(!ok(time, H, M)){
		int h = (time[0]-'0')*10+(time[1]-'0');
		int m = (time[3]-'0')*10+(time[4]-'0');
		m++;
		if(m==M){
			m = 0;
			h++;
			if(h==H){
				h=0;
			}
		}
		string hh, mm;
		if(h == 0) hh = "00";
		else if(h<10) hh = "0"+to_string(h);
		else hh = to_string(h);
		if(m == 0) mm = "00";
		else if(m<10) mm = "0"+to_string(m);
		else mm = to_string(m);
		time = hh + ":" + mm;
	}
	return time;
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
