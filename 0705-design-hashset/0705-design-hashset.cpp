class MyHashSet {
public:
    vector<bool>myset;
    MyHashSet() {
        myset.resize(1e6+1,false);
    }
    
    void add(int key) {
        myset[key]=true;
    }
    
    void remove(int key) {
        myset[key]=false;
    }
    
    bool contains(int key) {
        return myset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */