#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums;
    vector<int> mons;

    int n;
    cin>>n;
    

    for(int i=0;i<n;i++){
        int nn;
        cin>>nn;

        nums.push_back(nn);
    }

    for(int i=0;i<n;i++){
        if(find(mons.begin(), mons.end(),nums[i])==mons.end()){
            mons.push_back(nums[i]);
        }
    }

    if(mons.size()>nums.size()/2){
        cout<< nums.size()/2;
    }else{
        cout<<mons.size();
    }


}