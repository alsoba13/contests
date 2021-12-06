#include <bits/stdc++.h>
using namespace std;

bool checkField(string field, string value) {
    if (field == "byr") {
        return 1920 <= stoi(value) && stoi(value) <= 2002;
    }
    if (field == "iyr") {
        return 2010 <= stoi(value) && stoi(value) <= 2020;
    }
    if (field == "eyr") {
        return 2020 <= stoi(value) && stoi(value) <= 2030;
    }
    if (field == "hgt") {
        if (value.substr(value.size()-2) == "cm"){
            value = value.substr(0, value.size()-2);
            return 150 <= stoi(value) && stoi(value) <= 193;
        }
        if (value.substr(value.size()-2) == "in"){
            value = value.substr(0, value.size()-2);
            return 59 <= stoi(value) && stoi(value) <= 76;
        }
        return false;
    }
    if (field == "hcl") {
        return value[0] == '#';
    }
    if (field == "ecl") {
        return value == "amb" || value == "blu" || value == "brn" || value == "gry" ||value == "grn" || value == "hzl" || value == "oth";
    }
    if (field == "pid") {
        if (value.size() != 9) return false;
        for (int i = 0; i<9; i++) {
            if (value[i] < '0' || value[i] > '9') return false;
        }
        return true;
    }
    return true;
}

int main() {
    string line, passport = "";
    int sol1 = 0, sol2 = 0;
    while(getline(cin, line)){
        if (!line.empty()) {
            if (passport.empty()) passport = line;
            else passport += " " + line;
        } else {
            const char *str = passport.c_str();
            int valid1 = 0, valid2 = 0;
            do{
                const char *begin = str;
                while(*str != ' ' && *str) str++;
                string field = string(begin, str);
                string value = field.substr(field.find(':')+1);
                field = field.substr(0, field.find(':'));
                if (field == "cid") continue;
                valid1++;
                if (checkField(field, value)) valid2++;
            } while (0 != *str++);
            sol1 += (valid1 == 7);
            sol2 += (valid2 == 7);
            passport = "";
        }       
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}