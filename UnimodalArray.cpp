#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ok = false;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            //[1..i..j..n]    
            int fm = 1;
            for(int k = i; k+1 <= j; k++)
                if(a[k] != a[k+1])
                    fm = 0;
            int fl = 1;
            for(int k = 1; k+1 <= i; k++)
                if(a[k+1] <= a[k])
                    fl = 0;
            int fr = 1;
            for(int k = j; k+1 <= n; k++)
                if(a[k+1] >= a[k])
                    fr = 0;
            if(fm && fl && fr)
            {
                ok = true;
                break;
            }
            if(ok)
                break;
        }
        if(ok)
            break;
    }

    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
