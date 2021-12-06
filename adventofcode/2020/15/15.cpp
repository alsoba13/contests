#include <bits/stdc++.h>
using namespace std;

vector<string> split(string value, string separator) {
    vector<string> result; int found; int i = 0;
    while((found = value.find(separator, i)) != string::npos) {
        result.push_back(value.substr(i,found-i));
        i = found+separator.size();
    }
    result.push_back(value.substr(i, value.size()-i));
    return result;
}

int main() {
    int sol1 = 0, last_spoken;
    long long c = 1;
    string line;
    getline(cin, line);
    vector<string> numbers = split(line, ",");
    map<int, int> m;
    for (int i = 0; i<numbers.size()-1; i++){
        m[stoi(numbers[i])] = c++;}
    last_spoken = stoi(numbers[numbers.size()-1]);
    while (c < 30000000) {
        if (m.find(last_spoken) == m.end()) {
            m[last_spoken] = c;
            last_spoken = 0;
        } else { 
            int tmp = m[last_spoken];
            m[last_spoken] = c;
            last_spoken = c - tmp;
        }
        c++;
        if (c == 2020) sol1 = last_spoken;
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << last_spoken << endl;
}
