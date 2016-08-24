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


const int maxn = 507;
string grid[maxn];

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int n , m; 

inline int valid(int x , int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}
inline void  pr(int tp)
{
	if(tp)
		cout << "YES\n";  
	else
		cout << "NO\n";  
}

map<pair<int,int>,int>vis;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> grid[i];
	pii init , fin;
	cin >> init.ff >> init.ss >> fin.ff >> fin.ss;
	init.ff--;
	init.ss--;
	fin.ff--;
	fin.ss--;

	if(init.ff == fin.ff && init.ss == fin.ss)
	{
		int flag = 0;
		for(int i = 0; i < 4; i++)
		{
			int x = init.ff + dx[i];  
			int y = init.ss + dy[i];  
			if(valid(x,y) && grid[x][y] == '.')
			{
				flag = 1;  
				break;
			}
		}
		if(flag)
			pr(true);
		else
			pr(false);
		return 0;
	}
	// check if neighbours
	int nflag = 0;
	for(int i = 0; i < 8; i++)
	{
		int x = init.ff + dx[i];  
		int y = init.ss + dy[i];  
		if(fin.ff == x && fin.ss == y)
			nflag = 1;
	}
	if(nflag)
	{
		if(grid[fin.ff][fin.ss] == 'X')
		{
			pr(1);
		}
		else
		{
			int flag = 0;
			for(int i = 0; i < 4; i++)
			{
				int xx = fin.ff + dx[i];  
				int yy = fin.ss + dy[i];  
				if(valid(xx,yy) && grid[xx][yy] == '.')
				{
					flag = 1;  
					break;
				}
			}
			if(flag)
				pr(true);
			else
				pr(false);
		}
		return 0;
	}
	queue<pii> q;
	q.push(mp(init.ff,init.ss));

	int fdestflag = (grid[fin.ff][fin.ss] == 'X') ? 1 : 0;
	grid[fin.ff][fin.ss] = '.';

	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		int x = top.ff;
		int y = top.ss;
		vis[mp(x,y)] = 1;
		if(x == fin.ff && y == fin.ss)
		{
			if(fdestflag)
			{
				pr(true);
			}
			else
			{
				int cntflag = 0;
				for(int i = 0; i < 4; i++)
				{
					int xx = fin.ff + dx[i];  
					int yy = fin.ss + dy[i];  
					if(valid(xx,yy) && grid[xx][yy] == '.')
					{
						cntflag++;
					}
				}
				if(cntflag >= 2)
					pr(true);
				else
					pr(false);

			}
			return 0;
		}
		for(int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];  
			int yy = y + dy[i];  
			if(valid(xx,yy) && grid[xx][yy] == '.' && !vis[mp(xx,yy)])
			{
				vis[mp(xx,yy)] = 1;
				q.push(mp(xx,yy));
			}
		}
	}
	//if no path.
	pr(false);
	return 0;
}

