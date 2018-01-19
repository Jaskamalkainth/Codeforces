#include <iostream>
using namespace std;

int main()
{
    long long int n,m, pow[30]; cin >> n >> m;
    
    pow[0] = 1;
    for(int i = 1; i <= 29; i++)
    {
      pow[i] = pow[i-1]*2;    
    }
    if(n > 30)
    {
      cout << m << "\n";    
    }
    else
    {
        cout << m%pow[n];
    }
    return 0;
}
