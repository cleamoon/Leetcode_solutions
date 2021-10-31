class MinStack {
private:
    int* real;
    int* cmin; 
    int pos = 0;
    const int lim = 30001;

public:
    MinStack() {
        real = new int[lim];
        cmin = new int[lim];
        cmin[0] = INT_MAX;
    }
    
    void push(int val) {
        pos++;
        real[pos] = val;
        cmin[pos] = min(val, cmin[pos - 1]);
    }
    
    void pop() {
        pos--;
    }
    
    int top() {
        return real[pos];
    }
    
    int getMin() {
        return cmin[pos];
    }
};
