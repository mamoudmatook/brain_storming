
// Sample code to perform I/O:

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int T;
	cin >>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    vector<string>finalLeague;
	    for(int i=0;i<n;i++)
	    cin>>finalLeague[i];
	    
	    std::sort(finalLeague.begin(), finalLeague.end());
       auto it = std::unique(finalLeague.begin(), finalLeague.end());
      finalLeague.erase(it, finalLeague.end());
      for (int i=0;i<finalLeague.size();i++)
      cout<<finalLeague[i]<<endl;
      
	    
	}
	// Reading input from STDIN
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here

