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
#define left(x) 		   (x << 1)
#define right(x) 		   (x << 1) + 1
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z)    {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
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

const int maxn = 500007;
vector<int> G[maxn];
int tick ;
bool vis[maxn];
int lo[maxn];
int hi[maxn];
void dfs(int u , int par )
{
	vis[u] = true;
	lo[u] = ++tick;
	for(auto &v: G[u])
	{
		if(!vis[v] && v != par)
			dfs(v,u);
	}
	hi[u] = tick;
}

int tree[3][4*maxn],lazy[3][4*maxn];

void range_update(int type,int id , int left ,int right ,int lq , int rq, int val)
{
	if(lazy[type][id])
	{
		tree[type][id] = lazy[type][id];
		if(left != right)
		{
			lazy[type][2*id] = lazy[type][id];
			lazy[type][2*id+1] = lazy[type][id];
		}
		lazy[type][id] = 0;
	}
	if(left > rq || right < lq)
		return;

	if(left >= lq && right <= rq)
	{
		tree[type][id] = val;
		if(left != right)
		{
			lazy[type][2*id] = val;
			lazy[type][2*id+1] = val;
		}
		return ;
	}
	int mid = mid(left , right);
	range_update(type,2*id,left,mid,lq,rq,val);
	range_update(type,2*id+1,mid+1,right,lq,rq,val);
	tree[type][id] = max(tree[type][2*id],tree[type][2*id+1]);
}

int range_query(int type ,int id ,int left , int right , int lq ,int rq)
{
  if(lazy[type][id])
	{
		tree[type][id] = lazy[type][id];
		if(left != right)
		{
			lazy[type][2*id] = lazy[type][id];
			lazy[type][2*id+1] = lazy[type][id];
		}
		lazy[type][id] = 0;
	}
  	if(left > rq || right < lq)
	{
		return -9999999;  
	}
	if(left >= lq && right <= rq)
	{
		return tree[type][id];  
	}
	int mid = mid(left, right);
	return max(range_query(type,2*id,left,mid,lq,rq) , range_query(type,2*id+1,mid+1,right,lq,rq));
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n-1; i++)
	{
		int u , v;   
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,-1);

	int q;
	scanf("%d",&q);
	for(int i = 1; i <= q; i++)
	{
		int tp, ver; 
		scanf("%d%d",&tp,&ver);
		if(tp == 1)
		{
			//fill
			range_update(1,1,1,n,lo[ver],hi[ver],i);
		}
		else if(tp == 2)
		{
			//empty
			range_update(2,1,1,n,lo[ver],lo[ver],i);
		}
		else 
		{
			int time_filled = range_query(1,1,1,n,lo[ver],lo[ver]);
			int time_empty = range_query(2,1,1,n,lo[ver],hi[ver]);
			if(time_filled > time_empty)
			{
				printf("%d\n",1);  
			}
			else
			{
				printf("%d\n",0);  
			}
		}
	}
    return 0;
}

