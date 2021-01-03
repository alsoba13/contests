#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int sol1 = 0, sol2 = 0, c = 0;
    map<char, int> y;
    while(getline(cin, line)){
        if (!line.empty()) {
            c++;
            for (int i = 0; i < line.size(); i++) y[line[i]]++;
        } else {
            sol1 += y.size();
            for (map<char, int>::iterator i = y.begin(); i != y.end(); i++) if (i->second == c) sol2++;
            c = 0;
            y = map<char, int>();
        }       
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}