#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std; 

int main() {
	int t; cin >> t;
	int n; 
	string info;
	for (int i = 0; i < t; i++) {
		cin >> n;
		char U[3][3] = { {'w','w','w'},{'w','w','w'},{'w','w','w'} };
		char D[3][3] = { {'y','y','y'},{'y','y','y'},{'y','y','y'} };
		char F[3][3] = { {'r','r','r'},{'r','r','r'},{'r','r','r'} };
		char B[3][3] = { {'o','o','o'},{'o','o','o'},{'o','o','o'} };
		char L[3][3] = { {'g','g','g'},{'g','g','g'},{'g','g','g'} };
		char R[3][3] = { {'b','b','b'},{'b','b','b'},{'b','b','b'} };

		for (int j = 0; j < n; j++) {
			cin >> info;
			if (info[0] == 'U') {
				if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[0][a];
					}
					for (int a = 0; a < 3; a++) {
						L[0][a] = F[0][a];
					}
					for (int a = 0; a < 3; a++) {
						F[0][a] = R[0][a];
					}
					for (int a = 0; a < 3; a++) {
						R[0][a] = B[0][a];
					}
					for (int a = 0; a < 3; a++) {
						B[0][a] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[0][2-a]; 
					}
					for (int a = 0; a < 3; a++) {
						U[0][2-a] = U[a][0];
					}
					for (int a = 0; a < 3; a++) {
						U[a][0] = U[2][a];
					}
					for (int a = 0; a < 3; a++) {
						U[2][a] = U[2-a][2];
					}
					for (int a = 0; a < 3; a++) {
						U[2-a][2] = temp[0][a];
					}


				}
				else if (info[1] == '-') {
					char temp[3][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = R[0][a];
					}
					for (int a = 0; a < 3; a++) {
						R[0][a] = F[0][a];
					}
					for (int a = 0; a < 3; a++) {
						F[0][a] = L[0][a];
					}
					for (int a = 0; a < 3; a++) {
						L[0][a] = B[0][a];
					}
					for (int a = 0; a < 3; a++) {
						B[0][a] = temp[0][a];
					}


					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[0][a];
					}
					for (int a = 0; a < 3; a++) {
						U[0][a] = U[a][2];
					}
					for (int a = 0; a < 3; a++) {
						U[a][2] = U[2][2-a];
					}
					for (int a = 0; a < 3; a++) {
						U[2][2-a] = U[2-a][0];
					}
					for (int a = 0; a < 3; a++) {
						U[2-a][0] = temp[0][a];
					}
				}
			}
			else if (info[0] == 'D') {
				if (info[1] == '-') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[2][a];
					}
					for (int a = 0; a < 3; a++) {
						L[2][a] = F[2][a];
					}
					for (int a = 0; a < 3; a++) {
						F[2][a] = R[2][a];
					}
					for (int a = 0; a < 3; a++) {
						R[2][a] = B[2][a];
					}
					for (int a = 0; a < 3; a++) {
						B[2][a] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = D[0][2-a];
					}
					for (int a = 0; a < 3; a++) {
						D[0][2-a] = D[a][0];
					}
					for (int a = 0; a < 3; a++) {
						D[a][0] = D[2][a];
					}
					for (int a = 0; a < 3; a++) {
						D[2][a] = D[2-a][2];
					}
					for (int a = 0; a < 3; a++) {
						D[2-a][2] = temp[0][a];
					}
				}
				else if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = R[2][a];
					}
					for (int a = 0; a < 3; a++) {
						R[2][a] = F[2][a];
					}
					for (int a = 0; a < 3; a++) {
						F[2][a] = L[2][a];
					}
					for (int a = 0; a < 3; a++) {
						L[2][a] = B[2][a];
					}
					for (int a = 0; a < 3; a++) {
						B[2][a] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = D[0][a];
					}
					for (int a = 0; a < 3; a++) {
						D[0][a] = D[a][2];
					}
					for (int a = 0; a < 3; a++) {
						D[a][2] = D[2][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						D[2][2 - a] = D[2-a][0];
					}
					for (int a = 0; a < 3; a++) {
						D[2-a][0] = temp[0][a];
					}
				}
			}
			else if (info[0] == 'F') {
				if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[2][a];
					}
					for (int a = 0; a < 3; a++) {
						U[2][a] = L[2-a][2];
					}
					for (int a = 0; a < 3; a++) {
						L[2-a][2] = D[0][a];
					}
					for (int a = 0; a < 3; a++) {
						D[0][a] = R[a][0];
					}
					for (int a = 0; a < 3; a++) {
						R[a][0] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = F[0][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						F[0][2 - a] = F[a][0];
					}
					for (int a = 0; a < 3; a++) {
						F[a][0] = F[2][a];
					}
					for (int a = 0; a < 3; a++) {
						F[2][a] = F[2 - a][2];
					}
					for (int a = 0; a < 3; a++) {
						F[2 - a][2] = temp[0][a];
					}

				}
				else if (info[1] == '-') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[2-a][2];
					}
					for (int a = 0; a < 3; a++) {
						L[2-a][2] = U[2][a];
					}
					for (int a = 0; a < 3; a++) {
						U[2][a] = R[a][0];
					}
					for (int a = 0; a < 3; a++) {
						R[a][0] = D[0][a];
					}
					for (int a = 0; a < 3; a++) {
						D[0][a] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = F[0][a];
					}
					for (int a = 0; a < 3; a++) {
						F[0][a] = F[a][2];
					}
					for (int a = 0; a < 3; a++) {
						F[a][2] = F[2][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						F[2][2 - a] =F[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						F[2 - a][0] = temp[0][a];
					}
				}
			}
			else if (info[0] == 'B') {
				if (info[1] == '-') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[0][a];
					}
					for (int a = 0; a < 3; a++) {
						U[0][a] = L[2-a][0];
					}
					for (int a = 0; a < 3; a++) {
						L[2-a][0] = D[2][a];
					}
					for (int a = 0; a < 3; a++) {
						D[2][a] = R[a][2];
					}
					for (int a = 0; a < 3; a++) {
						R[a][2] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = B[0][a];
					}
					for (int a = 0; a < 3; a++) {
						B[0][a] = B[a][2];
					}
					for (int a = 0; a < 3; a++) {
						B[a][2] = B[2][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						B[2][2 - a] = B[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						B[2 - a][0] = temp[0][a];
					}
				}
				else if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[2-a][0];
					}
					for (int a = 0; a < 3; a++) {
						L[2-a][0] = U[0][a];
					}
					for (int a = 0; a < 3; a++) {
						U[0][a] = R[a][2];
					}
					for (int a = 0; a < 3; a++) {
						R[a][2] = D[2][a];
					}
					for (int a = 0; a < 3; a++) {
						D[2][a] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = B[0][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						B[0][2 - a] = B[a][0];
					}
					for (int a = 0; a < 3; a++) {
						B[a][0] = B[2][a];
					}
					for (int a = 0; a < 3; a++) {
						B[2][a] = B[2 - a][2];
					}
					for (int a = 0; a < 3; a++) {
						B[2 - a][2] = temp[0][a];
					}
				}
			}
			else if (info[0] == 'L') {
				if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = F[a][0];
					}
					for (int a = 0; a < 3; a++) {
						F[a][0] = U[a][0];
					}
					for (int a = 0; a < 3; a++) {
						U[a][0] = B[2-a][2];
					}
					for (int a = 0; a < 3; a++) {
						B[2-a][2] = D[a][2];
					}
					for (int a = 0; a < 3; a++) {
						D[a][2] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[0][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						L[0][2 - a] = L[a][0];
					}
					for (int a = 0; a < 3; a++) {
						L[a][0] = L[2][a];
					}
					for (int a = 0; a < 3; a++) {
						L[2][a] = L[2 - a][2];
					}
					for (int a = 0; a < 3; a++) {
						L[2 - a][2] = temp[0][a];
					}
				}
				else if (info[1] == '-') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[a][0];
					}
					for (int a = 0; a < 3; a++) {
						U[a][0] = F[a][0];
					}
					for (int a = 0; a < 3; a++) {
						F[a][0] = D[a][2];
					}
					for (int a = 0; a < 3; a++) {
						D[a][2] = B[2 - a][2];
					}
					for (int a = 0; a < 3; a++) {
						B[2 - a][2] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = L[0][a];
					}
					for (int a = 0; a < 3; a++) {
						L[0][a] = L[a][2];
					}
					for (int a = 0; a < 3; a++) {
						L[a][2] = L[2][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						L[2][2 - a] = L[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						L[2 - a][0] = temp[0][a];
					}
				}
			}
			else if (info[0] == 'R') {
				if (info[1] == '-') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = F[a][2];
					}
					for (int a = 0; a < 3; a++) {
						F[a][2] = U[a][2];
					}
					for (int a = 0; a < 3; a++) {
						U[a][2] = B[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						B[2 - a][0] = D[a][0];
					}
					for (int a = 0; a < 3; a++) {
						D[a][0] = temp[0][a];
					}

					for (int a = 0; a < 3; a++) {
						temp[0][a] = R[0][a];
					}
					for (int a = 0; a < 3; a++) {
						R[0][a] = R[a][2];
					}
					for (int a = 0; a < 3; a++) {
						R[a][2] = R[2][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						R[2][2 - a] = R[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						R[2 - a][0] = temp[0][a];
					}
				}
				else if (info[1] == '+') {
					char temp[1][3];
					for (int a = 0; a < 3; a++) {
						temp[0][a] = U[a][2];
					}
					for (int a = 0; a < 3; a++) {
						U[a][2] = F[a][2];
					}
					for (int a = 0; a < 3; a++) {
						F[a][2] = D[a][0];
					}
					for (int a = 0; a < 3; a++) {
						D[a][0] = B[2 - a][0];
					}
					for (int a = 0; a < 3; a++) {
						B[2 - a][0] = temp[0][a];
					}


					for (int a = 0; a < 3; a++) {
						temp[0][a] = R[0][2 - a];
					}
					for (int a = 0; a < 3; a++) {
						R[0][2 - a] = R[a][0];
					}
					for (int a = 0; a < 3; a++) {
						R[a][0] = R[2][a];
					}
					for (int a = 0; a < 3; a++) {
						R[2][a] = R[2 - a][2];
					}
					for (int a = 0; a < 3; a++) {
						R[2 - a][2] = temp[0][a];
					}
				}
			}
        }
            
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                cout << U[a][b];
            }
            cout << "\n";
		}
	}
}

	