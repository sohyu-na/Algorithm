#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int CNT =9;

void select(vector <int>& v , int sum) {
    for (int i = 0; i < CNT; i++) {
        for (int j = i + 1; j < CNT; j++) {
            if (sum - v[i] - v[j]==100) {
                // i , j 순으로 존재하기때문에 
                // i를 먼저 지우면 j의 인덱스가 달라짐 => i먼저
                v.erase(v.begin()+j);
                v.erase(v.begin() + i);
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v(CNT);
    int sum = 0;

    for (int i = 0; i < CNT; i++) {
        cin >> v[i];
        sum += v[i];
    }
    select(v, sum);

    sort(v.begin(), v.end());
    for (int i = 0; i < CNT - 2; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
