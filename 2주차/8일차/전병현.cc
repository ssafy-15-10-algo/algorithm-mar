#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

queue<int> q;


int avail[100000];
vector<pair<int,long long>> e[100000];
long long dist[100000];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> avail[i];
		avail[i] = !avail[i];
	}
	avail[n - 1] = 1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (avail[a] && avail[b]) {
			e[a].push_back({ b, c });
			e[b].push_back({ a, c });
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i] = 9223372036854775807ll;
	}
	priority_queue<pair<long long int, int>> pq;
	pq.push({ 0, 0 });
	while (pq.size()) {
		auto t = pq.top();
		pq.pop();
		int v = t.second;
		long long d = -t.first;
		if (dist[v] <= d) {
			continue;
		}
		dist[v] = d;
		for (auto nv : e[v]) {
			if (dist[nv.first] > d + nv.second) {
				pq.push({ -d - nv.second, nv.first });
			}
		}
	}
	if (dist[n - 1] == 9223372036854775807ll) {
		cout << -1;
	}
	else {
		cout << dist[n - 1];
	}

}
