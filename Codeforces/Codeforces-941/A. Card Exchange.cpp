#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, x;
    cin>>t;
    bool flag;
    while(t--) {
        cin>>n>>k;  flag = false;
        map<int, int>a;
        for(int i = 0; i < n; i++) {
            cin>>x;
            a[x]++;
            if(a[x] >= k) flag = true;
        }
        if(flag) cout<<k-1<<"\n";
        else cout<<n<<"\n";
    } 

    return 0;
}
