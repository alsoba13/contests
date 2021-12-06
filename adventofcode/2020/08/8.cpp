#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> l(n);
    vector<int> l2(n);
    for (int i = 0; i<n; i++) {
        string v_;
        cin >> l[i] >> v_;
        l2[i] = stoi(v_.substr(1)) * (v_[0] == '+' ? 1 : -1);
    }
    int sol1 = -1, sol2;
    for (int i = 0; i < n; i++){
        if (sol1 != -1 && l[i] == "acc") continue;
        set<int> s;
        int line = 0, acc = 0;
        while(s.find(line) == s.end() && line < n) {
            s.insert(line);
            switch (l[line][0]) {
                case 'a': acc += l2[line]; line++; break;
                case 'j': if (line == i) line++; else line += l2[line]; break;
                case 'n': if (line == i) line += l2[line]; else line++; break;
            }
        }
        if (l[i] == "acc") sol1 = acc;
        if (line >= n) {
            sol2 = acc;
            break;
        }
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}