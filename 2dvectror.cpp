#include <iostream>
#include <vector>
using namespace std;
int main()
{
	
        int n;
	cin>>n;
	vector<vector<int> > v;

	for(int i=0;i<n;i++)
	{
		int temp;
		vector<int> t;
		while(cin>>temp)
		{
			t.push_back(temp);
			
	       
		
		}
		v.push_back(t);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}



