class StockSpanner {
private:
    vector<int> stockPrice;
public:
    StockSpanner() {}
    
    int next(int price) {
        int cnt = 0;
        stockPrice.push_back(price);
        for(int i  = stockPrice.size()-1;i >= 0;i--){
            if(stockPrice[i] <= price){
                cnt++;
            } else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
