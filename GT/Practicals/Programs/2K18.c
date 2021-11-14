#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
bool try_kuhn(int v) {
if (used[v])
return false;
used[v] = true;
for (int to : g[v]) {
if (mt[to] == -1 || try_kuhn(mt[to])) {
mt[to] = v;
return true;
}
}
return false;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
cin>>n>>k;
int m;
cin>>m;
g.assign(n, vector<int>());
for(int i =0; i<m; i++){
int a, b;
cin>>a>>b;
g[--a].push_back(--b);
}
mt.assign(k, -1);
for (int v = 0; v < n; ++v) {
used.assign(n, false)
try_kuhn(v);
}
int count = 0;
for (int i = 0; i < k; ++i)
if (mt[i] != -1)
count++;

cout<<"Maximum matching in given bipartite graph : \n"<<count<<"\n";
cout<<"Included Edges: \n";
for (int i = 0; i < k; ++i)
if (mt[i] != -1)
printf("%d %d\n", mt[i] + 1, i + 1);

return 0;
}
