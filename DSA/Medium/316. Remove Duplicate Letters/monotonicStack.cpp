class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastSeen(26, 0);
        for(int i = 0;i < s.size();i++) lastSeen[s[i] - 'a'] = i;

        vector<bool> visited(26, false);
        stack<char> stq;

        for (int i = 0;i < s.size();i++) {
            if (visited[s[i] - 'a']) continue; // if visited, skip it to avoid multiple occurence
            // pop out the largest char, which will occur later
            while (!stq.empty() && s[i] < stq.top() && i < lastSeen[stq.top() - 'a']) {
                visited[stq.top() - 'a'] = false;
                stq.pop();
            }
            visited[s[i] - 'a'] = true;
            stq.push(s[i]);
        }

        string result;
        while(!stq.empty()) {
            result = stq.top() + result;
            stq.pop();
        }

        return result;
    }
};
