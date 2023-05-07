
#ifndef Fraction_H
#define Fraction_H
#include <iostream>


namespace  ariel{
    
    class Fraction
    {
    private:
        int Numerator, Denominator;
    public:
    
        Fraction(int,int);
        Fraction(float);
        Fraction(const Fraction& other);
        Fraction();
        Fraction(Fraction&& other) noexcept;
        ~Fraction();


    Fraction& operator=(const Fraction& other);
    Fraction& operator=(Fraction&& other) noexcept ;

    Fraction operator+(const Fraction& other) ;
    friend Fraction operator+(const float& other,const Fraction& fra) ;

    Fraction operator-(const Fraction& other) ;
    friend Fraction operator-(const float& other,const Fraction& fra) ;


    Fraction operator/(const Fraction &other);
    friend Fraction operator/(const float& other,const Fraction& fra) ;

    friend bool operator==(const Fraction& other,const Fraction& fra) ;
    friend bool operator==(const float& other,const Fraction& fra) ;

    friend bool operator<(const Fraction& other,const Fraction& fra) ;
    friend bool operator<(const float& other,const Fraction& fra) ;

    friend bool operator<=(const Fraction& other,const Fraction& fra) ;
    friend bool operator<=(const float& other,const Fraction& fra) ;

    friend bool operator>(const Fraction& other,const Fraction& fra) ;
    friend bool operator>(const float& other,const Fraction& fra) ;

    friend bool operator>=(const Fraction& other,const Fraction& fra) ;
    friend bool operator>=(const float& other,const Fraction& fra) ;
    
    Fraction operator*(const Fraction& other);
    friend Fraction operator*(const float& other,const Fraction& fra) ;

    Fraction operator++() ;// for ++a
    Fraction operator++(int) ;// for a++

    Fraction operator--() ;// for --a
    Fraction operator--(int) ;// for a--
   
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& ist, Fraction& fraction);

    void setNumerator(int);
    int getNumerator();
    void setDenominator(int);
    int getDenominator();
    void Factorization();
    
   
    };

}
#endif