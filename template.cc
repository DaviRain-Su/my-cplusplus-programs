#include <iostream>
#include <vector>

template<typename  T>
class Test 
{
public:
    Test(T a, T b);
    ~Test() { std::cout << "~Test()" << std::endl; }
    void Print() {
        std::cout << "_a = " << _a << std::endl;
        std::cout << "_b = " << _b << std::endl;
    }
private:
    T _a;
    T _b;
};

template<typename T>
Test<T>::Test(T a, T b)
    : _a(a), _b(b)
{  std::cout << "Test(T a, T b)" << std::endl; }


int main()
{
    float a = 1.0;
    float b = 2.0;
    Test<float> m_test(a, b);
    m_test.Print();
    return 0;
}
