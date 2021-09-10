#include <iostream>
using namespace std;

int V1[] = {0, 1, 2};
int V2[] = {0, 1, 2};
int E1[3][3], E2[3][3], E3[5][5];

void ring_sum(int arr1[], int arr2[], int m, int n)
{
    cout << "\nSet of vertices in ring sum of the graphs G1 and G2 are:\n";
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++]<<" ";
        else if (arr2[j] < arr1[i])
            cout << arr2[j++]<<" ";
        else
        {
            cout << arr2[j++]<<" ";
            i++;
        }
    }
    while (i < m)
        cout << arr1[i++];
    while (j < n)
        cout << arr2[j++];

    cout << "\n";
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            if (i<m && j<m && E1[i][j] == E2[i][j])
                E3[i][j] = 0;
            else if (i<m && j<m && E1[i][j]>E2[i][j])
                E3[i][j] = E1[i][j];
            else
                E3[i][j] = E2[i][j];
        }
    }

    cout << "\nAdjacency matrix of ring sum of graphs G1 and G2 is:\n\t";
    for (i = 0; i < n; i++)
        cout << i << "\t";
    cout << "\n\t";

    for (i = 0; i < n; i++)
        cout << " ";
    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << i << "|\t";
        for (j = 0; j < n; j++)
        {
            cout << E3[i][j] << "\t";
        }
    }
}

int main()
{
    int m = sizeof(V1) / sizeof(V1[0]);
    int n = sizeof(V2) / sizeof(V2[0]);
    int i, j, k;
    cout << "Enter the adjacency matrix(symmetric) for graph G1:\n";
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            cin >> E1[i][j];

    cout << "\nEnter the adjacency matrix(symmetric) for graph G2:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> E2[i][j];


    ring_sum(V1, V2, m, n);

    cout << endl;
    return 0;
}
