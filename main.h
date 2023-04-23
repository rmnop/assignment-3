#include <string>
#include <stack>
using namespace std;

bool sOperator(char user);

bool operand(char user);

int inStackPrecendence(char user);
int outStackPrecendence(char user);

void infixToPostFix(char user[]);

bool balanced(string b);