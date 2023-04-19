#include <iostream>
#include <iomanip>
#include <string>
#include "infixToPostfix.h"
using namespace std;

int main(){


infixToPostfix obj;
obj.getInfix();
obj.showInfix();
obj.convertToPostfix();
obj.showPostfix();
return 0;


}