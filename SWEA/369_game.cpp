#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        string s=to_string(i);
        int cnt=0;

        for(int j=0;j<s.length();j++){
            if(s[j]=='3'||s[j]=='6'||s[j]=='9') cnt++;
        }

        if(cnt==0) cout<<i;
        else {
            for(int j=0;j<cnt;j++){
                cout<<"-";
            }
        }
        if(i!=n) cout<<" ";
    }

    return 0;
}