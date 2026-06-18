#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> stack;
public:
    MinStack() {
    }

    void push(int val) {
        stack.push(val);
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.top();}

    int getMin() {
        std::stack<int> tmp;
        int mini = stack.top();

        while (!stack.empty()) {
            mini = std::min(mini, stack.top());
            tmp.push(stack.top());
            stack.pop();
        }

        while (!tmp.empty()) {
            stack.push(tmp.top());
            tmp.pop();
        }

        return mini;
    }
};