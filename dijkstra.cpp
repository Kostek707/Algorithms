/*
 Implementatation of the dijkstra algorithm

 Calculates the shortest way on a graph from point 1 to the point given by the user.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int vis[1000000];
priority_queue<pair<int, int> >Q;
vector<vector<pair<int,int> > > g;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c*-1,b));
    }
    for(int i = 0; i<1000000; i++){
        vis[i]=100000;
    }
    vis[1]=0;
    Q.push(make_pair(0,1));
    while(!Q.empty()){
        int w = Q.top().second;
        Q.pop();
        for(int j = 0; j<g[w].size(); j++){
            if(vis[g[w][j].second]>vis[w]+(g[w][j].first*-1)){
                Q.push(g[w][j]);
                vis[g[w][j].second]=vis[w]+(g[w][j].first*-1);
            }
        }
    }
    int a;
    cin >> a;
    cout << vis[a] << "\n";
    return 0;
}
