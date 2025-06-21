class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> counter;
        for(char ch: tasks) counter[ch]++;

        priority_queue<int> maxHeap;
        for(auto [_, freq]: counter) {
            maxHeap.push(freq);
        }

        //         time, freq
        queue<pair<int, int>> coolingDownTasks;
        int time = 0;

        while(!maxHeap.empty() || !coolingDownTasks.empty()) {
            time++;
            if(!maxHeap.empty()) {
                int currentFreq = maxHeap.top(); maxHeap.pop();
                currentFreq -= 1; // completed now
                if(currentFreq > 0) {
                    coolingDownTasks.push({time + n, currentFreq});
                }
            }
            if(!coolingDownTasks.empty() && coolingDownTasks.front().first == time) {
                maxHeap.push(coolingDownTasks.front().second);
                coolingDownTasks.pop();
            }
        }
        return time;
    }
};
