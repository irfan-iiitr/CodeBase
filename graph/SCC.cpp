#include "bits/stdc++.h"

void topodfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st,bool topo){
	if(vis[node]==1) return;

	vis[node]=1;

	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			topodfs(nbr,adj,vis,st,topo);
		}
	}
     if(topo==true)
	{st.push(node);}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<vector<int>> adj(v);

	for(auto ele:edges){
		int u=ele[0],v=ele[1];
		adj[u].push_back(v);
	}
	stack<int> st;

	vector<int> vis(v,0);

	for(int i=0;i<v;i++){
		if(vis[i]==0){
			topodfs(i,adj,vis,st,true);
		}
	}


	vector<vector<int>> adjR(v);

	for(auto ele:edges){
		int u=ele[0],v=ele[1];
		adjR[v].push_back(u);
	}

	vector<int> visR(v,0);
	int c=0;

	while(!st.empty()){
		int node=st.top(); st.pop();
		if(!visR[node]){
			topodfs(node,adjR,visR,st,false);
			c++;
		}
	}

	return c;





}