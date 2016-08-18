#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
// Z-Algorithm for Pattern Matching
// O(n+m)
const int maxn = 2e5+7;
ll a[maxn],b[maxn];
vector<ll> da,db;
inline vector<ll> calculateZ(vector<ll> inp)
{
	int len = inp.size();
	vector<ll> Z(len);
	int left = 0;
	int right = 0;
	for(int k = 1; k < len; k++)
	{
		if(k > right)
		{
			left = right = k;
			while(right < len && inp[right] == inp[right-left])
			{
				right++;  
			}
			Z[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			// inside the Z-Box
			if(Z[k1] < right-k+1)
			{
				Z[k] = Z[k1];  
				//if the value is inside the Z-box then copy it
			}
			else
			{
				// otherwise do more comparisons
				left = k;
				while(right < len && inp[right] == inp[right-left])
				{
					right++;  
				}
				Z[k] = right-left;
				right--;
			}
		}
	}
	return Z;
	// Z[i] denotes the length of the longest substring starting from i which is also the prefix of the string.
}
int main()
{

	int n , m; cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];  
	for(int i = 0; i < m; i++)
		cin >> b[i];  

	for(int i = 0; i+1 < n; i++)
		da.push_back(a[i+1]-a[i]);  
	for(int i = 0; i+1 < m; i++)
		db.push_back(b[i+1]-b[i]);  


	vector<ll> str;
	for(auto x: db)
		str.push_back(x);
	str.push_back(10000000000ll);
	for(auto x: da)
		str.push_back(x);
	int chk = db.size();
	vector<ll> Zstr = calculateZ(str);


	int ans = 0;
	for(auto x: Zstr)
		if(x == chk)
			ans++;


	cout << ans << "\n";

	return 0;
}
