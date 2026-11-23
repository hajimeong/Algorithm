#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int dx[4]={0,1, 0, -1};
        int dy[4]={1, 0, -1, 0};
        
        int n;
        cin>>n;
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        int x=0;
        int y=0;
        int idx=0;
        
        
        for(int i=1;i<=n*n;i++){
        	v[x][y]=i;
            
            int nx=x+dx[idx];
            int ny=y+dy[idx];
            
            if(nx<0||ny<0||nx>=n||ny>=n||v[nx][ny]!=0){
            	idx=(idx+1)%4;
            }
            
            x+=dx[idx];
            y+=dy[idx];
        }
        
        cout<<"#"<<test_case<<"\n";
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
            	cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }

	}
	return 0;
}