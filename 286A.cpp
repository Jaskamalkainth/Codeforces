#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool ispalin(string s )
{
	string t = s;
	reverse(t.begin(),t.end());
	return ( s == t );
}
int main()
{
	string s; cin >> s;
	int l = s.length();
	for(int i = 0; i <= l; i++)
	{
		for( char ch = 'a' ; ch <= 'z'; ch++)
		{
			string new_s = s.substr(0,i) +ch + s.substr(i); 
			if( ispalin(new_s) )
			{
				cout << new_s << "\n";
				return 0;
			}
		}
	}
	cout << "NA";
	return 0;
}
