#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

string getBinary(int n, int len) {
    string res = "";
    while(n) {
        if(n%2 == 0) {
            res = "0" + res;
        } else {
            res = "1" + res;
        }
        n/=2;
    }

    while(res.length() < len) {
        res = "0" + res;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;

    int largest = pow(2, n);

    for(int i = 0; i < largest; i++) {
        string bin = getBinary(i, n);
        string res = "";
        res.push_back(bin[0]);
        for(int j = 1; j < n; j++) {
            int x = (bin[j-1]-'0') ^ (bin[j]-'0');
            res.push_back((x+'0'));
        }
        cout<<res<<endl;
    }

    return 0;
}
