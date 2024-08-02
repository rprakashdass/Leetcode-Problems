class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int p = 0, ip = 1, fib = 0;
        for(int i = 2;i <= n;i++){
            fib = p + ip;
            p = ip;
            ip = fib;
        }
        return fib;
    }
};
