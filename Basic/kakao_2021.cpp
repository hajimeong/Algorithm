#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, char> nums;
string s;
int idx=0;
string result;

void func(){
    int start_index=0;
    while(true){
        if(start_index==s.length()){
            break;
        }
        for(auto &i:nums){
        bool check=true;
        if(s[start_index]==i.second){
            result.push_back(i.second);
            start_index+=1;
            continue;
        }

        for(int j=0;j<i.first.length();j++){
            if(s[start_index+j]!=i.first[j]){
                check=false;
            }
        }
        if(check){
            result.push_back(i.second);
            start_index+=i.first.length();
            break;
        }
    }
}
    
}


int main(){
    cin>>s;

    int answer;

    nums["zero"]='0';
    nums["one"]='1';
    nums["two"]='2';
    nums["three"]='3';
    nums["four"]='4';
    nums["five"]='5';
    nums["six"]='6';
    nums["seven"]='7';
    nums["eight"]='8';
    nums["nine"]='9';

    func();

    answer=stoi(result);
    cout<<answer;

}