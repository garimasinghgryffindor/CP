#include<bits/stdc++.h>
using namespace std;
#define int long long int

int recur(int idx, int sum, int tot, vector<int>&vec) {
    if(idx == 0) { return abs((tot-sum)-sum); }

    return min(recur(idx-1, sum, tot, vec), recur(idx-1, sum+vec[idx], tot, vec));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  cin>>n;
    int tot = 0;

    vector<int>vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    for(int x: vec) {
        tot += x;
    }

    //int idx = n-1;
    //int sum = 0;
    int res = recur(n-1, 0, tot, vec);
    cout<<res<<endl;

    return 0;
}