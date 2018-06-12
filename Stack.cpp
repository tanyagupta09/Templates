/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Stack.h"
#include "TestStack.h"
#include <iostream>
#include <string>
#include <memory>
//#include "StringStack.h"

void TMPL::useStack()
{
    Stack<int *> stack(4);
    int * a = new int (4);
    stack.push(a);
    stack.push(new int (10));
    stack.push(new int (12));
    
    Stack<int *> stack1 = stack;
    Stack<int *> stack3(3);
    stack3 = stack1;
    
    TestStack st1test;
    st1test.push("1001");
    std::cout << "About to create string stack\n";
    std::cout.flush();
    Stack<std::string> stringStac;
    std::string ss1 = "ss1";
    stringStac.push("ss1");
    //stringStac.push("ss2");
    //stringStac.push("ss3");
    //stringStac.push("ss4");
    //std::cout << "Stack returned " <<  *(stack3.pop()) << "\n";
    //std::cout << "Stack returned " <<  *(stack3.pop()) << "\n";
    //std::cout << "Stack returned " <<  *(stack3.pop()) << "\n";
    std::cout << "Stack returned " >>  stack3 << "\n";
    std::cout << "Stack returned ********** " <<  st1test.pop() << "\n";
    std::cout << "Stack returned " <<  (stringStac.pop()) << "\n";
    //std::cout << "Stack returned " <<  (stringStac.pop()) << "\n";
    //std::cout << "Stack returned " <<  (stringStac.pop()) << "\n";
    //std::cout << "Stack returned " <<  (stringStac.pop()) << "\n";
    //std::cout << "Stack returned " <<  stringStac << "\n";
}