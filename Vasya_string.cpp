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



const int maxN = 2e5+7;
char s[maxN+1];
int n , k; 
bool solve(int len)
{
	int cnt_a = 0;
	int cnt_b = 0;
	for(int i = 1; i <= len; i++)
		if(s[i]=='a') cnt_a++;
		else cnt_b++;
		
	if(min(cnt_a,cnt_b) <= k)
			return true;
	for(int i = 2; i <= n - len + 1; i++)
	{
		if(s[i-1] == 'a')
			cnt_a--;
		else
			cnt_b--;
		if(s[i-1+len] == 'a')
			cnt_a++;
		else
			cnt_b++;
		if(min(cnt_a,cnt_b) <= k)
			return true;

	}
		return false;

}

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);

	int l = 1, r = n+1;
	int ans = 1 ;
	while(l+1 != r)
	{
		int m = (l+r)/2;
		if( solve(m) )
		{
			ans = m;
			l = m ;
		}
		else
			r = m;  
	}
	cout << ans ;
    return 0;
}

