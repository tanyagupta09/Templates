/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rahulgupta
 *
 * Created on January 15, 2018, 11:48 AM
 */

#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "Stack.h"
#define NO_INLINE __attribute__ ((noinline)) 
class A
{
public:
    int i;
    A(int l) : i(l) 
    { 
        std::cout << "In ctor\n";
    };
    A() : A(0) {};
    bool operator>(const A& a) const
    {
        return i > a.i;
    }
    
    bool operator<(const A& a) const
    {
        return i < a.i;
    }
    virtual void print1(std::ostream& os) const
    {
        os << "Calling A's\n";
        os << i;
    }
    friend std::ostream& operator<<(std::ostream& os, const A& a);
    friend std::ostream& operator<<(std::ostream& os, const A* a);
    A(const A& a)
    {
        std::cout << "copy called\n";
        i = a.i;
    }
    
    A(A&& a)
    {
        std::cout << "move called\n";
        i = a.i;
    }
    
    A& operator=(const A& a)
    {
        std::cout << "assignment copy called\n";
        i = a.i;
        return *this;
    }
    virtual ~A() {}
    //
private:
};

class B : public A 
{
public:
    double y;
public:
    void print1(std::ostream& os) const override
    {
        os << "Calling B's\n";
        os << y;
    }
    B(double i) : A(i) { y = i;}
};
std::ostream& operator<<(std::ostream& os, const A& a)
{
    a.print1(os);
    return os;
}
std::ostream& operator<<(std::ostream& os, const A* a)
{
    a->print1(os);
    return os;
}
template <typename T>
T max1(T a, T b)
{
    std::cout << "In Max1\n";
    return a > b ? a : b;
}
template <typename T1, typename T2>
T2 min(T1& a, T2& b)
{
    std::cout << "In Min\n";
    return a < b ? a : b;
}

void AB()
{
    A b2;
    const A b1;
}
template <typename T1, typename T2>
auto max(T1 t1, T2 t2) -> typename std::decay<decltype(true ? t1 : t2)>::type
{
    //std::cout << "Max template " << typeid(typename std::decay<decltype(true ? t1 : t2)>::type).name() << "\n";
    //std::cout << "Max template  type T1" << typeid(t1).name() << "\n";
    //std::cout << "Max template  type X111 ," << std::is_reference<T1>::value << "\n";
    return t1 < t2 ? t2 : t1;
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type max1(T1 t1, T2 t2)
{
    std::cout << "In Max1 using common type\n";
    return t1 < t2 ? t2 : t1;
}

A m()
{
    return A(2);
}

template <typename T>
T max3(T t1, T t2)
{
    std::cout << "In new max\n";
    t1 = 1; t2 = 1;
    return t1 < t2 ? t2 : t1;
}

template <typename T>
const T& max4(const T& t1, const T& t2)
{
    std::cout << "Max4 template version type is "  << typeid(t1).name() << "\n";
    std::cout << "t1 is " << (int *) t1 << "\n";
    std::cout << "t2 is " << (int *) t2 << "\n";
    std::cout.flush();
    std::cout.flush();
    return strcmp(t1 ,t2) < 0 ? t2 : t1;
}

__attribute__((always_inline)) const char * max4(const char *  t1, const char* t2)
{
    std::cout << "Max4 non templated  version\n";
    //std::cout << "t1 is " << (int *) t1 << "\n";
    //std::cout << "t2 is " << (int *) t2 << "\n";
    //std::cout << "Is swappable "  << is_swapable<T>::value << "\n";
    //std::cout.flush();
    return strcmp(t1, t2) < 0 ? t2 : t1;
}

__attribute__ ((noinline)) int& p1(int& r)
{
    return r;
}

const int * & p( const int *  & r)
{
    //std::cout << *r <<"\n";
    
    return r;
}
template <typename T>
constexpr bool is_lvalue(T&&) {
  return std::is_lvalue_reference<T>{};
}

template <typename T>
const T& max4(const T& t1, const T& t2, const T& t3)
{
    return ::max4(::max4(t1, t2), t3);
    //return strcmp(t1, t2) < 0 ? (strcmp(t2, t3) < 0 ? t3 : t2) : t1;
}

template <typename T1>
 int Fun1(T1 t, T1 t1)
{
    std::cout << "Calling Fun1<T1, T2>()\n";
   return t + t1;  
}

template <>
 int Fun1<int>(int t, int t1)
{
    std::cout << "Calling Fun1<int, int>()\n";
   return t + t1;  
}

 int Fun1(int t, int t1)
{
    std::cout << "Calling Fun1()\n";
   return t + t1;  
}

 void intCheck1(int *& i)
 {
     std::cout << "Int * check returns " << *i << "\n";
 }
 
 template <typename T>
 void intCheck(const T & i)
 {
     std::cout << "Template check returns " << *i << "\n";
 }
int main(int argc, char** argv) {
    A a(2);
    B b(9.3);
    A& x = a;
    B& y = b;
    const int tr = 5;
    const int& trR = tr;
    decltype(trR) x1 = 10;
    
    //x1 = 10;
    std::cout << x1<<"\n";
    std::cout << max1(3.3, 2)<<"\n";
    
//    A m();
    A a1(A); 
    
    std::cout << "Returning from m " << m() << "\n";
    
    auto c =  ::max(x, y);
    B* k = dynamic_cast<B *>(&c);
    std::cout << max1(&b,&a) << "\n";
    
    
    //AB();
    {
        int x, y;
        int& xr = x, &yr = y;
        xr = 8;
        yr = 9;
        std::cout << "Max 3 before " << x << "," << y << "\n";
        std::cout << "Max 3 " << max3<double>(xr, yr) << "\n";
        std::cout << "Max 3 after " << x << "," << y << "\n";
    }
    
    const char * t1 = "Rahul";
    
    const char * t2 = "Rahul1";
    const char * t3 = "Rahuls";
    
    auto x12 = ::max4(t1, t2, t3);
    std::cout << "x12 before is ";std::cout.flush();
    std::cout << x12 << "\n";
    //std::cout << "Max4 " << retI(4, 5);
    
    const int j1 = 4;
    const int &j4 = j1;
    auto j3 = j4;
    j3 = 3;
    std::cout << "j3 is " << j3 << "\n";
    std::cout << "j4 is " << j4 << "\n";
    Fun1<>(3, 4);
    //Fun1<int, int>(3, 4);
    Fun1(4, 4.5);
    Fun1(4.5, 4.5);
    Fun1(4, 'c');
    
    int * ijk = new int(1);
    int abc = 4;
    intCheck1(ijk);
    TMPL::useStack();
}



