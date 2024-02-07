#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<string>result;

long long toh(int N, int from, int to, int aux) {
    // Your code here
    if(N <= 0) return 0;
    long long res = 1;
    res += toh(N-1, from, aux, to);
    //cout<<from<<" "<<to<<endl;
    string temp = to_string(from) + " " + to_string(to);
    result.push_back(temp);
    res += toh(N-1,aux,to,from);
    return res;
}

int main()
{
    int disks;
    cin>>disks;

    int ans = toh(disks, 1, 3, 2);

    cout<<ans<<endl;
    for(auto x: result) {
        cout<<x<<endl;
    }

    return 0;
}