class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfiedCustomers = 0;
        for(int i = 0;i < customers.size();i++) {
            if(grumpy[i] == 0) {
                satisfiedCustomers += customers[i];
                customers[i] = 0;
            }
        }
        int maxCustomers = 0, customersCount = 0;
        for(int i = 0;i < customers.size();i++) {
            customersCount += customers[i];
            if(i >= minutes) {
                customersCount -= customers[i - minutes];
            }
            maxCustomers = max(maxCustomers, customersCount);
        }
        return maxCustomers + satisfiedCustomers;
    }
};
