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


const int maxn = 1e3;
int vis[maxn][maxn];
int counter, k , n , m , free_spot;

inline int valid(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}
inline void dfs(int x, int y)
{
	if(counter == free_spot-k)
		return ;
	if(vis[x][y] == 1)
		return ;
	counter++;
	vis[x][y] = 1;
	if(valid(x-1,y))
		dfs(x-1,y);
	if(valid(x+1,y))
		dfs(x+1,y);
	if(valid(x,y+1))
		dfs(x,y+1);
	if(valid(x,y-1))
		dfs(x,y-1);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	string maze[maxn];
	pii pos;
	for(int i = 0; i < n; i++)
	{
		cin >> maze[i];  
		for(int j = 0; j < m; j++)
			if(maze[i][j] == '.')
			{
				pos.ff = i;
				pos.ss = j;
				free_spot++;
			}
			else
				vis[i][j] = -1;

	}
	dfs(pos.ff,pos.ss);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i][j])
				maze[i][j] = 'X';  
	for(int i = 0; i < n; i++)
		cout << maze[i] << "\n";

    return 0;
}

