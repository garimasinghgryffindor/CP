#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        if((a+b)%3 != 0) {
            cout<<"NO\n";
        } else {
            if(b == a) {
                if(b%3 != 0) {
                    cout<<"NO\n";
                } else {
                    cout<<"YES\n";
                }
            } else if(b > a) {
                if(b-a > a) {
                    cout<<"NO\n";
                } else {
                    cout<<"YES\n";
                }
            } else {
                if(a-b > b) {
                    cout<<"NO\n";
                } else {
                    cout<<"YES\n";
                }
            }
        }
    }

    return 0;
}