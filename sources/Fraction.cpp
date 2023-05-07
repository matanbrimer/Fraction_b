#include "Fraction.hpp"
#include <iostream>
#include <limits>
#include <tuple>
#include <algorithm>
using namespace  std;
using namespace  ariel;

int max_int = std::numeric_limits<int>::max();
int min_int = std::numeric_limits<int>::min();
Fraction::Fraction(int num1, int num2):Numerator(num1),Denominator(num2)
{
    if((num1 > max_int || num1 < min_int) || (num2 > max_int || num2 < min_int)){
        throw std::overflow_error("ERROR: overflow_error");
    }

    if(num2 == 0){
        throw std::invalid_argument("ERROR: It is impossible to divide by zero");
    }
    if(num2 < 0){
        Numerator *= -1;
        Denominator *= -1;
    }

    Factorization();
}

Fraction ::Fraction (){
    this->Numerator =0;
    this->Denominator =1;
}

Fraction :: Fraction (float other){
       if(other > 0 || other < 0){
        other = other *1000;
        int num1 = (int)other;       

        int num2 = 1000;
        this->Numerator =num1;
        this->Denominator=num2;
        Factorization();
       }else{
        this->Numerator = 0;
        this->Denominator = 1;
       }
 
}

Fraction :: Fraction (const Fraction& copy):Numerator(copy.Numerator),Denominator(copy.Denominator){
    Factorization();
}

// Move constructor
Fraction::Fraction(Fraction&& other) noexcept: 
        Numerator(std::move(other.Numerator)), Denominator(std::move(other.Denominator)) {
}

Fraction::~Fraction()
{
}

// Copy assignment operator
Fraction& Fraction:: operator=(const Fraction& other) {
if (this != &other) {
    Numerator = other.Numerator;
    Denominator = other.Denominator;
}
return *this;
}
// Move assignment operator
Fraction& Fraction:: operator=(Fraction&& other) noexcept {
if (this != &other) {
    Numerator = other.Numerator;
    Denominator = other.Denominator;
}
return *this;
}


Fraction Fraction:: operator+(const Fraction& other)  {
       long long int num1, num2;
        if (Denominator != other.Denominator) {
            num1 = (static_cast<long long int>(Numerator) * other.Denominator) + (static_cast<long long int>(other.Numerator) * Denominator);
            num2 = static_cast<long long int>(Denominator) * other.Denominator;
        } else {
            num1 = static_cast<long long int>(Numerator) + static_cast<long long int>(other.Numerator);
            num2 = static_cast<long long int>(Denominator);
        }
        if (num1 > max_int || num1 < min_int || num2 > max_int || num2 < min_int) {
            throw std::overflow_error("ERROR: overflow_error");
        }
        Fraction temp(num1, num2);
       
        return temp;
}

Fraction ariel::operator+(const float& other,const Fraction& fra) 
{
    if(other == 0){
       return fra;
    }   
    int res1,res2;
    float other2 = other*1000;
    int num1 = (int)other2;        
    int num2 = 1000;
    if(fra.Denominator != num2){
        res1 =  (fra.Numerator * num2) + (num1 * fra.Denominator);
        res2 = fra.Denominator * num2 ;
        
    }
    else{
        res1 =  fra.Numerator  + num1 ;
        res2 = fra.Denominator; 
    }
    Fraction temp2(res1,res2);
    return temp2;
    
        
}

Fraction Fraction::operator-(const Fraction& other) {
    long long int num1, num2;
    if (Denominator != other.Denominator) {
        num1 = (static_cast<long long int>(Numerator) * other.Denominator) - (static_cast<long long int>(other.Numerator) * Denominator);
        num2 = static_cast<long long int>(Denominator) * other.Denominator;
    } else {
        num1 = static_cast<long long int>(Numerator) - static_cast<long long int>(other.Numerator);
        num2 = static_cast<long long int>(Denominator);
    }
    if (num1 > max_int || num1 < min_int || num2 > max_int || num2 < min_int) {
        throw std::overflow_error("ERROR: overflow_error");
    }
    Fraction temp(num1, num2);
    return temp;
}


Fraction ariel::operator-(const float& other,const Fraction& fra) {
    int res1,res2;
    if(other != 0){
        float other2 = other * 1000;
        int num1 = (int)other2;       
        int num2 = 1000;      
        Fraction fra2(num1,num2);
        if(fra.Denominator != fra2.Denominator){

            res1 = (fra2.Numerator * fra.Denominator) - (fra.Numerator * fra2.Denominator);
            res2 = fra.Denominator * fra2.Denominator ;
        }
        else{
            res1 =  fra2.Numerator  - fra.Numerator ;
            res2 = fra.Denominator;
            
        }
        Fraction temp2(res1,res2);
       
        return temp2;
    }
    else{
        
       
        Fraction temp2(0 - fra.Numerator,fra.Denominator);
        
        return temp2;
    }
        
}

Fraction Fraction:: operator*(const Fraction& other){    
    long int num1 = Numerator;
    num1 *=  other.Numerator;
    long int num2 = Denominator;
    num2 *= other.Denominator;
   
    if(num1 > max_int || num1 < min_int){
        throw std::overflow_error("ERROR: overflow_error");
    }
    else if(num2 > max_int || num2 < min_int){
        throw std::overflow_error("ERROR: overflow_error");
    }

    Fraction temp(num1,num2);
        
    return temp;
}


Fraction ariel:: operator*(const float& other,const Fraction& fra){
  
        int res1,res2;
        float other2 = other *1000;
        int num1 = (int)other2;       
        int num2 = 1000;
        res1 = fra.Numerator * num1;
        res2 = fra.Denominator * num2;
        Fraction temp2(res1,res2);
        return temp2;
}

Fraction Fraction:: operator/(const Fraction& other){


    if(other.Numerator != 0){
        long int num1 = Numerator ;
         num1 *=  other.Denominator;

        long int num2 = Denominator ;
        num2 *= other.Numerator;       
        if(num1 > max_int || num1 < min_int){
            throw std::overflow_error("ERROR: overflow_error");
        }
        else if(num2 > max_int || num2 < min_int){
            throw std::overflow_error("ERROR: overflow_error");
        }

        Fraction temp(num1,num2);

        return temp;
    }
    else{
        throw  std::runtime_error("ERROR: Cannot be divided by zero");
    }
 


}

Fraction ariel:: operator/(const float& other,const Fraction& fra){
    int res1,res2;
    if(other > 0 || other < 0){
        float other2 = other * 1000;
        int num1 = (int)other2;       
        int num2 = 1000;
        Fraction result(num1,num2);
        res1 = fra.Denominator * result.Numerator;
        res2 = fra.Numerator * result.Denominator;
        
        result.setNumerator(res1);
        result.setDenominator(res2);
        result.Factorization();
        return result;

    }
    else{
       Fraction result(0,1);
       return result;
    }
}


std::istream& ariel::operator>>(std::istream& input, Fraction& fra){
    char temp ;
    if(input >> fra.Numerator>> fra.Denominator){
        if(fra.Denominator > 0 ){
            
            return input;
        }
        else if(fra.Denominator < 0){
            fra.Denominator *= -1;
            fra.Numerator *= -1;
            return input;
        }
    }
    throw std::runtime_error("Invalid fraction format");
    
}


std::ostream &ariel::operator<<(std::ostream &output, const Fraction &fraction)
{
    output << fraction.Numerator << "/" << fraction.Denominator;
    return output;
}

Fraction Fraction:: operator++()
{   
    Numerator += Denominator;
    Factorization();
    return *this;

}

Fraction Fraction:: operator++(int num)
{
    Fraction temp(*this);
    Numerator += Denominator;
    Factorization();
    return temp;

}

Fraction Fraction:: operator--() {
    Numerator -= Denominator;
    Factorization();
    return *this;
}

Fraction Fraction:: operator--(int){
    Fraction temp(*this);
    Numerator -= Denominator;
    Factorization();
    return temp;
}
    
bool ariel:: operator==(const Fraction& other,const Fraction& fra) {

    if(fra.Numerator == other.Numerator && fra.Denominator == other.Denominator){
        return true;
    }
    else if(fra.Numerator == 0 && other.Numerator == 0){
        return true;
    }
    return false;
}

bool ariel:: operator==(const float& other,const Fraction& fra) {
    float other2 = other * 1000;
    int num1 = (int)other2;       
    int num2 = 1000;
    Fraction check(num1,num2);
    if(fra.Numerator == check.Numerator && fra.Denominator == check.Denominator){
        return true;
    }
    return false;


}

bool ariel:: operator<(const Fraction& other,const Fraction& fra) {
    
  float flo = (float)fra.Numerator/fra.Denominator;
  float flo2 = (float) other.Numerator/other.Denominator;
  if(flo2 < flo)return true;

  return false;

}

bool ariel:: operator<(const float& other,const Fraction& fra){
    float flo = (float)fra.Numerator/fra.Denominator;

    if(other < flo)return true;

    return false;

}

bool ariel:: operator<=(const Fraction& other,const Fraction& fra) {
    float flo = (float)fra.Numerator/fra.Denominator;
    float flo2 = (float) other.Numerator/other.Denominator;
    if(flo2 <= flo)return true;

    return false;
}
bool ariel:: operator<=(const float& other,const Fraction& fra){
    float flo = (float)fra.Numerator/fra.Denominator;
    if(other <= flo)return true;

    return false;

}

bool ariel:: operator>(const Fraction& other,const Fraction& fra) {

    if(( other.Numerator * fra.Denominator ) > (fra.Numerator * other.Denominator ))return true;

    return false;
}

bool ariel:: operator>(const float& other,const Fraction& fra) {
    float flo = (float)fra.Numerator/fra.Denominator;
   
    if(other > flo)return true;

    return false;
}

bool ariel:: operator>=(const Fraction& other,const Fraction& fra) {
    float flo = (float)fra.Numerator/fra.Denominator;
    float flo2 = (float) other.Numerator/other.Denominator;
    if(flo2 >= flo)return true;

    return false;
}
bool ariel:: operator>=(const float& other,const Fraction& fra){
    float flo = (float)fra.Numerator/fra.Denominator;
    if(other >= flo)return true;

    return false;
}



void Fraction:: Factorization(){

    int divide = __gcd(Numerator,Denominator);
    Numerator = Numerator / abs(divide); 
    Denominator = Denominator / abs(divide);

}

void Fraction:: setNumerator(int num){
    Numerator = num;
}

int Fraction:: getNumerator(){
    return Numerator;
}

void Fraction:: setDenominator(int num){
    if(num == 0){
        Denominator = 1;
    }else{
        Denominator = num;
    }
    
}

int Fraction:: getDenominator(){
    return Denominator;
}





