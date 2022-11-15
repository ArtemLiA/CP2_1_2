#include <iostream>
using namespace std; //Нужно подключить пространство имён std
//Или использовать оператор разрешения области видимости
class Complex
{
public:
    Complex( double _real, double _imaginary = 0 )
            : real( real ), imaginary(_imaginary )
    {
    }
    Complex& operator + (Complex other) /*Оператор сложения
    не должен иметь тип void, он должен возвращать ссылка на новый объект Complex */
    {
        Complex result(0, 0);
        result.real = real + other.real;
        result = imaginary + other.imaginary;
        return result;
    }
    ostream& operator << ( ostream &os ) // оператор << должен возвращать ссылку на поток
    {
        os << "(" << real << "," << imaginary << ")";

        return os;
    }
    Complex& operator ++() //Должен возвращать ссылку
    {
        ++real;
        return *this;
    }
    Complex operator++( int )
    {
        Complex temp = *this;
        ++*this;
        return temp;
    }
private:
    //Не рекомендуется начинать название полей с нижнего подчёркивания.
    double real;
    double imaginary;
};
