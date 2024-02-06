#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int res = 0;

    //int temp = 10;
    //while(temp <= n) {
    //    res += n/temp;
    //    temp*=10;
    //}

    int temp = 5;
    while(temp <= n) {
        res += n/temp;
        temp*=5;
    }

    cout<<res;

    return 0;
}