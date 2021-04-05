#include <bits/stdc++.h>

using namespace std;
bool balanced(string expr){ 
  stack<char> a;
  char b;
  for (int n = 0; n < expr.length(); n++){
    if (expr[n] == '(' || expr[n] == '[' || expr[n] == '{'){
      a.push(expr[n]);
      continue;
    }
    if (a.empty())
    return false;
    switch (expr[n]) {
      case ')':
      b = a.top();
      a.pop();
      if (b == '{' || b == '[')
      return false;
      break;
      case '}':
      b = a.top();
      a.pop();
      if (b == '(' || b == '[')
      return false;
      break;
      case ']':
      b = a.top();
      a.pop();
      if (b == '(' || b == '{')
      return false;
      break;
    }
  }
  return (a.empty());
}
int main(){
  string expr = "{{{}}}[[]]()[[]]{{{}}}";
  if (balanced(expr))
  cout << "This is a balanced parantheses.";
  else
  cout << "This is not a balanced parantheses.";
  return 0;
}