#include <iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int pri(char op){               // to check the priority of operation
    if(op=='+' || op == '-')
        return 1;
    else if(op=='*' || op =='/')
        return 2;
    else if (op=='^')
        return 3;
    else
        return 0;
}

string in_to_per(string exp){
    stack<char> stk;
    string output = "";
    for(int i=0 ; i<exp.length() ;i++)
    {
        if(exp[i] == ' ') continue;  // if user put space
        if(isdigit(exp[i]) || isalpha(exp[i])) // if it's num or alpha print in result
            {output += exp[i];}
        else if(exp[i] == '(')    //if it's ( add to the stack
            {stk.push(exp[i]);}
        else if (exp[i]==')'){ // if it's ) then pop from stack to get (
        while(stk.top() != '('){   // the pop loop
                output += stk.top();
                stk.pop();
              }
              stk.pop();}
        else{
            while(!stk.empty() && pri(exp[i]) <= pri(stk.top())){
                output += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
    }
    while(!stk.empty()){
        output+=stk.top();
        stk.pop();}
    return output;
}

int main()
{
    string Exp_infix ="(3+2)+7/2*((7+3)*2)";
    cout << in_to_per(Exp_infix) << endl;
}
