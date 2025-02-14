class ProductOfNumbers {
    vector<int> stream;
public:
    ProductOfNumbers() {}
    void add(int num) {
        stream.push_back(num);
    }
    int getProduct(int k) {
        int prod = 1, i = stream.size()-1;
        while(k--){
            prod *= stream[i--];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
