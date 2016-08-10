#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// Z-Algorithm for Pattern Matching
// O(n+m)
inline vector<int> calculateZ(string inp)
{
	int len = inp.length();
	vector<int> Z(len);
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


	string s; cin >> s;
	int len = s.length();
	vector<int> z = calculateZ(s);

	int max_so_far = 0;
	for(int i = 0; i < z.size(); i++)
	{
		if(z[i] == len-i && max_so_far >= len-i)
		{
			int id = len-i;
			for(int j = 0; j < id; j++)
				printf("%c",s[j]);
			return 0;
		}
		max_so_far = max ( max_so_far , z[i]);
	}
	printf("%s\n","Just a legend");
	return 0;
}
