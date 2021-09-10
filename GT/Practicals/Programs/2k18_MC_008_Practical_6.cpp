#include<bits/stdc++.h>
using namespace std;

#define N 4
#define INF 100000

void floydWarshall(int g[][N])
{
    int dist[N][N], i, j, k;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = g[i][j];

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int g[4][4] = {{0 ,5,INF,2},
                {INF,2,4,1},
                {INF,INF,0,1},
                {INF,INF,INF,0}};

    floydWarshall(g);

    return 0;
}
