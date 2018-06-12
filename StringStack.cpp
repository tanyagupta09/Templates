/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Stack.h"
#include "StringStack.h"

namespace TMPL
{
    Stack<std::string>::Stack() : _size(0) 
    {
        std::cout << "Using specialized string stackkkkkkk!\n";
        std::cout.flush();
    }
    
    void Stack<std::string>::push(std::string t)
    {
        assert(_arrayImpl.size() == _arrayImpl.max_size());
        assert(_size < _arrayImpl.max_size());
        _arrayImpl[_size++] = t;
    }
    
    std::string Stack<std::string>::back()
    {
        return _arrayImpl.back();
    }
    
    std::string Stack<std::string>::pop()
    { 
        return _arrayImpl.at(--_size);
    }
}