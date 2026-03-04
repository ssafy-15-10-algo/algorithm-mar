#include <bits/stdc++.h>
using namespace std;

struct node{
    int n1,n2,c;
    bool operator<(const node other) const{
        if(c == other.c) return n1 < other.n1;
        return c > other.c;
    }
};

priority_queue<node> pq;
int n,m,k;
vector<int> parent;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void input(){
    cin >> n >> m >> k;
    parent.resize(n+1); for(int i=1;i<=n;i++) parent[i] = i;
    vector<int> ps(k);
    for(int i=0;i<k;i++){ 
        cin >> ps[i];
    }
    for(int i=0;i<k-1;i++){
        for(int j=i+1;j<k;j++){
            pq.push({ps[i], ps[j], 0});
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        pq.push({a,b,c});
    }
}

void solve(){
    int ans = 0;
    int cnt = n - 1; // 연결해야 할 간선
    while(!pq.empty() && cnt){
        node t = pq.top(); 
        pq.pop();

        int p1 = find(t.n1), p2 = find(t.n2); // 사이클 확인
        if(p1 == p2) continue;
        if(p1 > p2) swap(p1,p2);
        parent[p1] = p2;

        cnt--;
        ans += t.c;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}