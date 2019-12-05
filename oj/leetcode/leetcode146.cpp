#include <unordered_map>
#include <list>
#include <utility>
#include <iostream>
using namespace std;


class LRUCache {
private:
    int cap;
    list<pair<int,int>> l;  // key,value
    unordered_map<int,list<pair<int,int>>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key,value));
        m[key] = l.begin();

        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


void printList(list<int>& l){
    for(auto p=l.begin();p!=l.end();p++){
        std::cout << *p << '\t';
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    list<int> l;

    for(int i=0;i<5;i++){
        l.push_back(i);
    }

    printList(l);

    auto p = (++l.begin());
    std::cout << *p << std::endl;
    l.splice(l.begin(),l,p);
    printList(l);


    return 0;
}