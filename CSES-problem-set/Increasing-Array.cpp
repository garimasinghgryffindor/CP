#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n; i++) {
        int x;  cin>>x;
        vec[i] = x;
    }

    long long res = 0;
    for(int i = 1; i < n; i++) {
        if(vec[i] < vec[i-1]) {
            res += (long long)vec[i-1]-vec[i];
            vec[i] = vec[i-1];
        }
    }

    cout<<res<<endl;

    return 0;
}