#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Cmp {
    bool operator()(pair<int,int> a,pair<int,int> b) {
        int aa=abs(a.first-a.second);
        int ab=abs(b.first-b.second);

        if (aa!=ab) return aa<ab;
        return a<b;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1) {
        int n,a,b;
        cin>>n>>a>>b;

        if (!n&&!a&&!b) break;

        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
        for (int i=0;i<n;i++) {
            int k,da,db;
            cin>>k>>da>>db;

            for (int j=0;j<k;j++) pq.push({da,db});
        }

        int ans=0;
        while (!pq.empty()) {
            int ca=pq.top().first;
            int cb=pq.top().second;
            pq.pop();

            if (ca<cb&&a) {
                ans+=ca;
                a--;
            }
            else if (ca>=cb&&b) {
                ans+=cb;
                b--;
            }
            else if (ca<cb&&!a) {
                ans+=cb;
                b--;
            }
            else if (ca>=cb&&!b) {
                ans+=ca;
                a--;
            }
        }

        cout<<ans<<"\n";
    }
}
