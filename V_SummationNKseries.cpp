#include <bits/stdc++.h>
using namespace std;

#define MaxN 1040

long long int m = 1000000007;     // m is the modulo
long long int F[MaxN][MaxN], nk[MaxN];
long long int inverse[MaxN];
long long int arr[MaxN][MaxN];

void combinatorics() {
    for(int i = 0; i < MaxN; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for(int i = 2; i < MaxN; i++) {
        for(int j = 1; j < i; j++){
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % m;
        }
    }
    inverse[0] = inverse[1] = 1;
    for(int i = 2; i < MaxN; i++) {
        inverse[i] = (-(long long int)(m / i) *
                      (long long int)inverse[m % i]) % m + m;
    }
}

void compute() {
    F[0][0] = 1;
    F[1][0] = F[1][1] = inverse[2];
    for(int i = 2; i < MaxN - 1; i++) {
        F[i][0] = i + 1;
        for(int j = 0;j <= i - 1; j++){
            F[i][0] = (F[i][0] - (long long int)arr[i + 1][j] * F[j][0]) % m;
        }
        F[i][0] = (F[i][0] * (long long int)inverse[i + 1]) % m;
        if(F[i][0] < 0) {
            F[i][0] += m;
        }
        for(int j = 1; j <= i; j++) {
            F[i][j] = ((((F[i - 1][j - 1] * (long long int)i) % m) *
                         (long long int)inverse[j+1]) % m);
        }
    }
}

void put_nk(long long int n, int k) {
    nk[0] = n;
    for(int i = 1; i <= k + 2; i++){
        nk[i] = (nk[i - 1] * n) % m;
    }
}

long long int f(int k) {
    long long int answer = 0;
    for(int i = 0;i < k + 1; i++) {
        answer = (answer + (long long int)F[k][i] * nk[i]) % m;
    }
    return answer;
}

int main() {
    long long int n, answer;
    int k, test;
    cin >> test;
    
    combinatorics();
    compute();

    for(int i = 0; i < test; i++) {
        cin >> n >> k;
        n %= m;
        put_nk(n, k);

        answer = f(k);
        if(answer < 0) {
            answer += m;
        }
        cout << answer << endl;
    }
    return 0;
}
