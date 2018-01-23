#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string s, t; cin >> s >> t;
    string in; cin >> in;

    map<char, char> mp;
    for(int i = 0; i < s.size(); i++)
    {
        mp[(char)(s[i]-32)] = (char)(t[i]-32);
        mp[s[i]] = t[i];
    }
    for(int i = 0; i <= 9; i++)
        mp[(char)(i+48)] = (char)(i+48);
    string ans;
    for(auto c: in)
        ans.push_back(mp[c]);
    cout << ans << "\n";
    return 0;    
}
