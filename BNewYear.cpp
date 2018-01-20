#include <iostream>
using namespace std;
int main()
{
  
    long long int n, k; cin >> n >> k;
    if(k == 1)
    {
        cout << n << "\n";    
    }
    else
    {
        int mark = 0;
        for(int i = 63; i >= 0; i--)
        {
            if(n&(1ll<<i))
            {
                mark = i;
                break;
            }
        }
        mark++;
        long long ans = 1ll;
        while(mark--)
            ans *= 2ll;
        ans--;
        cout << ans << "\n";
    }

    return 0;
}
