#include <bits/stdc++.h>
using namespace std;

set<string> s;
map<string, vector<string> > b;
map<string, vector<pair<string, int> > >b2;

int dfs(string which) {
    for (int i = 0; i<b[which].size(); i++) {
        s.insert(b[which][i]);
        dfs(b[which][i]);
    }
    return s.size();
}

int dfs2(string which) {
    int m = 0;
    for (int i = 0; i<b2[which].size(); i++) {
        m += b2[which][i].second*(dfs2(b2[which][i].first)+1);
    }
    return m;
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i<n; i++) {
        string aux, bag1, bag2;
        cin >> bag1 >> aux;
        bag1 += " " + aux;
        cin >> aux >> aux >> aux;
        if (aux == "no") {
            cin >> aux >> aux;
            continue;
        }
        m = stoi(aux);
        do{
            cin >> bag2 >> aux;
            bag2 += " " + aux;
            b[bag2].push_back(bag1);
            b2[bag1].push_back(make_pair(bag2, m));
            cin >> aux;
            if (aux.back() != '.') {
                cin >> aux;
                m = stoi(aux);
            }
        } while (aux.back() != '.');
    }
    cout << "Problem1: " << dfs("shiny gold") << endl << "Problem2: " << dfs2("shiny gold") << endl;
}