#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  cin>>n;
    vector<int>playlist(n);
    for(int i = 0; i < n; i++) {
        cin>>playlist[i];
    }

    map<int, int> occurence;
    occurence[playlist[0]] = 0;
    int res = 1;
    int curr = 1;
    int l = 0;
    for(int i = 1; i < n; i++) {
        if(occurence.find(playlist[i]) == occurence.end() || occurence[playlist[i]] < l) {
            // A ok
            curr++;
            res = max(res, curr);
            occurence[playlist[i]] = i;
        } else {
            l = occurence[playlist[i]]+1;
            curr = i-l+1;
            occurence[playlist[i]] = i;
        }
    }

    cout<<res<<endl;

    return 0;
}
