#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_W = 15;
const int N = 6;
const int V[N] = {15, 4, 2, 8, 1, 3};
const int W[N] = {11, 4, 1, 5, 3, 2};

int all(int i, int j) {
    if (i == N) return 0;
    else if (j < W[i]) return all(i + 1, j);
    else return max(all(i + 1, j - W[i]) + V[i], all(i + 1, j));
}

int cache[N + 1][MAX_W + 1];
int done[N + 1][MAX_W + 1];
int memo(int i, int j) {
    if (i == N) return 0;
    if (done[i][j]) return cache[i][j];
    
    done[i][j] = true;
    if (j < W[i]) return cache[i][j] = memo(i + 1, j);
    else return cache[i][j] = max(memo(i + 1, j - W[i]) + V[i], memo(i + 1, j));
}

int dp() {
    int table[N + 1][MAX_W + 1];

    for(int w = 0; w <= MAX_W; ++w) {
        table[0][w] = 0;
    }

    for(int i = 0; i < N; ++i) {
        for(int w = 0; w <= MAX_W; ++w) {
            if (w >= W[i]) table[i + 1][w] =  max(table[i][w - W[i]] + V[i], table[i][w]);
            else table[i + 1][w] = table[i][w];
        }
     }

    return table[N][MAX_W];
}

int main() {
    cout << all(0, MAX_W) << endl;
    cout << memo(0, MAX_W) << endl;
    cout << dp() << endl;
    return 0;
}