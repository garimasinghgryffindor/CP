//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int mod = 1e9+7;

int fn(int n) {
    int res = 1;
    int x = 2;

    while(n) {
        if(n%2 == 0) {
            x = ((long long)x*x)%mod;
            n/=2;
        } else {
            res = ((long long)res*x)%mod;
            n--;
        }
    }

    return res;
}

int main()
{
    int n;
    cin>>n;

    int ans = fn(n);

    cout<<ans;

    return 0;
}
