#include <iostream>
#include <vector>
#include <iomanip>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
typedef K::Ray_2 R;

double floor_to_double(const K::FT& x)
{
    double a = floor(to_double(x));
    while (a > x) a -= 1;
    while (a+1 <= x) a += 1;
    return a;
}

void solve(int n,R ray, vector<S>& obs){

    int i;
    bool flag=false;
    P res;
    for(i=0;i<n;i++){
        S seg = obs[i];

        if(!flag){
            if(do_intersect(ray,seg)){
                flag=true;
                auto o =intersection(ray,seg);
                if(const P* op = get<P>(&*o))
                    res=*op;
                else if(const S* os = get<S>(&*o)){
                    if(collinear_are_ordered_along_line(ray.source(),os->target(),os->source()))
                        res=os->target();
                    else
                        res=os->source();
                }
            }
        }else{
            S r(ray.source(),res);
            if(do_intersect(r,seg)){
                auto o =intersection(r,seg);
                if(const P* op = get<P>(&*o))
                    res=*op;
                else if(const S* os = get<S>(&*o)){
                    if(collinear_are_ordered_along_line(ray.source(),os->target(),os->source()))
                        res=os->target();
                    else
                        res=os->source();
                }
            }
        }
    }
    if(flag)
        cout<<fixed<<setprecision(0)<<floor_to_double(res.x())<<" "<<floor_to_double(res.y())<<endl;
    else
        cout<<"no"<<endl;
}

int main(){

    while(true){
        int n;
        cin>>n;
        if(n==0)
            break;

        long x,y,a,b;
        cin>>x>>y>>a>>b;

        P p(x,y), q(a,b);
        R r(p,q);

        int i;
        vector<S> obstacles;
        for(i=0;i<n;i++){
            long r,s,t,u;
            cin>>r>>s>>t>>u;

            P p(r,s), q(t,u);
            S seg(p,q);
            obstacles.push_back(seg);
        }
        random_shuffle(obstacles.begin(),obstacles.end());
        solve(n,r,obstacles);
    }
}