#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> hash_map;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums = vector<int>();
        hash_map = unordered_map<int,int>(); 
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_map.count(val) == 1){
            return false;
        }
        nums.push_back(val);
        hash_map[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash_map.count(val) == 0){
            return false;
        }

        int pos = hash_map[val];
        hash_map[nums[nums.size()-1]] = pos; 
        nums[pos] = nums[nums.size()-1];
        nums.pop_back();
        hash_map.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main(int argc, char const *argv[])
{
    RandomizedSet* obj = new RandomizedSet();
    int val = 10;
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
    
    return 0;
}