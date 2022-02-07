class LRUCache {
private:
    int capacity;
    list<int> li;
    unordered_map<int, int> key_val;
    unordered_map<int, list<int>::iterator> key_ite;
    void use(int key) {
        if (key_ite.find(key) != key_ite.end()) {
            li.erase(key_ite[key]);
        } else if (li.size() >= capacity) {
            int old_key = li.back();
            li.pop_back();
            key_val.erase(old_key);
            key_ite.erase(old_key);
        }
        li.push_front(key);
        key_ite[key] = li.begin();
    }
public:
    LRUCache(int capacity): capacity(capacity) {}
    int get(int key) {
        if (key_val.find(key) != key_val.end()) {
            use(key);
            return key_val[key];
        }
        return -1;
    }
    void put(int key, int value) {
        use(key);
        key_val[key] = value;
    }
};
// class LRUCache {
// public:
//     vector<int> key_val;
//     vector<list<int> :: iterator> key_ite;
//     list<int> li;
//     list<int> :: iterator temp = li.end();
//     int capacity;
//     LRUCache(int capacity) {
//         for(int i = 0; i <= 10001; i++){
//             key_val.push_back(-1);
//             key_ite.push_back(li.end());
//         }
//         this->capacity = capacity;
//     }
    
//     int get(int key) {
//         if(li.size()< capacity){
//             if(key_ite[key] != temp){
//                 li.erase(key_ite[key]);
//             }
//         }
//         else{
//             if(key_ite[key] == temp){
//                 // key_val[li.front()] = -1;
//                 li.erase(li.begin());
//             }
//             else{
//                 li.erase(key_ite[key]);
//             }
//         }
//         li.push_back(key);
//         key_ite[key] = --li.end();
//         return key_val[key];
//     }
    
//     void put(int key, int value) {
//         if(li.size()< capacity){
//             if(key_ite[key] != temp){
//                 li.erase(key_ite[key]);
//             }
//         }
//         else{
//             if(key_ite[key] == temp){
//                 key_val[li.front()] = -1;
//                 li.erase(li.begin());
//             }
//             else{
//                 li.erase(key_ite[key]);
//             }
//         }
//         li.push_back(key);
//         key_ite[key] = --li.end();
//         key_val[key] = value;
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */