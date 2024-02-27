#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  cin>>n;

    vector<int> arrival(n), leaving(n);

    for(int i = 0; i < n; i++) {
        cin>>arrival[i]>>leaving[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());
    int res = 1, curr = 1;
    int i = 1, j = 0;

    while(i < n && j < n) {
        if(arrival[i] <= leaving[j]) {
            curr++;
            i++;
        } else {
            j++;
            curr--;
        }
        res = max(res, curr);
    }

    cout<<res<<endl;

    return 0;
}
