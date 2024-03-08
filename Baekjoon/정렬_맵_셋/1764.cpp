#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    set <string> s;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.insert(name);
    }

    int size;
    set <string> s_out;
    for (int j = 0; j < m; j++) {
        cin >> name;
        /* set에 중복 불가를 이용해 size로 일치 확인
        size = s.size();
        s.insert(name);
        if (s.size() == size) {
            s_out.insert(name);
        }
        */
        //find()함수 사용, 없으면 s.end()반환
        if (s.end() != s.find(name)) {
            s_out.insert(name);
        }
    }

    cout << s_out.size() << "\n";
    for (auto iter = s_out.begin(); iter != s_out.end(); iter++) {
        cout << *iter << "\n";
    }
    return 0;
}
