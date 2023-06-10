class MyHashSet {
public:
       int  s[1000001] ={0};
    MyHashSet() {
    }
    
    void add(int key) {
        s[key]=1;
        
    }
    
    void remove(int key) {
        s[key]=0;
        
    }
    
    bool contains(int key) {
        return s[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
