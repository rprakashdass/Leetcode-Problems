class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> marks;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int num: nums) {
            add(num);
        }
    }
    int add(int val) {
        if(marks.size() < k) {
            marks.push(val);
        } else if (val > marks.top()) {
            marks.pop();
            marks.push(val);
        }
        return marks.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
