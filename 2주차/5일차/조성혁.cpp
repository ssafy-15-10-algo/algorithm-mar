#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int,int,int> tiii;

char board[1001][1001];
int visited[1001][1001][2];

int main() {
    int n,m;
    cin>>n>>m;
    int sx=0,sy=0;
    int ex=0,ey=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>board[i][j];
            if (board[i][j]=='S') {
                sx=i;
                sy=j;
            }
            else if (board[i][j]=='H') {
                ex=i;
                ey=j;
            }
        }
    }

    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    queue<tiii> q;
    q.push({sx,sy,0});
    visited[sx][sy][0]=1;
    while (!q.empty()) {
        int x,y,flag;
        tie(x,y,flag)=q.front();
        q.pop();
        if (x==ex&&y==ey&&flag) {
            cout<<visited[x][y][flag]-1;
            return 0;
        }

        for (int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if (board[nx][ny]=='D') continue;

            int nxtFlag=flag|board[nx][ny]=='F';
            if (visited[nx][ny][nxtFlag]) continue;

            visited[nx][ny][nxtFlag]=visited[x][y][flag]+1;
            q.push({nx,ny,nxtFlag});
        }
    }

    cout<<-1;
}
