namespace my_lib
{
	template <typename T>
	class Rational
	{	
		private:		

		T numerator;
		T denominator;

		T gcd(T x, T y);
		void normalize();

		bool isNormalized;

		public:

		Rational();
		Rational(T n, T d);
		Rational(T n);

		T getNumerator() const;
		void setNumerator(T n);
		T getDenominator() const;
		void setDenominator(T d);

		void print();
		
		Rational<T> operator+=(Rational<T>& rv);
		Rational<T> operator*=(Rational<T>& rv);

		Rational<T> operator+(const Rational<T>& rv) const;
		Rational<T> operator*(const Rational<T>& rv) const;
		Rational<T> operator-();

		bool operator==(const Rational<T>& rv) const;
		bool operator>(Rational<T>& rv);

		Rational<T>& operator++ ();
		Rational<T> operator++ (int);
	};

    template <typename T>
    T Rational<T>::gcd(T x, T y)
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

    template <typename T>
    void Rational<T>::normalize()
    {
        T NOD = gcd(numerator, denominator);
        numerator = numerator / NOD;
        denominator = denominator / NOD;
        isNormalized = true;
    }

    template <typename T>
    Rational<T>::Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    template <typename T>
    Rational<T>::Rational(T n, T d)
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

    template <typename T>
    Rational<T>::Rational(T n)
    {
        numerator = n;
        denominator = 1;
    }

    template <typename T>
    T Rational<T>::getNumerator() const
    {
        return numerator;
    }

    template <typename T>
    void Rational<T>::setNumerator(T n)
    {
        numerator = n;
        isNormalized = false;
    }

    template <typename T>
    T Rational<T>::getDenominator() const
    {
        return denominator;
    }

    template <typename T>
    void Rational<T>::setDenominator(T d)
    {
        if (d == 0)
        {
            throw std::runtime_error("Warning, denominator = 0");
        }
        denominator = d;
        isNormalized = false;
    }

    template <typename T>
    void Rational<T>::print()
    {
        if (numerator == 0 || denominator == 1)
        {
            std::cout << numerator << std::endl;
        }

        if (numerator > denominator)
        {
            T natural = numerator / denominator;
            numerator -= natural * denominator;
            std::cout << natural << " " << numerator << "/" << denominator << std::endl;
        }

        else
        {
            std::cout << numerator << "/" << denominator << std::endl;
        }
    }

    template <typename T>
    Rational<T> Rational<T>::operator+=(Rational& right_number)
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

    template <typename T>
    Rational<T> Rational<T>::operator*=(Rational& right_number)
    {
        numerator = (numerator * right_number.getNumerator());
        denominator = (denominator * right_number.getDenominator());

        if (isNormalized == false)
        {
            normalize();
        }
        return *this;
    }

    template <typename T>
    Rational<T> Rational<T>::operator+(const Rational& right_number) const
    {
        Rational result;
        result.setNumerator(numerator * right_number.getDenominator() + denominator * right_number.getNumerator());
        result.setDenominator(denominator * right_number.getDenominator());
        return result;
    }

    template <typename T>
    Rational<T> Rational<T>::operator*(const Rational& right_number) const
    {
        Rational result;
        result.setNumerator(numerator * right_number.getNumerator());
        result.setDenominator(denominator * right_number.getDenominator());
        return result;
    }

    template <typename T>
    Rational<T> Rational<T>::operator-()
    {
        this->setNumerator(-this->getNumerator());

        if (isNormalized == false)
        {
            normalize();
        }
        return *this;
    }

    template <typename T>
    bool Rational<T>::operator==(const Rational& right_number) const
    {
        return numerator * right_number.getDenominator() == denominator * right_number.getNumerator();
    }

    template <typename T>
    bool Rational<T>::operator>(Rational& right_number)
    {
        return numerator * right_number.getDenominator() > denominator * right_number.getNumerator();
    }

    template <typename T>
    Rational<T>& Rational<T>::operator++ ()
    {
        T num = getNumerator();
        T dem = getDenominator();
        setNumerator(num + dem);
        return *this;
    }

    template <typename T>
    Rational<T> Rational<T>::operator++ (int)
    {
        Rational temp = *this;
        T num = getNumerator();
        T dem = getDenominator();
        setNumerator(num + dem);
        return temp;
    }
}

