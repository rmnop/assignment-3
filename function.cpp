#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

using namespace std;


bool sOperator(char user) {
    return (user == '+' || user == '-' || user == '*' || user == '/' || user == '%');
}

bool operand(char user) {
    return(user >= '0' && user <= '9');
}

int inStackPrecedence(char user) {
    if (user == '+' || user == '-') {
        return 2;
 } else if (user == '*' || user == '/' || user == '%') {
        return 4;
 } else {
        return 0;
    }
}

int outStackPrecendence(char user) {
    if (user == '+' || user == '-')
        return 1;
    else if (user == '*' || user == '/' || user == '%')
        return 3;
    else
        return 100;
}


void infixToPostFix(char user[]) {
    stack<char> s;
    //string postFix = " "; //leave postfix empty
    int i = 0;
    while(user[i] != '\0') {
        if(operand(user[i])) {
            printf("%c", user[i]);
        } else if(sOperator(user[i])) {
            if(s.empty() || outStackPrecendence(user[i]) > inStackPrecendence(s.top()))
                s.push(user[i]);
         else {
            while(!s.empty() && outStackPrecendence(user[i]) < inStackPrecendence(s.top())) {
                printf("%c", s.top());
                s.pop();
            }
            s.push(user[i]);
         }

    } else if(user[i] == ')') {
        while(s.top() != '(') {
            printf("%c", s.top());
            s.pop();

                if(s.empty()) {
                    printf("Invalid expression");
                }
            }
            s.pop();
        }
        i++;
    }

    while(!s.empty()) {
        if(s.top() == '(') {
            printf("\n Invalid input");
        }
        printf("%c", s.top());
        s.pop();
    }
}


bool balanced(string b) {
    stack<char> temp;
    for(int i = 0; i < b.length(); i++) {
        if(temp.empty()) {
            temp.push(b[i]); //this function will check if the stack is balanced if it is empty

        }
        else if((temp.top() == '(' && b[i] == ')') ||
        (temp.top() == '{' && b[i] == '}') || (temp.top() == '[' && b[i] == ']')) {
            temp.pop(); //checks out balanced, pops stack
        }
        else {
            temp.push(b[i]); //pushes function if passses
        }
    }
    if(temp.empty()) {
        return true;
    }
    return false;
}
