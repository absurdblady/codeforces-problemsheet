#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> g(n);
        for(int i=0;i<n;i++) cin>>g[i];
        bool ok=true;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(g[i][j]=='#') c++; else c=0;
                if(c>=3) ok=false;
            }
        }
        for(int j=0;j<n;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(g[i][j]=='#') c++; else c=0;
                if(c>=3) ok=false;
            }
        }
        for(int i=0;i+1<n;i++){
            for(int j=0;j+1<n;j++){
                if(g[i][j]=='#' && g[i][j+1]=='#' &&
                   g[i+1][j]=='#' && g[i+1][j+1]=='#')
                    ok=false;
            }
        }
        int parityA=0,parityB=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='#'){
                    if((i+j)%2) parityA=1;
                    else parityB=1;
                }
            }
        }
        if(parityA&&parityB) ok=false;
        cout<<(ok?"YES\n":"NO\n");
    }
}
