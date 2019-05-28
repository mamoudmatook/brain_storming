#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	// Reading input from STDIN
	int n=0;
	for (int i = 0; i < n; i++)  
	{
        for (int len = 1; len <= n - i; len++)
{
	string l=s.substr(i,len);
	cout<<l<<endl;
	if (l == string(l.rbegin(), l.rend()))
	
	n++;
}
}
	cout  << n;		// Writing output to STDOUT
}
