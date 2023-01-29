#include<iostream>
#include<stack>
using namespace std;
// function to check if character is operator or not
bool isOperator (char x)
{
switch(x) {
case '+':
case'-':
case'/':
case '*':
return true;
}
return false;
}


// convert prefix to postfix
string preTopost ( string pre_exp)
{
stack<string>s;
// length of expression
int length = pre_exp.size();

//reading from right to left
for (int i= length-1; i>=0; i--)

// check if symbol is operator
if (isOperator (pre_exp[i]))
{
// pop two operands from stack
string op1= s.top();
s.pop();
string op2= s.top();
s.pop();

//concat the operands and operators
string temp = op1 + op2 + pre_exp[i];

//push string temp back to stack
s.push(temp);
}

else
s.push(string (1,pre_exp[i]));
return s.top();
}
int main ()
{

     string pre_exp = "*-A/BC-/AKL";
     cout<<"postfix: "<<preTopost (pre_exp);
     return 0;
}

