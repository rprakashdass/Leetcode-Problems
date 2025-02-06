class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        int k = p.size();
        vector<int> result;
        vector<int> current(26, 0), total(26, 0);
        for(int i = 0;i < p.size();i++) total[p[i]-'a']++;
        int left = 0;
        for(int right = 0;right < s.size();right++){
            current[s[right]-'a']++;
            if(right-left+1 > k){
                current[s[left]-'a']--;
                left++;
            }
            if (right - left + 1 == k && total == current) {
                result.push_back(left);
            }
        }
        return result;
    }
}; 
