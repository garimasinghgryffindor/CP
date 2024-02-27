#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second) return true;
    if (a.second == b.second) {
        return a.first >= b.first;
    }
    return false;
}

int32_t main() {
    int n;
    cin >> n;
    set<pair<int, int> > st;
    vector<pair<int, int> > movies;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        st.insert(make_pair(a, b));
    }

    for (auto x : st) {
        movies.push_back(make_pair(x.first, x.second));
    }

    sort(movies.begin(), movies.end(), compare);

    int currentEnd = -1, res = 0;

    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].first >= currentEnd) {
            res++;
            currentEnd = movies[i].second;
        }
    }

    cout << res << endl;

    return 0;
}
