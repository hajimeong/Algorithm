#include <iostream>
#include <string>
#include <vector>

using namespace std;

string video_len;
string pos;
string op_start;
string op_end;
vector<string> commands;

int main(){
    int n;
    cin>>n;

    cin>>video_len;
    cin>>pos;
    cin>>op_start;
    cin>>op_end;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        commands.push_back(s);
    }

    


}