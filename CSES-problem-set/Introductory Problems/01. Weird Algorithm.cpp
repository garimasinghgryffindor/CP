#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;

    vector<ll>res;
    
    while(n != 1) {
        res.push_back(n);
        if(n%2 == 0) {
            n /= 2;
        } else {
            n = n*3 + 1;
        }
    }

    res.push_back(1);

    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
