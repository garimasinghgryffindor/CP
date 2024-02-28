#include <iostream>
#include <queue>
#include <list>
#include <set>
using namespace std;

int main()
{
    int len, n;   cin>>len>>n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    vector<int>res(n, 0);
    set<int>pos;

    pos.insert(0);
    pos.insert(len);
    for(int i = 0; i < n; i++) {
        pos.insert(vec[i]);
    }

    int maxDis = 0;
    int prev = 0;

    for(int x: pos) {
        //cout<<"x:  "<<x<<"  ";
        maxDis = max(maxDis, x-prev);
        prev = x;
    } 
    //cout<<endl<<endl;

    res[n-1] = maxDis;
    //res.back() = maxDis;

    for(int i = n-1; i > 0; i--) {
        pos.erase(vec[i]);
        auto ptr = pos.upper_bound(vec[i]);
        int h = *ptr;
        int l = *(--ptr);
        maxDis = max(maxDis, h-l);
        res[i-1] = maxDis;
    }

    for(int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
