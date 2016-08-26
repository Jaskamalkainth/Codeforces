/*
 *    J1K7_7
 *
 *    You can use my contents on a Creative Commons - Attribution 4.0 International - CC BY 4.0 License.  XD 
 *    - JASKAMAL KAINTH
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
#include <cassert>
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
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w << " = " <<w <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))

const int mod=1e9+7;

template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T, typename S> T expo(T b, S e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T> T modinv(T a) { return expo(a, mod-2, mod); }

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);
/*
 *
 * Bridge tree.
 * using DSU ( union by rank and path compression )
 * mark all the bridges first then do DSU .
 */
const int maxn = 3e5+7;
int n; // number of nodes

vector<int> G[maxn];
int low[maxn], disc[maxn] , parent[maxn] , vis[maxn];
vector<pair<int,int> > bedge; // all bridge edges 
int timer;
vector<int> Btree[maxn]; 

/******** DSU part *********/
int rankN[maxn];
int parentN[maxn];
inline void make_set()
{
	for(int i = 0; i < n; i++)
		parentN[i] = rankN[i] = i;  
}
inline int find_set(int u)
{
	if(parentN[u] != u )
		parentN[u] = find_set(parentN[u]);
	return parentN[u];
}
inline void union_set(int u,int v)
{
	int pu = find_set(u);
	int pv = find_set(v);
	if(pu == pv)
		return ;
	if(rankN[pu] > rankN[pv])
	{
		parentN[pv] = pu;  
	}
	else
	{
		parentN[pu] = pv;
		if(rankN[pu] == rankN[pv])
			rankN[pv]++;
	}
}
/* */
/********* Bridge tree ********/
inline void clear()
{
	timer = 0;
	for(int i = 0; i < maxn; i++)
	{
		low[i] = disc[i] = vis[i] = 0;
		parent[i] = -1;
		G[i].clear();
	}
}
/* Mark all the bridges */
inline void mark_bridges(int u)
{
	vis[u] = 1;
	disc[u] = low[u] = timer++;
	for(int &v: G[u])
	{
		if(!vis[v])
		{
			parent[v] = u;
			mark_bridges(v);
			low[u] = min(low[u],low[v]);
			if(low[v] > disc[u])
			{
				// u-v is a bridge edge
				bedge.push_back(mp(u,v));
			}
			else
			{
				union_set(u,v);
			}
		}
		else if(parent[u] != v)
		{
			low[u] = min(low[u],disc[v]);
		}
	}
}
int num_br_edges;
inline void make_tree()
{
	mark_bridges(0); // mark all the bridges

	for(auto &i: bedge) // atmose n-1 bridge edges.
	{
		int pu = find_set(i.ff);
		int pv = find_set(i.ss);
		if(pu != pv)
		{
			num_br_edges++;
			Btree[pu].push_back(pv);
			Btree[pv].push_back(pu);
		}
	}
}
/**** Bridge tree Ends ****/


vector<pair<int,int> > edges;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int m; cin >> n >> m;
	edges.resize(m);
	make_set(); // initializing parent[] and rank[]
	clear();

	for(int i = 0; i < m; i++)
	{
		int u , v; cin >> u >> v;
		u--; v--;
		G[u].pb(v);
		G[v].pb(u);
		edges[i].ff = min(u,v);
		edges[i].ss = max(u,v);
	}
	
	sort(all(edges));

	// remove duplicate edges ( cant be a bridge edge ).
	for(int i = 0; i < m-1; i++)
	{
		if(edges[i].ff == edges[i+1].ff && edges[i].ss == edges[i+1].ss)
		{
			int pu = find_set(edges[i].ff);
			int pv = find_set(edges[i].ss);
			union_set(pu,pv);
		}
	}

	make_tree();

	if(num_br_edges == 0)
	{
		cout << "YES\n";
		return 0;
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(Btree[i].size() == 1)
			cnt++;

	if(cnt == 2)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";  
	}

    return 0;
}

