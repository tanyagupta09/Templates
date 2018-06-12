/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestStack.h
 * Author: rahulgupta
 *
 * Created on June 10, 2018, 8:41 PM
 */

#ifndef TESTSTACK_H
#define TESTSTACK_H

#include <vector>
class TestStack
{
private:
    std::vector<std::string> _vec;
public:
    TestStack() : TestStack(10) {}
    TestStack(int n) { _vec.reserve(n);}
    
    void push(const std::string& i) {_vec.push_back(i);}
    std::string pop() {return _vec.back();}
};

#endif /* TESTSTACK_H */

