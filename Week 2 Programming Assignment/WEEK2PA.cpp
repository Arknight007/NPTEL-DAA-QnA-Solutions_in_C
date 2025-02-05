#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> L(N), U(N), A(N), R(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> U[i];
        A[i] = U[i] - L[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] > A[j]) {
                R[i] += 2;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << R[i] << " ";
    }
    return 0;
}
