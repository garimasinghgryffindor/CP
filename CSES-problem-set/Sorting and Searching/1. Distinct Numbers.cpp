#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{    
    int n;  cin>>n;
    vector<int> vec(n);

    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());
    int res = 1;

    for(int i = 1; i < n; i++) {
        if(vec[i] != vec[i-1]) {
            res++;
        }
    }

    cout<<res<<endl;

    return 0;
}
