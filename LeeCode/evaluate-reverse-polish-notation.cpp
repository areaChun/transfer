/*From leetcode && 牛客网

时间限制：1秒 空间限制：32768K 热度指数：56501

题目描述

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

/*

栈的思路其实是挺简单，但对原string处理比较麻烦。
备注一下string的比较方法，
特别是用stringstream方法将数字字符串string转为int的技巧。

*/
#include <stack>
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty())
            return 0;
        std::stack<int> number;
        for(int i =0 ;i<tokens.size();i++){
            
            if(tokens[i]=="*"||tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"){
                int b = number.top();number.pop();
                int a = number.top();number.pop();
                if(tokens[i]=="*")
                    number.push(a*b);
                if(tokens[i]=="/")
                    number.push(a/b);
                if(tokens[i]=="+")
                    number.push(a+b);
                if(tokens[i]=="-")
                    number.push(a-b);
            }else{
                stringstream ss;
                ss<<tokens[i];
                int temp;
                ss>>temp;
                number.push(temp);
            }
               

        }
        return number.top();
    }
};