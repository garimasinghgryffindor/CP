#include <iostream>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int res = 1;
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            count++;
            res = max(res, count);
        } else {
            count = 1;
        }
    }

    cout<<res<<endl;

    return 0;
}