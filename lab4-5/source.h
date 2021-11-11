namespace my_lub 
{
	class Rational 
	{	
		private:
		int numerator;
		int denominator;

		int gcd(int x, int y);
		void normalize();

		bool isNormalized;

		public:
		Rational();
		Rational(int n, int d);
		Rational(int n);

		int getNumerator() const;
		void setNumerator(int n);
		int getDenominator() const;
		void setDenominator(int d);

		void print();
		
		Rational operator+=(Rational& rv);
		Rational operator*=(Rational& rv);

		Rational operator+(const Rational& rv) const;
		Rational operator*(const Rational& rv) const;
		Rational operator-();

		bool operator==(const Rational& rv) const;
		bool operator>(Rational& rv);

		Rational& operator++ ();
		Rational operator++ (int);
	};
}

