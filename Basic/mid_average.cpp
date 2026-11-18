#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v;
        long long sum=0;
        double result=0;
        for(int i=0;i<10;i++){
        	int a;
            cin>>a;
            
            v.push_back(a);
        }
        
        sort(v.begin(), v.end());
        
        for(int i=1;i<9;i++){
            sum+=v[i];
        }
        
        result=(double) sum/8;
        
        cout<<"#"<<test_case<<" ";
        cout<<round(result)<<"\n";

	}
	return 0;
}