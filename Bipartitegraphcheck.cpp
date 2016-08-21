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


const int maxN = 1e5+7;
vector<int> G[maxN];
int num_vertices;
int vis[maxN];
int color[maxN];
vi red,blue;
#define RED 1
#define BLUE 2
bool check_Bipartite_flag = true;

inline void dfs(int u, int c)
{
	color[u] = c;
	vis[u] = 1;
	if(c == RED)
		red.push_back(u);
	else
		blue.push_back(u);
	for(auto &v: G[u])
	{
		if(!vis[v])
			dfs(v,(c==RED)?BLUE:RED);
		if(c == color[v])
			check_Bipartite_flag = false;
	}
}
inline bool isBipartite()
{
	for(int i = 1; i <= num_vertices; i++)
		if(!vis[i])
			dfs(i,RED);
	if(check_Bipartite_flag)
		return 1;
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int  m; cin  >> num_vertices >> m;
	while(m--)
	{
		int u , v; cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	if(isBipartite())
	{
		cout << red.size() << "\n";
		for(auto u: red)
			cout << u << " ";
		cout << "\n";

		cout << blue.size() << "\n";
		for(auto u: blue)
			cout << u << " ";
		cout << "\n";
	}
	else
	{
		cout << "-1\n";  
	}
	return 0;
}

