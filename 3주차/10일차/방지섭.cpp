#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<pair<int,int>> zeros, ones;
int n,m;

void input(){
    cin >> n >> m;
    for(int i=0;i<m+1;i++){
        int a,b,c; cin >> a >> b >> c;
        if(c == 1){
            zeros.push_back({a,b}); // 내리막길
        }
        else ones.push_back({a,b}); // 오르막길
    }
}

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void solve(){
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;
    int mn = 0, mx = 0;
    int cnt = n;
    // 최소 찾기
    for(int i=0;i<zeros.size();i++){
        int p1 = find(zeros[i].first), p2 = find(zeros[i].second);
        if(p1 == p2) continue;
        if(p1 < p2) swap(p1,p2);
        parent[p1] = p2;
        if(--cnt == 0) break;
    }
    mn = cnt; // 나머지는 어짜피 1로 다 채울 거니깐

    cnt = n;
    for(int i=0;i<=n;i++) parent[i] = i;
    // 최대 찾기
    for(int i=0;i<ones.size();i++){
        int p1 = find(ones[i].first), p2 = find(ones[i].second);
        if(p1 == p2) continue;
        if(p1 < p2) swap(p1,p2);
        parent[p1] = p2;
        if(--cnt == 0) break;
    }
    mx = n - cnt; // 나머지는 어짜피 0으로 다 채울 거니깐

    cout << mx*mx - mn*mn;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}