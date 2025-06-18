class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> infiniteContainer;
    unordered_set<int> contained;
    int current = 1;
public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if(infiniteContainer.empty()) {
            return current++;
        }
        int smallest = infiniteContainer.top();
        infiniteContainer.pop();
        contained.erase(smallest);
        return smallest;
    }

    void addBack(int num) {
        if(num < current && contained.find(num) == contained.end()) {
            infiniteContainer.push(num);
            contained.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
