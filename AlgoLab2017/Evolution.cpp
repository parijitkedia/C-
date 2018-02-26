#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> oldests;
string root;

int find(int id,int age){
	int oldest = oldests[id];
	int parent = parents[id];
	int next;

	if(ages[oldest]<age)
		next=oldest;
	else
		next=parent;
	if(next>=0 && ages[next]>age)
		return id;
	if(next<0 && ages[ids[root]]>age)
		return id;
	if(next<0 && ages[ids[root]]<=age)
		return ids[root];
	return oldests[id]=find(next,age);
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n>>q;

		vector<int> ages(n);
		vector<string> names(n);
		map<string,int> ids;

		int i;
		for(i=0;i<n;i++){
			string name;
			int age;
			cin>>name>>age;
			ids[name]=i;
			names[i]=name;
			ages[i]=age;
		}

		parents=vector<int>(n,-1);
		oldests=vector<int>(n,-1);

		for(i=0;i<n-1;i++){
			string child,parent;
			cin>>child>>parent;
			int cid = ids[child];
			int pid = ids[parent];
			parents[cid]=pid;
			oldests[cid]=pid;
		}

		for(i=0;i<n;i++){
			if(parents[i]==-1)
				root=names[i];
		}

		for(i=0;i<q;i++){
			string name;
			int age;
			cin>>name>>age;
			int ans = find(ids[name],age);
			if(ans==-1)
				cout<<root<<" ";
			else
				cout<<names[ans]<<" ";
		}
		cout<<endl;
	}
}

/*
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;

		vector<string> names(n);
		vector<int> age(n);
		vector<int> parents(n,-1);
		map<string,int> mapspec;

		int i;
		for(i=0;i<n;i++){
			string n;
			int a;
			cin>>n>>a;
			names[i]=n;
			age[i]=a;
			mapspec[n]=i;
		}

		for(i=0;i<n-1;i++){
			string s,p;
			cin>>s>>p;
			parents[mapspec[s]]=mapspec[p];
		}

		for(i=0;i<q;i++){
			string s;
			int a;
			cin>>s>>a;

			int s0=mapspec[s];
			int s1=parents[s0];

			while(s1>=0 && age[s1]<=a){
				s0=s1;
				s1=parents[s1];
			}
			cout<<names[s0]<<" ";
		}
		cout<<endl;
	}
}*/