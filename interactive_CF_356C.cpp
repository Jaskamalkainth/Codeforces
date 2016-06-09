/*
 *    J1K7_7
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <list>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef long double        ld;
typedef pair<int,int>      pii;
typedef pair<ll,ll>        pll;
typedef vector<int>        vi;
typedef vector<long long>  vll;
#define l(x) 		       (x << 1) + 1
#define r(x) 		       (x << 1) + 2
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))
#define snuke(c,itr)       for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

template<class T>
inline bool ispow2(T x){return (x!=0 && (x&(x-1))==0);} //0 or 1

template<class T> inline T powmod(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const int mod=1e9+7;

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);


const int maxN = 1e2+7;
int  pp[maxN+1];
vector <int> prime;
inline void pre_sieve()
{
    // there are 1007 primes < 8000 
    // there are 78499   primes < 1e6+7
    for(ll i = 2; i < maxN; i++ )
        if( pp[i] == 0 )
            for(ll j = i*i; j < maxN; j += i)
                pp[j] = 1;

    for(int i =2; i< maxN; i++)
        if(pp[i] == 0)
            prime.push_back(i);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	pre_sieve();
	vector<int> arr;
	for(auto x: prime)
		if(x < 51)
			arr.pb(x);

	vector<int> arr1 = {4,9,25,49};

	for(auto x: arr1)
	{
		cout << x << endl;
		string st;
		cin >> st;
		if(st[0] == 'y')
		{
			cout << "composite" << endl;
			return 0;
		}
	}
	int cnt = 0;
	for(auto p : arr)
	{
		cout << p << endl;
		string st;
		cin >> st;
		if(st[0] == 'y')
			cnt++;  
	}
	if(cnt >= 2)
		cout << "composite" << endl;
	else
		cout << "prime" << endl;
	return 0;
}

