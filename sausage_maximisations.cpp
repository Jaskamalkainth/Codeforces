#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long

const int maxN = 60*1e5;
const int maxBITS = 59;

ll trie[maxN][2];
int sz = 1;

inline void insert(ll N)
{
	int node = 0;
	for(int i = maxBITS; i >= 0; i--)
	{
		int b = (N & (1ll << i)) != 0;  
		if(trie[node][b] == -1)
			trie[node][b] = sz++;  
		node = trie[node][b];
	}
}


inline ll query(ll X)
{
	int node = 0;
	ll ans = 0;
	for(int i = maxBITS; i >= 0; i--)
	{
		int b = (X & (1ll << i)) != 0;  
		int ok = 1;
		if(trie[node][b^1] == -1)
		{
			ok = 0;
			node = trie[node][b];
		}
		else
		{
			node = trie[node][b^1];  
		}
		if(ok)
			ans += ( 1ll << i);
	}
	return ans;
}

int main()
{
	memset(trie,-1,sizeof(trie));
	ll n; 
	scanf("%lld",&n);

	ll inp[n+2] , preXOR[n+2],suffXOR[n+2];
	preXOR[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&inp[i]);
		preXOR[i] = preXOR[i-1]^inp[i];
	}
	suffXOR[n+1] = 0;
	for(int i = n; i >= 1; i--)
		suffXOR[i] = suffXOR[i+1]^inp[i];

	ll ans = -1;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans , preXOR[i]);
		ans = max(ans , suffXOR[i]);
	}
	for(int i = 2; i <= n; i++)
	{
		insert(preXOR[i-1]);
		ans = max ( ans , query(suffXOR[i]));
	}
	printf("%lld\n",ans);
	return 0;
}
