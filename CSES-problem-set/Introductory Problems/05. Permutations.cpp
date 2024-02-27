#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int>res;
    cin>>n;

    if(n == 1) {
        cout<<1<<endl;
    } else if(n == 2 || n == 3) {
        cout<<"NO SOLUTION"<<endl;
    } else if(n == 4) {
        cout<<"3 1 4 2"<<endl;
    } else {
        for(int i = 2; i <= n; i+=2) {
            res.push_back(i);
        }

        for(int i = 1; i <= n; i+=2) {
            res.push_back(i);
        }

        for(int i = 0; i < n-1; i++) {
            cout<<res[i]<<" ";
        }
        cout<<res[n-1];
    }

    return 0;
}
