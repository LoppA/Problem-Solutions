// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
  stack<int> head, tail;
  
  void flush() {
    if (!head.empty()) {
      return;
    }
    while(!tail.empty()) {
      head.push(tail.top());
      tail.pop();
    }
  }
  
public:
    MyQueue() {}
    
    void push(int x) {
      tail.push(x);
    }
    
    int pop() {
      assert(!empty());
      int val = peek();
      head.pop();
      return val;
    }
    
    int peek() {
      assert(!empty());
      flush();
      return head.top();
    }
    
    bool empty() {
      return head.empty() && tail.empty();
    }
};
