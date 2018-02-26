#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        int n,m; 
        cin>>n>>m; 
        
        int r,b; 
        cin >> r >> b; 

        vector<vector<int> > graph(n, vector<int>()); 
        
        int i;
        for (i=0;i<m;i++) {
            int u,v; 
            cin>>u>>v; 
            graph[u].push_back(v); 
        }

        vector<int> mini(n+1,50001);
        vector<int> maxi(n+1,-1);

        mini[n] = 0;
        maxi[n] = 0;

        for (i=n-1;i>=1;i--) {
            for (int v:graph[i]) {
                mini[i]=min(mini[i], maxi[v] + 1); 
                maxi[i]=max(maxi[i], mini[v] + 1); 
            }
        }

        int sher = mini[r]; 
        int mor = mini[b]; 

        if (sher<mor || sher%2==1) 
            cout<<0<<endl;
        else 
            cout<<1<<endl;
    }
}