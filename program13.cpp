//Write a C++ program that uses stack operations to convert a given infix expression into its postfix equivalent//
#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
int precedence(char m) 
{ 
  if(m == '^') 
  return 3; 
  else if(m == '*' || m == '/') 
  return 2; 
  else if(m == '+' || m == '-') 
  return 1;
  else if(m=='$')
  return 0; 
} 
void infix_to_postfix(string t) 
{ 
  stack<char> s;
  int l = t.length(); 
  string ans; 
  for(int i = 0; i < l; i++) 
  { 
    if((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z')) 
        ans+=t[i]; 
    else if(t[i] == '(') 
        s.push('('); 
        
    else if(t[i] == ')') 
    { 
      while(s.top() != '(') 
      { 
        char c = s.top(); 
        ans += c;
        s.pop(); 
           
      } 
      if(s.top() == '(') 
      { 
        char c = s.top(); 
        s.pop(); 
      } 
    } 
    else{ 
      while(s.empty()==false && precedence(t[i]) <= precedence(s.top())) 
      { 
        char c = s.top(); 
        ans += c; 
        s.pop(); 
      
      } 
      s.push(t[i]); 
    } 
  } 
  
  while(s.empty() == false) 
  { 
    char c = s.top(); 
    ans += c; 
    s.pop(); 
    
  } 
  
  cout << ans << endl; 
}
int main() 
{ 
    cout<<"\nThe postfix expression is  : ";//it will print postfix conversion  
  string s = "a+b*c"; 
  infix_to_postfix(s); 
  return 0; 
} 