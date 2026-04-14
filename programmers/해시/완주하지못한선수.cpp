#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> m;
    for(int i=0;i<participant.size();i++){
        m[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        m[completion[i]]--;
    }
    for(auto [name,cnt] : m){
        if(cnt>0) return name;
    }
}