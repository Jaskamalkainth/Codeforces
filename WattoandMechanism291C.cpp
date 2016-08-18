#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>

set<pii > hashSet;

ll base[2],mod[2];

inline ll pwrmod(ll base , ll power ,ll mod)
{
	ll ans = 1ll;
	while(power)
	{
		if(power&1ll)
			ans = (ans*base)%mod;
		base = (base*base)%mod;
		power /= 2;
	}
	return ans%mod;
}
inline pii getHashValue(string s)
{
	int len = s.length();
	pii hash(0,0);
	for(int i = len-1; i >= 0; i--)
	{
		ll val = s[i];
		hash.ff = ((ll)hash.ff*base[0] + val + mod[0]) % mod[0];
		hash.ss = ((ll)hash.ss*base[1] + val + mod[1]) % mod[1];
	}
	return hash;
}

inline pii changeit(pii oldhash,int pos ,char newch, char oldch)
{
	pii newhash = oldhash;

	ll mul = pwrmod(base[0],pos,mod[0]);
	ll val1 = oldhash.ff - mul*oldch + mul*newch;
	val1 %= mod[0];
	if(val1 < 0 ) val1 += mod[0];
	newhash.ff = val1;

	mul = pwrmod(base[1],pos,mod[1]);
	ll val2 = oldhash.ss - mul*oldch + mul*newch;
	val2 %= mod[1];
	if(val2 < 0 ) val2 += mod[1];
	newhash.ss = val2;

	return newhash;
}
int main()
{
	base[0] = 31;
	base[1] = 37;
	mod[0] = 999999937;
	mod[1] = 999999929;

	int n , m; 
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		hashSet.insert(getHashValue(s));
	}
	bool found;
	while(m--)
	{
		string s; cin >> s;
		pii	oldhash = getHashValue(s);
		int len = s.length();
		found = false;
		for(int i = 0; i < len; i++)
		{
			for(char ch = 'a'; ch <= 'c'; ch++)
			{
				if(s[i] == ch) continue;
				pii newhash = changeit(oldhash,i,ch,s[i]);
				if(hashSet.find(newhash) != hashSet.end()) 	found = true;
			}
			if(found)
				break;
		}
		if(found)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
// my hands hurt writing all this from scratch! XD
// finally AC for this shit question. :/
