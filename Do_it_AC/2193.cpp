#include <iostream>
#include <vector>

    using namespace std;


    int main() {
        int N;
        cin >> N;

        vector <long long> d(N + 1);
        vector <long long> p(N + 1);

        d[1] = 0;
        p[1] = 1;

        for (int i = 2; i <= N; i++) {
            d[i] = d[i - 1] + p[i - 1];
            p[i] = d[i - 1];
        }

        cout << (d[N] + p[N]);
    }
