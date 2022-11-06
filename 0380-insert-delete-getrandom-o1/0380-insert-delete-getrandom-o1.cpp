class RandomizedSet {
public:
    unordered_set<int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp.insert(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
       int idx = rand()%mp.size();
    auto it = mp.begin();
    for (int i = 0; i < idx; i++)
    {
    it++;
    }
    return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */