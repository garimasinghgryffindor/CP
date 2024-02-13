// https://japlslounge.com/posts/cses/two_knights/1.htm
// USE THE ABOVE LINK TO UNDERSTAND
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin>>k;

    for(int i = 1; i <=k; i++) {
        if(i == 1) {
            cout<<0<<endl;  continue;
        }
        long long total_positions = (long long)i*i;
        long long total_pairs_pos = total_positions*(total_positions-1)/2;
        // attacking block of size (minimum) => 2x3 or 3x2
        // finding the total number of these blocks which could exist int the kxk board
        // just visualize it
        long long total_attacking_blocks = (i-1)*(i-2);
        long long total_attacking_positions = total_attacking_blocks*8/2; 
        // divide by 2 to remove duplicates
        long long ans = total_pairs_pos - total_attacking_positions;
        cout<<ans<<endl;
    }

    return 0;
}
