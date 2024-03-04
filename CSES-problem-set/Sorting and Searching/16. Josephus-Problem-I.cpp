#include <iostream>
#include <list>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int n;  cin>>n;

    list<int> ls(n);
    iota(ls.begin(), ls.end(), 1);
    vector<int>res;

    auto it = ls.begin();
    it++;
    while(ls.size()) {
        if(ls.size() == 1) {
            res.push_back(*(ls.begin()));
            break;
        }
        while(it!=ls.end()) {
            res.push_back(*it);
            it = ls.erase(it);
            if(it == ls.end()) {
                if(ls.size() == 1) {
                    break;
                }
                it = ls.begin();
                it++;
                break;
            }
            it++;
            if(it == ls.end()) {
                it = ls.begin();
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }

    return 0;
}
