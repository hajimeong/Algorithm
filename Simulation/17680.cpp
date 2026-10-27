#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cctype>
#include <string>

using namespace std;

int cacheSize;
vector<string> cities;
vector<pair<int, string>> cache;
int answer=0;

bool cmp(pair<int,string> a, pair<int,string>b) {
    return a.first>b.first;
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) {
                  return tolower(c);
              });
    return s;
}

int main(){
    cin>>cacheSize;

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string city;
        cin>>city;

        cities.push_back(city);
    }

    for(int i=0;i<cities.size();i++){
        bool exist=false;
        if(cache.empty()){
            cache.push_back({i, cities[i]});
            answer+=5;
            continue;
        }
        else{
            for(auto& it:cache){
            if(toLower(it.second)==toLower(cities[i])){
                it.first=i;
                exist=true;
                break;
            }
        }

        if(exist) answer+=1;
        else{
            if(cache.size()==cacheSize){
                cache.pop_back();   
            }
            cache.push_back({i, cities[i]});
            answer+=5;
        }
        sort(cache.begin(), cache.end(),cmp);
    }

        for(int i=0;i<cache.size();i++){
            cout<<cache[i].first<<"["<<cache[i].second<<"] ";
        }
        cout<<"\n";
    }

    cout<<answer;

}