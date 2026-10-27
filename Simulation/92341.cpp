#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> fees;
vector<string> records;
map<int,string>parking;
map<int,int>timelist;
vector<int>answer;

int timeCalculate(string start, string end){
    int start_si=stoi(start.substr(0,2));
    int start_bun=stoi(start.substr(3,2));

    int end_si=stoi(end.substr(0,2));
    int end_bun=stoi(end.substr(3,2));

    int during=(end_si*60+end_bun)-(start_si*60+start_bun);

    return during;
}

void payCalculate(vector<int>fees, map<int,int>timelist){
    for(auto it:timelist){
        if(it.second<fees[0]){
            answer.push_back(fees[1]);
            continue;
        }else{
            int uni=(it.second-fees[0])/fees[2];
            int pay=fees[1]+(it.second-fees[0])/fees[2]*fees[3];
            if((it.second-fees[0])%fees[2]!=0){
                answer.push_back(pay+fees[3]);
            }else{
                answer.push_back(pay);
            }
        }
    }
}

int main(){

    for(int i=0;i<4;i++){
        int a;
        cin>>a;

        fees.push_back(a);
    }

    int n;
    cin>>n;

    cin.ignore();

    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);

        records.push_back(s);
    }

    for(int i=0;i<records.size();i++){
        string time;
        int carNumber;
        string in_out;

        stringstream ss(records[i]);
        ss>>time>>carNumber>>in_out;

        if(in_out=="IN"){
            parking.insert({carNumber, time});
            if(timelist.find(carNumber) == timelist.end()){
                timelist[carNumber] = 0;
            }

        }else {
            auto it=parking.find(carNumber);
            string start=it->second;
            int during=timeCalculate(start, time);

            timelist[carNumber]+=during;
            parking.erase(carNumber);
        }
    }

    if(!parking.empty()){
        for(auto it:parking){
            int during=timeCalculate(it.second, "23:59");
            timelist[it.first]+=during;
        }
    }

    payCalculate(fees, timelist);

    for(auto it:timelist){
        cout<<it.first<<" -> "<<it.second<<"\n";
    }

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }


}