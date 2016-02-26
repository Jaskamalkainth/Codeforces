/*
 *
 *    J1K7_7
 * 
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

const int maxn = 501;
vector<int> cnt(maxn);
bool edge[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n , m ;
	memset(edge,false,sizeof(edge));
	n = nextint(); m = nextint();
	for(int i = 0; i < m; i++)
	{
		int  u , v ;  u = nextint();  v = nextint();
		u--; v--;
		cnt[u]++;
		cnt[v]++;
		edge[u][v] = true;
		edge[v][u] = true;
	}
	char ans[maxn];
	memset(ans,'0',sizeof(ans));
	for(int i = 0; i < n; i++)
		if(cnt[i] == n-1 )
			ans[i] = 'b';
	for(int i = 0; i < n; i++)
	{
		if( ans[i] == '0' )
		{
			ans[i] = 'a';
			for( int j = 0; j < n; j++)
			{
				if( ans[j]  == '0' )
				{
					if( edge[i][j] )
						ans[j] = 'a';
					else
						ans[j] = 'c';
				}
			}
		}
	}
	// check if valid answer
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j != i && j < n; j++)
		{
			if( abs(ans[i] - ans[j]) == 2 && edge[i][j] )
			{
				cout << "No" ; return 0;  
			}
			if( abs(ans[i] - ans[j]) < 2 && !edge[i][j] )
			{
				cout << "No" ; return 0;  
			}
		}
	}
	ans[n] = '\0';
	cout << "Yes\n" <<  ans ;
    return 0;
}

