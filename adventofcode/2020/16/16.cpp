#include <bits/stdc++.h>
using namespace std;

string join(vector<string> strings, string separator) {
    string joined = strings[0];
    for(int i = 1; i<strings.size(); i++) joined = joined+separator+strings[i];
    return joined;
}

vector<string> split(string value, string separator) {
    vector<string> result; int found; int i = 0;
    while((found = value.find(separator, i)) != string::npos) {
        result.push_back(value.substr(i,found-i));
        i = found+separator.size();
    }
    result.push_back(value.substr(i, value.size()-i));
    return result;
}

bool getLine(string &line) {
    getline(cin, line);
    return line != "";
}

pair<int, int> getRange(string range) {
    vector<string> nums = split(range, "-");
    return make_pair(stoi(nums[0]), stoi(nums[1]));
}

vector<int> getTicket(string line) {
    vector<int> ticket;
    vector<string> values = split(line, ",");
    for(int i = 0; i<values.size(); i++) ticket.push_back(stoi(values[i]));
    return ticket;
}

int main() {
    int sol1 = 0;
    vector<pair<pair<int, int>, pair<int, int> > > ranges;
    vector<string> ranges_names;
    vector<vector<int> > tickets;
    string line;
    while(getLine(line)) {
        vector<string> parts;
        parts = split(line, ":");
        ranges_names.push_back(parts[0]);
        parts = split(parts[1], " ");
        ranges.push_back(make_pair(getRange(parts[1]), getRange(parts[3])));
    }
    getLine(line);
    getLine(line);
    vector<int> your_ticket = getTicket(line);
    getLine(line);
    getLine(line);
    while(getLine(line)){
        vector<int> ticket = getTicket(line);
        bool all_ok = true;
        for(int i = 0; i<ticket.size(); i++) {
            bool found = false;
            for(int j = 0; j<ranges.size(); j++) {
                if ((ranges[j].first.first <= ticket[i] && ticket[i] <= ranges[j].first.second) || 
                (ranges[j].second.first <= ticket[i] && ticket[i] <= ranges[j].second.second)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                sol1 += ticket[i];
                all_ok = false;
            }
        }
        if (all_ok) tickets.push_back(ticket);
    }
    map<int, int> field_index_to_range_index, range_index_to_field_index;
    while (field_index_to_range_index.size() != ranges.size()) {
        for (int field = 0; field < ranges.size(); field++) {
            if (field_index_to_range_index.find(field) != field_index_to_range_index.end()) continue;
            int c = 0, selected_range;
            for (int range = 0; range < ranges.size(); range++) {
                if (range_index_to_field_index.find(range) != range_index_to_field_index.end()) continue;
                bool all_ok = true;
                for(int ticket = 0; ticket < tickets.size(); ticket++) {
                    if (!(ranges[range].first.first <= tickets[ticket][field] && tickets[ticket][field] <= ranges[range].first.second) and 
                    !(ranges[range].second.first <= tickets[ticket][field]  && tickets[ticket][field]  <= ranges[range].second.second)) {
                        all_ok = false;
                        break;
                    }
                }
                if (all_ok) {
                    selected_range = range;
                    c++;
                    if (c > 1) break;
                }
            }
            if(c == 1) {
                field_index_to_range_index[field] = selected_range;
                range_index_to_field_index[selected_range] = field;
                break;
            }
        }
    }
    long long sol2 = 1;
    for(int i = 0; i<ranges_names.size(); i++) {
        vector<string> name_words = split(ranges_names[i], " ");
        if (name_words[0] == "departure") {
            sol2 *= your_ticket[range_index_to_field_index[i]];
        }
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}
