class RecentCounter {
    vector<int> counter;
public:
    RecentCounter() {}
    int ping(int t) {
        counter.push_back(t);
        int start = t - 3000, count = 0;
        for(int i = counter.size()-1;i >= 0;i--){
            if(counter[i] < start) break;
            count++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
