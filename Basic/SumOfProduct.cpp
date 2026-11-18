#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long a,b,c;
        long long result=0;
        cin>>a>>b>>c;
        
        long long aa=(a*(a+1)/2)%998244353;
        long long bb=(b*(b+1)/2)%998244353;
        long long cc=(c*(c+1)/2)%998244353;
        
        result=aa*bb%998244353*cc%998244353;
        
        cout<<result<<"\n";

	}
	return 0;
}