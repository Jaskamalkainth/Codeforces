#include <iostream>
using namespace std;
int cnt[500];
int main()
{
    string s; cin >> s;
    for(char ch: s)
        cnt[ch]++;
    if(cnt['a'] == 0 || cnt['b'] == 0)
    {
        cout << "NO\n";
        return 0;
    }

    if(cnt['a'] != cnt['c'] && cnt['b'] != cnt['c'])
    {
        cout << "NO\n";
    }
    else
    {
        int i = 0;
        while(i < s.size() && s[i] == 'a')
            i++;
        while(i < s.size() && s[i] == 'b')
            i++;
        while(i < s.size() && s[i] == 'c')
            i++;
        if(i != s.size())
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
