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
const int maxlen = 1e6+7;
string s; 
struct node
{
	int open , close , ans;
	node()
	{
		open = close = ans = 0;  
	}
	node(int o , int c , int a)
	{
		open = o;
		close = c;
		ans = a;
	}
	void merge(node l ,node r)
	{
		open = l.open + r.open - min(l.open,r.close);
		close = l.close + r.close - min(l.open,r.close);
		ans = l.ans + r.ans + 2*min(l.open,r.close);
	}
}tree[4*maxlen];
void build(int id , int left ,int right)
{
	if(left == right)
	{
		tree[id] = node(0,0,0);
		if(s[left] == '(')
		{
			tree[id].open++;
		}
		else
		{
			tree[id].close++;  
		}
		return;
	}
	int mid = mid(left, right);
	build(2*id,left,mid);
	build(2*id+1,mid+1,right);
	tree[id] = node();
	tree[id].merge(tree[2*id],tree[2*id+1]);
}
node query(int id ,int left, int right ,int lq ,int rq)
{
	if(left > rq || right < lq)
		return node(0,0,0);
	if(left >= lq && right <= rq)
		return tree[id];
	int mid = mid(left,right);
	node _l = query(2*id,left,mid,lq,rq);
	node _r = query(2*id+1,mid+1,right,lq,rq);
	node temp = node();
	temp.merge(_l,_r);
	return temp;
}
int main()
{
	cin >> s;
	build(1,0,s.length());
	int q;
	cin >> q;
	while(q--)
	{
		int l , r; 
		cin >> l >> r;
		cout << query(1,0,s.length(),l-1,r-1).ans << "\n";
	}
    return 0;
}

