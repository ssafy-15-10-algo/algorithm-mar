#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int g;
    cin>>g;

    bool flag=false;
    int start=(int)sqrt(g)==sqrt(g)?sqrt(g)-1:sqrt(g);
    for (int k=start;k>=1;k--) {
        if (g%k==0&&(g/k-k)%2==0) {
            cout<<(g/k-k)/2+k<<"\n";
            flag=true;
        }
    }

    if (!flag) cout<<-1;
}
