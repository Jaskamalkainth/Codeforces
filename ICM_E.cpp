#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll phi(ll n)
{
	ll res = n;
	for(ll i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
			res -= res/i;
		while(n%i == 0) n /= i;
	}
	if(n > 1)
		res -= res/n;
	return res;
}
int main()
{
	ll n , k; cin >> n >> k;

	ll  t = (k+1)/2;
	while(1)
	{
		n = phi(n);
		t--;
		if(t == 0 || n == 1)
			break;
	}
	cout << n % mod<< "\n";
	return 0;
}
