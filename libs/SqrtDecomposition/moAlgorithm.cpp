#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
const int seed = 1;

int bruteforce(int a[], int l, int r) {
    int sum = 0;
    for(int i = l; i<=r; i++) {
        sum += a[i];
    }
    return sum;
}

const int block_size = (int)sqrt(N)+1;
int sum = 0;
int a[N];
void remove(int idx) {
    sum -= a[idx];
}
void add(int idx) {
    sum += a[idx];
}
int get_answer() {
    return sum;
}
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    for(int i = 0; i<100; i++){
        printf("%d, %d\n", queries[i].l, queries[i].r);
    }
    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (int i = 0; i<queries.size(); i++) {
        Query q = queries[i];
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main() {
    srand(seed);
    for(int i = 0; i<N; i++) a[i] = (rand()%1000);
    // preprocessing
    const int len = (int)sqrt(N)+1;
    int b[len];
    for(int i = 0; i<len; i++) b[i] = 0;
    for(int i = 0; i<N; i++) b[i/len] += a[i];

    vector<Query> queries;
    int idx = 0;
    for(int l = 0; l<N; l++){
        for(int r = l; r<N; r++){
            Query q;
            q.idx = idx++;
            q.l = l;
            q.r = r;
            queries.push_back(q);
        }
    }
    vector<int> answers = mo_s_algorithm(queries);

    for(int i = 0; i<queries.size(); i++) {
        int sum = answers[i];
        int sum2 = bruteforce(a, queries[i].l, queries[i].r);
        assert(sum == sum2);
    }

}
