#include "source.h"
#include <iostream>
#include <stdexcept>


namespace my_lub
{

    int Rational::gcd(int x, int y) 
    {
        while (x > 0 && y > 0) 
        {
            if (x > y) 
            {
                x %= y;
            }
            else 
            {
                y %= x;
            }
        }
        return x + y;
    }
    
    void Rational::normalize() 
    {
        int NOD = gcd(numerator, denominator);
        numerator = numerator / NOD;
        denominator = denominator / NOD;
        isNormalized = true;
    }

    Rational::Rational() 
    {
        numerator = 0;
        denominator = 1;
    }

    Rational::Rational(int n, int d)
    {
        if (d == 0) 
        {
            throw std::runtime_error("Warning, denominator = 0");
        }
        numerator = n;
        denominator = d;
        isNormalized = false;
        normalize();
    }

    Rational::Rational(int n)
    {
        numerator = n;
        denominator = 1;
    }

    int Rational::getNumerator() const
    {
        return numerator;
    }

    void Rational::setNumerator(int n)
    {
        numerator = n;
        isNormalized = false;
    }

    int Rational::getDenominator() const
    {
        return denominator;
    }

    void Rational::setDenominator(int d)
    {
        if(d == 0)
        {
            throw std::runtime_error("Warning, denominator = 0");
        }
        denominator = d;
        isNormalized = false;
    }

    void Rational::print()
    {
        if (numerator == 0 || denominator == 1) 
        {
            std::cout << numerator << std::endl;
        }
        
        if (numerator > denominator) 
        {
            int natural = numerator / denominator;
            numerator -= natural * denominator;
            std::cout << natural << " " << numerator << "/" << denominator << std::endl;
        }
        
        else 
        {
            std::cout << numerator << "/" << denominator << std::endl;
        }
    }

    Rational Rational::operator+=(Rational& right_number)
    {
        if (right_number.getDenominator() != denominator)
        {
            numerator = (numerator * right_number.getDenominator() + denominator * right_number.getNumerator());
            denominator = (denominator * right_number.getDenominator());
        }

        else
        {
            numerator = (numerator * right_number.getNumerator());
        }

        if (isNormalized == false)
        {
            normalize();
        }
        return *this;
    }

    Rational Rational::operator*=(Rational& right_number)
    {
        numerator = (numerator * right_number.getNumerator());
        denominator = (denominator * right_number.getDenominator());

        if (isNormalized == false)
        {
            normalize();
        }
        return *this;
    }

    Rational Rational::operator+(const Rational& right_number) const
    {
        Rational result;
        result.setNumerator(numerator * right_number.getDenominator() + denominator * right_number.getNumerator());
        result.setDenominator(denominator * right_number.getDenominator());
        return result;
    }

    Rational Rational::operator*(const Rational& right_number) const
    {
        Rational result;
        result.setNumerator(numerator * right_number.getNumerator());
        result.setDenominator(denominator * right_number.getDenominator());
        return result;
    }

    Rational Rational::operator-()
    {
        this -> setNumerator(-this->getNumerator());
        
        if (isNormalized == false) 
        {
            normalize();
        }
        return *this;
    }

    bool Rational::operator==(const Rational& right_number) const
    {
        return numerator * right_number.getDenominator() == denominator * right_number.getNumerator();
    }

    bool Rational::operator>(Rational& right_number)
    {
        return numerator * right_number.getDenominator() > denominator * right_number.getNumerator();
    }

    Rational& Rational::operator++ ()
    {
        int num = getNumerator();
        int dem = getDenominator();
        setNumerator(num + dem);
        return *this;
    }

    Rational Rational::operator++ (int)
    {
        Rational temp = *this;
        int num = getNumerator();
        int dem = getDenominator();
        setNumerator(num + dem);
        return temp;
    }
}