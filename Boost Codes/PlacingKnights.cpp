#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	vector<pair<int,int> > moves(8);
	moves.push_back(make_pair(-1,-2));
	moves.push_back(make_pair(-1,2));
	moves.push_back(make_pair(1,-2));
	moves.push_back(make_pair(1,2));
	moves.push_back(make_pair(-2,-1));
	moves.push_back(make_pair(-2,1));
	moves.push_back(make_pair(2,-1));
	moves.push_back(make_pair(2,1));

	while(t--){
		int n;
		cin>>n;

		vector<vector<int> > board(n,vector<int>(n,-1));

		int i,j,k;
		int ctr=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				int a;
				cin>>a;
				if(a==1){
					board[i][j]=ctr++;
				}
			}
		}

		Graph G(ctr);

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(board[i][j]!=-1){
					for(k=0;k<8;k++){
						int x = i+moves[k].first;
						int y = j+moves[k].second;
						if(x>=0 && x<n && y>=0 && y<n && board[x][y]!=-1){
							add_edge(board[i][j],board[x][y],G);
						}
					}
				}
			}
		}

		vector<Vertex> mate(ctr);
		edmonds_maximum_cardinality_matching(G,&mate[0]);
		int size = matching_size(G,&mate[0]);
		cout<<ctr-size<<endl;
	}
}