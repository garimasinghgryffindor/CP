#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int n = s.length();
    vector<int> ch(26,0);

    for(auto x: s) {
        ch[x-'A']++;
    }

    string res = s;
    int l = 0, r = n-1;
    bool odd = false;
    bool ans = true;

    for(int i = 0; i < 26; i++) {
        if(ch[i]%2 == 1) {
            if(odd) {
                cout<<"NO SOLUTION\n";
                ans = false;
                break;
            } else {
                //cout<<"here   "<<char(i+'A')<<endl;
                res[n/2] = i+'A';
                odd = true;
                int x = (ch[i]-1)/2;
                while(x) {
                    res[l++] = i+'A';
                    res[r--] = i+'A';
                    x--;
                }
            }
        } else {
            int x = (ch[i])/2;
            while(x) {
                res[l] = i+'A';
                res[r] = i+'A';
                l++;    r--;
                x--;
            }
        }
    }

    if(ans) {
        cout<<res<<endl;
    }

    return 0;
}
