/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: rahulgupta
 *
 * Created on May 29, 2018, 8:43 PM
 */

#ifndef STACK_H
#define STACK_H
#include <vector>
#include <cassert>
#include <iostream>

namespace TMPL
{
    void useStack();
    
    template <typename T>
    class Stack
    {
        private:
            std::vector<T> _impl;
        public:
            Stack(const size_t capacity);
            Stack();
            Stack(const Stack& st);
            Stack& operator=(const Stack& st);
            void push(const T&);
            T back() const;
            T pop();
            
            template <typename U>
            friend std::ostream& operator<<(std::ostream& os,  Stack<U> const& st);        
            
            friend std::ostream& operator>>(std::ostream& os,  Stack<T> const& st)
            {
                const T& t = st.back();
                os <<  "FF >> " << *t <<"\n";
                return os;
            }
    };
    template <typename T>
    std::ostream& operator<<(std::ostream& os,  Stack<T> const& st)
    {
        const T& t = st.back();
        os <<  "FF " << t <<"\n";
        return os;
    }
    
    template <typename T>
    Stack<T>::Stack(const Stack<T>& st)
    {
        std::cout << "Called stack copy ctor\n";
        this->_impl = st._impl;
    }
    
    template <typename T>
    T Stack<T>::back() const
    {
        return _impl.back();
    }
    template <typename T>
    Stack<T>& Stack<T>::operator =(const Stack<T>& st)
    {
        std::cout << "Called stack assignment operator\n";
        this->_impl = st._impl;
        return *this;
    }
    
    template <typename T>
    Stack<T>::Stack(const size_t capacity)
    {
        std::cout << "Using Templatized stack with capacity!\n";
        std::cout.flush();
        //_impl.reserve(capacity);
    }
    
    template <typename T>
    Stack<T>::Stack() : Stack(100)
    {
        std::cout << "Called stack default ctor\n";
        std::cout.flush();
    }
    
    template <typename T>
    void Stack<T>::push(const T& x)
    {
        _impl.push_back(x);
    }
    
    template <typename T>
    T Stack<T>::pop()
    {
        assert(!_impl.empty());
        T t = _impl.back();
        _impl.pop_back();
        return t;
    }
};


#endif /* STACK_H */

