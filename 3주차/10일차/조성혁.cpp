#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> forBestGraph[1001]; // 내리막길의 가중치를 0으로 == 내리막길을 최대한 많이 == MST의 가중치 합은 오르막길의 개수
vector<pair<int,int>> forWorstGraph[1001]; // 오르막길의 가중치를 0으로 == MST의 가중치 합은 내리막길의 개수

int bestMST[1001];
int worstMST[1001];

int main() {
    int n,m;
    cin>>n>>m;

    for (int i=0;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;

        // 내리막길
        if (c==1) {
            forBestGraph[a].push_back({b,0});
            forBestGraph[b].push_back({a,0});

            forWorstGraph[a].push_back({b,1});
            forWorstGraph[b].push_back({a,1});
        }
        // 오르막길
        else {
            forBestGraph[a].push_back({b,1});
            forBestGraph[b].push_back({a,1});

            forWorstGraph[a].push_back({b,0});
            forWorstGraph[b].push_back({a,0});
        }
    }

    int cnt=0;
    int best=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    bestMST[0]=1;
    for (int i=0;i<forBestGraph[0].size();i++) {
        pq.push({forBestGraph[0][i].second,forBestGraph[0][i].first});
    }

    while (cnt<n) {
        int x=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if (bestMST[x]) continue;

        bestMST[x]=1;
        cnt++;
        best+=w;

        for (int i=0;i<forBestGraph[x].size();i++) {
            int y=forBestGraph[x][i].first;
            int nw=forBestGraph[x][i].second;
            pq.push({nw,y});
        }
    }

    cnt=0;
    int worst=0;
    while (!pq.empty()) pq.pop();
    worstMST[0]=1;
    for (int i=0;i<forWorstGraph[0].size();i++) {
        pq.push({forWorstGraph[0][i].second,forWorstGraph[0][i].first});
    }

    while (cnt<n) {
        int x=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if (worstMST[x]) continue;

        worstMST[x]=1;
        cnt++;
        worst+=w;

        for (int i=0;i<forWorstGraph[x].size();i++) {
            int y=forWorstGraph[x][i].first;
            int nw=forWorstGraph[x][i].second;
            pq.push({nw,y});
        }
    }

    cout<<(n-worst)*(n-worst)-best*best;
}
