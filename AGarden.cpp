#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 107;
    for(int i = 1; i <= n; i++)
        if(k%a[i] == 0)
            ans = min(ans,k/a[i]);
    cout << ans << "\n";
    return 0;
}
