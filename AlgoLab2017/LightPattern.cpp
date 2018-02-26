include <iostream>
   #include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        
        vector<int> lights(n);
        vector<int> pattern(k);
        vector<pair<int,int> > ans;
        int i,j;
        for(i=0;i<n;i++){
            cin>>lights[i];
        }
        
        for(i=0;i<k;i++){
            pattern[i]=0;
        }
        
        for(i=k-1;i>=0;i--){
            pattern[i]=x&1;
            x=x>>1;
        }
        
        
        for(i=0;i<n;i+=k){
            int wrong=0;
            for(j=0;j<k;j++){
                if(pattern[j]!=lights[i+j]){
                    wrong++;
                }
            }
            ans.push_back(make_pair(wrong,k-wrong));
        }
        bool switched = false;
        bool dontcare = false;
        int res=0;
        for(i=n/k-1;i>=0;i--){
            int add=1;
            if(dontcare){
                add=0;
            }
            if(switched){
                if(ans[i].first + add < ans[i].second){
                    res+=ans[i].first+add;
                    switched=false;
                    if(dontcare){
                        dontcare=false;
                    }
                }else{
                    res+=ans[i].second;
                    if(ans[i].second == ans[i].first+add){
                        dontcare=true;
                    }else{
                        dontcare=false;
                    }
                }
            }else{
                if(ans[i].second+add < ans[i].first){
                    res+=ans[i].second+add;
                    switched=true;
                    if(dontcare)
                        dontcare=false;
                }else{
                    res+=ans[i].first;
                    if(ans[i].second + add == ans[i].first)
                        dontcare=true;
                    else
                        dontcare=false;
                }
            }
        }
        cout<<res<<endl;
    }
}