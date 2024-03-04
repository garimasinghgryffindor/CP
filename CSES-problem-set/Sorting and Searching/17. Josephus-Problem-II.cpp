#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int main()
{
    int n;  cin>>n;
    int k;  cin>>k;
    vector<int>res;

    ordered_set<int> st;
    for(int i = 1; i <= n; i++) {
        st.insert(i);
    }

    int pos = k%n;
    while(!st.empty()) {
        //auto it = st.begin();
        //advance(it, pos);
        int x = *(st.find_by_order(pos));

        res.push_back(x);
        st.erase(x);

        if(!st.empty()) {
            pos = (pos+k)%st.size();
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }

    return 0;
}
