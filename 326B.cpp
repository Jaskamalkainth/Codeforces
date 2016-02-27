#include<iostream>
#include<set>
using namespace std;

// fuck sleep
int main()
{
	long long n ; cin >> n;
	set<long long> div;
	long long temp = n;
	for( long long i = 2ll; i * i <= n; i++)
	{
		if(temp % i == 0)
		{
			div.insert(i);
			while(temp % i == 0 ) 
				temp /= i;
		}
	}
	if( temp > 1)  div.insert(temp);
	long long ans = 1ll;
	for(auto x: div)
	{
		ans *= x;
	}

	cout << ans << "\n";
}
