#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n,m; cin >> n >> m;
    //map 두개 안쓰면 시간초과남
    map <int,string> num_map ;
    map <string,int> name_map;
    //vector 안쓰면 입력 받는 중에 출력함 
    vector <string> v(m);

    string input;
    for (int i=1;i<n+1;i++){
        cin >> input;
        name_map[input]=i;
        num_map[i]=input;
    }

    for (int i=0;i<m;i++)
        cin >> v[i];
    
    for (int i=0;i<m;i++){
        if(isdigit(v[i][0]))//숫자인지 체크하는 함수
            cout << num_map[stoi(v[i])] << '\n';//string to int 
        else
            cout << name_map[v[i]] << '\n';
    }
    
    return 0;
    
}