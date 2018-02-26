#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor> > > > Graph;
 // Interior Property Maps
typedef property_map<Graph, edge_capacity_t>::type EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

struct EdgeAdder {
    EdgeAdder(Graph & G, EdgeCapacityMap &capacity, ReverseEdgeMap &rev_edge)
    : G(G), capacity(capacity), rev_edge(rev_edge) {}
    void addEdge(int u, int v, long c) {
        Edge e, reverseE; bool success;
        tie(e, success) = add_edge(u, v, G);
        tie(reverseE, success) = add_edge(v, u, G);
        capacity[e] = c;
        capacity[reverseE] = 0;
        rev_edge[e] = reverseE;
        rev_edge[reverseE] = e;
    }
    Graph &G;
    EdgeCapacityMap &capacity;
    ReverseEdgeMap  &rev_edge;
};

struct lnk{
    int from;
    int to;
};

int solve(int n,int m,int s,int d,vector<lnk>& ls, vector<int> ss, vector<int> ds){

    Graph G(2*n);
    EdgeCapacityMap capacity = get(edge_capacity, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);    
    EdgeAdder ea(G,capacity,revedgemap);

    Vertex source = add_vertex(G);
    Vertex target = add_vertex(G);

    int i;
    for(i=0;i<n;i++){
        ea.addEdge(i,i+n,1);
    }

    for(i=0;i<m;i++){
        lnk& l = ls[i];
        ea.addEdge(l.from+n,l.to,1);
    }

    for(i=0;i<s;i++){
        ea.addEdge(source,ss[i],1);
    }

    for(i=0;i<d;i++){
        ea.addEdge(ds[i]+n,target,1);
    }

    int flow = push_relabel_max_flow(G,source,target);
    return flow;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,s,d;
        cin>>n>>m>>s>>d;

        int i;
        vector<lnk> ls(m);
        for(i=0;i<m;i++){
            cin>>ls[i].from;
            cin>>ls[i].to;
        }

        vector<int> ss(s);
        for(i=0;i<s;i++){
            cin>>ss[i];
        }

        vector<int> ds(d);
        for(i=0;i<d;i++){
            cin>>ds[i];
        }

        cout<<solve(n,m,s,d,ls,ss,ds)<<endl;
    }
}