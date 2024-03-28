#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B, V; cin >> A>>B>>V;
    int day = (V - A) / (A - B);
    if ((V - A) % (A - B) == 0) {
        cout << day+1;
    }
    else {
        cout << day + 2;
    }
    
    
    return 0;
    
}


