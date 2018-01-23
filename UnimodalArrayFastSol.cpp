#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    int l = 1;
    int r = n;
    while((l+1) <= n && a[l+1] > a[l])
        l++;
    while((r-1) >= 1 && a[r-1] > a[r])
        r--;
    int ok = 1;
    for(int k = l; k+1 <= r; k++)
        if(a[k] != a[k+1])
        {
            ok = 0;
            break;
        }
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";    
    return 0;
}
