#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구조체 구현
struct student{
    string name;
    int ks,es,ms;
};

//비교함수 구현하는 방법 예시코드 참고
bool cmp (const student& s1, const student& s2){
    if(s1.ks!=s2.ks) //국어점수가 같지 않으면 
        return s1.ks > s2.ks;//국어 점수가 감소하는 순서->앞에 높은 점수 
    if(s1.es!=s2.es)
        return s1.es < s2.es;
    if(s1.ms!=s2.ms)
        return s1.ms > s2.ms;
    else
        return s1.name <s2.name;
}


int main()
{
    int n;
    cin >> n;
    vector<student> std(n);
    for(int i=0;i<n;i++){
        cin >> std[i].name >> std[i].ks >> std[i].es >> std[i].ms;
    }
    sort(std.begin(),std.end(),cmp); //함수 만들어서 조건 걸기 
	for(int i=0;i<n;i++){
        cout << std[i].name <<"\n";
    }

    return 0;
}