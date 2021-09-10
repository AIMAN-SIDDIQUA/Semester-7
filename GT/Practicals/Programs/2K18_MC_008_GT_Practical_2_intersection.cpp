#include <iostream>
using namespace std;

int V1[] = {0, 1};
int V2[] = {0, 1, 2};
int E1[2][2], E2[3][3], E3[5][5];

void intersection(int arr1[], int arr2[], int m, int n)
{
    cout << "\nSet of vertices in intersection of the graphs G1 and G2 is:\n";
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            cout << arr2[j++]<<" ";
            i++;
        }
    }

    cout << "\n";
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            if (E1[i][j] == E2[i][j])
                E3[i][j] = E1[i][j];
            else
                E3[i][j] = 0;
        }

    cout << "\nAdjacency matrix of intersection of graphs G1 and G2 is:\n\t";

    for (i = 0; i < m; i++)
        cout << i << "\t";
    cout << "\n\t";
    for (i = 0; i < m; i++)
        cout << " ";
    for (i = 0; i < m; i++)
    {
        cout << "\n"
             << i << "|\t";
        for (j = 0; j < m; j++)
        {
            cout << E3[i][j] << "\t";
        }
    }
    cout << endl;
}

int main()
{

    int m = sizeof(V1) / sizeof(V1[0]);
    int n = sizeof(V2) / sizeof(V2[0]);

    int i, j, k;
    cout << "Enter the adjacency matrix(symmetric) for graph 1:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            cin >> E1[i][j];

    }

    cout << "\nEnter the adjacency matrix(symmetric) for graph 2:"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> E2[i][j];
    }

    intersection(V1, V2, m, n);

    return 0;
}
