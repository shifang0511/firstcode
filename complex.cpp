#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class Complex
{
private:
	double real; double imag;
public:
	Complex(double a, double b) :real(a), imag(b) {};
    Complex(Complex &c):real(c.real),imag(c.imag){};
    friend istream& operator>>(istream& is, Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);
	Complex operator +(const Complex &cp)
	{
		return Complex(real+cp.real, imag+cp.imag);
	}
	Complex operator -(const Complex &cp)
	{
		return Complex(real-cp.real, imag-cp.imag);
	}
	Complex operator *(Complex cp)
	{
		double c = cp.real * real - cp.imag * imag;
		double d = real * cp.imag + imag * cp.real;
		return Complex(c, d);
	}

	Complex operator /(Complex cp)
	{
		double c = (cp.real * real + cp.imag * imag)/(cp.real*cp.real+cp.imag*cp.imag);
		double d = ( imag * cp.real - real * cp.imag) / (cp.real * cp.real + cp.imag * cp.imag);
		return Complex(c, d);
	}
    Complex &operator=(const Complex &c){
        real=c.real;
        imag=c.imag;
        return *this;
    }

};
istream& operator>>(istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return os;
}
int main()
{
    Complex c1(2.5, 3.7);
    Complex c2(1.8, -2.4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << c3 << endl;
    cout << "c1 - c2: " << c4 << endl;
    cout << "c1 * c2: " << c5 << endl;
    cout << "c1 / c2: " << c6 << endl;
	return 0;
}