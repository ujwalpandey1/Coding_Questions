class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        unordered_map<int,vector<pair<int,double>>>mp;   
    vector<double>prob(n,0);
    
    for(int i=0;i<edges.size();i++)
    {
    	int u=edges[i][0];
    	int v=edges[i][1];
    	double w=succ[i];
    	
    	mp[u].push_back(make_pair(v,w));
    	mp[v].push_back(make_pair(u,w));
	}
	
	set<pair<double,int>>st;  
	st.insert(make_pair(1,start));
	prob[start]=1;
	

	while(!st.empty())
	{
       auto it=(st.rbegin());
       auto p=*(it);
        
       double currnode_prob=p.first;
       int currnode=p.second;
        
       st.erase(p);
       
       for(auto x : mp[currnode])  
       {
          if((currnode_prob*x.second)>prob[x.first])
		  {
			 if(st.find(make_pair(prob[x.first],x.first))!=st.end())
			 {
			    st.erase(st.find(make_pair(prob[x.first],x.first)));	
		     }	
		     prob[x.first]=(currnode_prob*x.second);
		     st.insert(make_pair(prob[x.first],x.first));
	      }	  
	   }
	}    
	return prob[end];
    }
};