/*!
    @file
    @brief Файл с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
    @brief Конструктор класса
    @param aRe Действительная состаляющая
    @param aIm Мнимая состаляющая
*/
Complex :: Complex(double aRe, double aIm)
{
   Re = aRe;
   Im = aIm;
}

/*!
    @brief Конструктор класса
    @param aRval Комплексное число
*/
Complex ::  Complex(const Complex & aRval)
{
   Re = aRval.Re;
   Im = aRval.Im;
}

/*!
    @brief Диструктор класса
*/
Complex :: ~Complex()
{
   Re = 0.0;
   Im = 0.0;
}

void Complex :: Set(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Возвращает модоль комплексного числа
    @return Модуль комплексного числа
*/
Complex :: operator double()
{
    return abs();
}

/*!
    @brief Расчёт модуля комплексного числа
    @return Модуль комплексного числа
*/
double Complex :: abs()
{
    return sqrt(Re * Re + Im * Im);
}

/*!
    @brief Сложение комплексных чисел
    @return Результат сложения
*/
Complex Complex ::  operator + (const Complex & aRval)
{
  Complex Result;
  Result.Re = Re + aRval.Re;
  Result.Im = Im + aRval.Im;
  return Result;
}

/*!
    @brief Вычитание комплексных чисел
    @return Результат вычитания
*/
Complex Complex :: operator - (const Complex & aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im =  Im - aRval.Im;
    return Result;
}

/*!
    @brief Сложение комплексного и действительного числа
    @return Результат сложения
*/
Complex Complex :: operator + (const double & aRval)
{
   Complex Result;
   Result.Re = Re + aRval;
   Result.Im = Im;
   return Result;
}

/*!
    @brief Вычитание действительного из комплексного числа
    @return Результат вычитания
*/
Complex Complex :: operator - (const  double & aRval)
{
    Complex Result (*this);
    Result.Re = Re - aRval;
    return Result;
}

/*!
    @brief Произведение комплексных чисел
    @return Результат произведения
*/
Complex Complex :: operator * (const Complex & aRval)
{
   Complex Result;
   Result.Re = Re * aRval.Re - Im * aRval.Im;
   Result.Im = Re * aRval.Im + Im*aRval.Re;
   return Result;
}

/*!
    @brief Произведение комплексного и действительного числа
    @return Результат произведения
*/
Complex Complex :: operator * (const double & aRval)
{
   Complex Result;
   Result.Re = Re * aRval;
   Result.Im = Im * aRval;
   return Result;
}

/*!
    @brief Деление комплексных чисел
    @return Результат деления
*/
Complex Complex :: operator / (const double & aRval)
{
   Complex Result;
   Result.Re = Re / aRval;
   Result.Im = Im / aRval;
   return Result;
}

/*!
    @brief Сложение значения первого операнта - комплексного чисела со значением второго операнта - комплексного чисела; сохранение результата в объект, указанный первым операндом.
    @return Результат сложения
*/
Complex & Complex :: operator += (const Complex & aRval)
{
  Re += aRval.Re;
  Im += aRval.Im;
  return *this;
}

/*!
    @brief Вычитание значения второго операнта - комплексного чисела из значение первого операнта - комплексного чисела; сохранение результата в объект, указанный первым операндом.
    @return Результат вычитания
*/
Complex & Complex :: operator -= (const Complex & aRval)
{
   Re -= aRval.Re;
   Im -= aRval.Im;
   return *this;
}

/*!
    @brief Умножение значения первого операнта - комплексного чисела на значение второго операнта - комплексного чисела; сохранение результата в объект, указанный первым операндом.
    @return Результат произведения
*/
Complex & Complex :: operator *= (const Complex & aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/*!
    @brief Сложение значения первого операнта - комплексного чисела со значением второго операнта - действительного числа; сохранение результата в объект, указанный первым операндом.
    @return Результат сложения
*/
Complex & Complex :: operator += (const double & aRval)
{
    Re += aRval;
    return *this;
}

/*!
    @brief Вычитание значения второго операнта - действительного числа из значение первого операнта - комплексного чисела; сохранение результата в объект, указанный первым операндом.
    @return Результат вычитание
*/
Complex & Complex :: operator -= (const double & aRval)
{
  Re -= aRval;
  return *this;
}

/*!
    @brief Умножение значения первого операнта - комплексного чисела на значение второго операнта - действительного числа; сохранение результата в объект, указанный первым операндом.
    @return Результат произведения
*/
Complex & Complex   ::operator  *=  ( const  double & aRval)
{
   Re *= aRval;
   Im *= aRval;
   return *this;
}

/*!
    @brief Деление значения первого операнта - комплексного чисела на значение второго операнта - действительного числа; сохранение результата в объект, указанный первым операндом.
    @return Результат деления
*/
Complex & Complex :: operator /= (const double & aRval)
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/*!
    @brief Присвоение значения второго операнта - комплексного числа первому операнту - комплексному чиселу
    @return Результат присвоения
*/
Complex & Complex :: operator = (const Complex & aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/*!
    @brief Присвоение значения второго операнта - действительного числа первому операнту - комплексному чиселу
    @return Результат присвоения
*/
Complex & Complex :: operator = (const double & aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/*!
    @brief Извлекает комплексное число из входного потока.
    @return Результат
*/
istream & operator >>(istream & stream, Complex & aRval)
{
  char tmp[256];
  stream >> aRval.Re >> aRval.Im >> tmp;
  return stream;
}

/*!
    @brief вставляет указанное комплексное число в выходной поток.
    @return Результат
*/
ostream & operator << (ostream & stream, Complex & aRval)
{
    stream << aRval.Re;
    if ( !(aRval.Im < 0) ) stream << '+';
    stream << aRval.Im << 'i';
    return stream;
}

/*!
    @brief Сложение действительного и комплексного числа
    @return Результат
*/
Complex operator + (const double & aLval, const Complex & aRval)
{
   Complex Result;
   Result.Re = aLval + aRval.Re;
   Result. Im = aRval.Im;
   return Result;
}

/*!
    @brief Вычитание комплексного из действительного числа
*/
Complex operator -(const double &aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}

/*!
    @brief Произведение действительного и комплексного числа
*/
Complex operator * (const double & aLval, const Complex & aRval)
{
   Complex Result;
   Result.Re = aLval * aRval.Re;
   Result.Im = aLval * aRval.Im;
   return Result;
}
