#ifndef _STACK_HPP
#define _STACK_HPP
#include <iostream>

template <typename Type>
class stack
{
public:
    stack();
    ~stack();
};
template<typename Type>
stack<Type>::stack(){
    std::cout << "stack()" << std::endl;
}

template<typename Type>
stack<Type>::~stack(){
    std::cout << "~stack()" << std::endl;
}
#endif
