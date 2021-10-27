#include<bits/stdc++.h>
using namespace std;

stack<int> courses;

bool explore(int u, list<int> adj[], bool visited[], bool rec[])
{
    visited[u]=true;
    rec[u] = true;

    bool flag = false;

    for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
    {
        if(!visited[*i] && explore(*i, adj, visited, rec))
            flag = true;

        else if(rec[*i])
            flag = true;
    }

    rec[u] = false;
    courses.push(u);

    return flag;
}

bool topologicalSort(list<int> adj[], int n)
{
    bool visited[n];
    memset(visited, false, sizeof(visited));

    bool rec[n];
    memset(rec,false,sizeof(rec));

    stack<int> st;

    for(int i=0; i<n; i++){
        if(!visited[i])
            if(explore(i, adj, visited, rec))
                return false;
    }

    return true;
}

int main(){
    int n,x;

    cout<<"Enter the number of courses: ";
    cin>>n;

    cout<<"\nEnter the number of prerequisites: ";
    cin>>x;

    list<int> adj[n];

    cout<<"\nEnter prerequisites for each course"<<endl;
    for(int i=0;i<x;i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
    }

    if(topologicalSort(adj, n)){
        cout<<"\nCourse Schedule: ";

        while(!courses.empty()){
            cout<<courses.top()+1<<" ";
            courses.pop();
        }
        cout<<endl;
    }
    else
        cout<<"\nCourse Scheduling is not possible"<<endl;

    return 0;
}
