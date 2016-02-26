#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long  a ,b ,c ; cin >> a>> b >> c;
	cout << min (2*a+2*b , min (2*a +2*c , min (2*b + 2*c , a+b+c) ) ) << "\n";
	return 0;
}
