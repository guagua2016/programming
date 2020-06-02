/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> nums;
    vector<int>::iterator cur;

    vector<int> helper(vector<NestedInteger> &nestedList){
        vector<int> ret;
        for(auto it = nestedList.begin();it!=nestedList.end();it++){
            if((*it).isInteger()){
                ret.push_back(it->getInteger());
            }else{
                vector<int> t = helper(it->getList());
                ret.insert(ret.end(),t.begin(),t.end());
            }
        }
        return ret;
    }


    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto it = nestedList.begin();it!=nestedList.end();it++){
            if((*it).isInteger()){
                nums.push_back(it->getInteger());
            }else{
                vector<int> t = helper(it->getList());
                nums.insert(nums.end(),t.begin(),t.end());
            }
        }
        cur = nums.begin();
    }

    int next() {
        return *cur++;
        
    }

    bool hasNext() {
        return cur != nums.end();
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */