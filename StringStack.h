/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringStack.h
 * Author: rahulgupta
 *
 * Created on June 9, 2018, 1:32 PM
 */

#ifndef STRINGSTACK_H
#define STRINGSTACK_H


#include <cstring>
#include <array>
#include <cassert>

namespace TMPL
{
    template <>
    class Stack<std::string>
    {
        private:
            std::array<std::string, 100> _arrayImpl;
            int _size;
        public:
            Stack();
            void push(std::string t);
            std::string back();
            std::string pop();
        
        friend std::ostream& operator<<(std::ostream& os,  Stack<std::string> const& st);        
    };
    
 };

#endif /* STRINGSTACK_H */

