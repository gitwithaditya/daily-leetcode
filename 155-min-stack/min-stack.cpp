class MinStack {
    stack<long long> st;
    long long mini = LLONG_MAX;

public:
    MinStack() {
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else {
            if(value < mini) {
                st.push(2LL * value - mini);
                mini = value;
            }
            else {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2LL * mini - x;
        }
    }
    
    int top() {
        if(st.top() < mini) {
            return (int)mini;
        }
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};