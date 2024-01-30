// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
  enum Operator {
    CONSTANT,
    ADD,
    SUB,
    MUL,
    DIV
  };
   
  static int doOperation(Operator op, int a, int b) {
    if (op == ADD) {
      return a+b;
    } else if (op == SUB) {
      return a-b;
    } else if (op == MUL) {
      return a*b;
    } else if (op == DIV) {
      return a/b;
    }
    assert(false);
    return 0;
  }
  
  stack<pair<Operator, int>> s;
  void addConstant(int a) {
    if (s.empty() || s.top().first != CONSTANT) {
      s.emplace(CONSTANT, a);
      return;
    }
    
    int b = s.top().second;
    s.pop();
    Operator o = s.top().first;
    s.pop();
    
    addConstant(doOperation(o, a, b));
  }
  
public:
    int evalRPN(vector<string>& tokens) {
      map<string, Operator> op = {
        {"+", ADD},
        {"-", SUB},
        {"*", MUL},
        {"/", DIV}
      };

      for (auto it = tokens.rbegin(); it != tokens.rend(); it++) {
        string token = *it;
        if (op.contains(token)) {
          s.emplace(op[token], 0);
        } else {
          int a = stoi(token);
          addConstant(a);
        }
      }
      
      assert(s.size() == 1);
      return s.top().second;
    }
};
