#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int start = 20140402;

    //윤년 
    //2016 2020 2024
    for (int i = 1; i < n; i++) {
        start++;
        if ((start / 10000) % 4 == 0) {//윤년일때
            //1 3 5 7
            if (((start % 10000) / 100) < 8 and ((start % 10000) / 100) % 2 == 1) {
                if (start % 100 > 31) {
                    start = start + 69;
                }
            }
            //8 10 12
            else if (((start % 10000) / 100) > 7 and ((start % 10000) / 100) % 2 == 0){
                if (start % 100 > 31) {
                    start = start + 69;
                }
            }
            else if (((start % 10000) / 100) == 2) {
                if (start % 100 > 29) {
                    start = start + 71;
                }

            }
            else {
                if (start % 100 > 30) {
                    start = start + 70;
                }
            }

            if (((start % 10000) / 100) > 12) {
                start = start + 8800;
            }
        }
        else {//윤년 아닐때
            //1 3 5 7
            if (((start % 10000) / 100) < 8 and ((start % 10000) / 100) % 2 == 1) {
                if (start % 100 > 31) {
                    start = start + 69;
                }
            }
            //8 10 12
            else if (((start % 10000) / 100) > 7 and ((start % 10000) / 100) % 2 == 0) {
                if (start % 100 > 31) {
                    start = start + 69;
                }
            }
            else if (((start % 10000) / 100) == 2) {
                if (start % 100 > 28) {
                    start = start + 72;
                }

            }
            else{
                if (start % 100 > 30) {
                    start = start + 70;
                }
            }

            if (((start % 10000) / 100) > 12) {
                start = start + 8800;
            }
        }
    }
    cout << start / 10000;
    if ((start % 10000) / 100 < 10) {
        cout << "-0" << (start % 10000) / 100;
    }
    else {
        cout << "-" << (start % 10000) / 100;
    }
    if (start % 100 < 10) {
        cout << "-0" << start % 100;
    }
    else {
        cout << "-" << start % 100;
    }    
    
    return 0;
}


