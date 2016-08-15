#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;


const int maxn = 1e5*27;
int trie[maxn][27], ok[27];
string str;
int sz = 1 , len ,  ans , k;
inline void insert(int id)
{
	int fans = 0 ,  node = 0;
	for(int i = id; i < len; i++)
	{
		fans += !ok[str[i]-'a'];  
		if(fans > k )
			return;
		if(trie[node][str[i]-'a'] == -1)
		{
			ans++;
			trie[node][str[i]-'a'] = sz++;
		}
		node = trie[node][str[i]-'a'];
	}
}
int main()
{
	memset(trie,-1,sizeof(trie));
	cin >> str;
	len = str.length();
	string t; cin >> t;
	for(int i = 0; i < 26; i++)
		if(t[i] == '1')
			ok[i] = 1;
	cin >> k;
	for(int i = 0; i < len; i++)
		insert(i);  

	cout << ans << "\n";

	return 0;
}
