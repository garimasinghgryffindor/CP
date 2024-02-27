#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;   cin>>n>>x;
    vector<int> weight(n);

    for(int i = 0; i < n; i++) {
        cin>>weight[i];
    }

    sort(weight.begin(), weight.end());
    int res = 0, l = 0, r = n-1;

    while(l < r) {
        if(weight[l] + weight[r] <= x) {
            res++;  l++;    r--;
        } else {
            res++;  r--;
        }
    }

    if(l == r) res++;

    cout<<res<<endl;

    return 0;
}
