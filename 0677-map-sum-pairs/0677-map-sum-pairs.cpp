class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int res=0;
        for(auto i:mp){
            string k=i.first;
            int f=1;
            for(int j=0;j<prefix.size();j++){
                if(k[j]==prefix[j]) continue;
                else{
                    f=0;
                    break;
                }
            }
            if(f==1) res+=i.second;
            
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */