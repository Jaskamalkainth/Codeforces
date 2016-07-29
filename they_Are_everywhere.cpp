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
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w<<"\n";}
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

string s;
int n;
set<char> st;
int to_catch;
int cnt[299];
bool check(int x)
{

	if(x < to_catch)
		return false;
	int sum = 0;
	for(int i = 0; i < 290; i++)
		cnt[i] = 0;
	for(int i = 0; i < x; i++)
		cnt[s[i]-'A']++;
	for(int i = 0; i < 290; i++)
		if(cnt[i] >= 1)
			sum++;
	if(sum == to_catch)
		return true;
	for(int i = x; i < n; i++)
	{
		if(cnt[s[i]-'A'] == 0)
			sum++;
		cnt[s[i]-'A']++;
		if(cnt[s[i-x]-'A'] == 1)
			sum--;  
		cnt[s[i-x]-'A']--;
		if(sum == to_catch)
			return true;
	}
	return false;
}


int main()
{
	scanf("%d",&n);
	cin >> s;
	set<int> temp;
	for(auto x: s)
		temp.insert(x);
	to_catch = temp.size();
	int low = 0; 
	int high = n+1;
	int ans;
	while(low < high)
	{
		int mid = mid(low,high);
		if(check(mid))
		{
			ans = mid;
			high = mid;
		}
		else
		{
			low = mid+1;  
		}
	}
	printf("%d\n",ans);


    return 0;
}

