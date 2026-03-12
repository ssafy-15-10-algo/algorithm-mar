#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int rev[1001];
int inDegree[1001];
int dp[1001]; // dp[i]=j : i에 도달하기 위한 최대 비용은 j
vector<pair<int,int>> graph[1001]; // 노드, 가중치

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c; // a->b: c
        graph[a].push_back({b,c});
        inDegree[b]++;
    }
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x=q.front();
        q.pop();

        for (int i=0;i<graph[x].size();i++) {
            int y=graph[x][i].first;
            int w=graph[x][i].second;

            if (dp[y]<dp[x]+w) {
                dp[y]=dp[x]+w;
                rev[y]=x;
            }

            inDegree[y]--;
            if (y!=1&&!inDegree[y]) q.push(y);
        }
    }

    cout<<dp[1]<<"\n";

    vector<int> routes;
    int cur=1;
    routes.push_back(1);
    while (1) {
        routes.push_back(rev[cur]);
        cur=rev[cur];

        if (cur==1) break;
    }

    reverse(routes.begin(),routes.end());

    for (int i=0;i<routes.size();i++) {
        cout<<routes[i]<<" ";
    }
}
