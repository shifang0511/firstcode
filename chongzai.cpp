#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int gcd(int a, int b)
{
    while (a % b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}
class Rational {
private:
    int a, b;
public:
    Rational(int a, int b) :a(a), b(b) {};
    friend ostream& operator<<(ostream& os, const Rational& r);
    friend Rational operator*(const Rational& lop, const Rational& rop);
    friend Rational operator/(const Rational& lop, const Rational& rop);
    friend int gcd(int a, int b);

    Rational operator+(const Rational& rop) {
        int numerator = a * rop.b + b * rop.a;
        int denominator = b * rop.b;
        int divi = gcd(max(numerator, denominator), min(numerator, denominator));
        return Rational(numerator / divi, denominator / divi);
    }

    Rational operator-(const Rational& rop) {
        int numerator = a * rop.b - b * rop.a;
        int denominator = b * rop.b;
        int divi = gcd(max(numerator, denominator), min(numerator, denominator));
        return Rational(numerator / divi, denominator /divi);
};
};


Rational operator*(const Rational& lop, const Rational& rop) {
    int numerator = lop.a * rop.a;
    int denominator = lop.b * rop.b;
    int divi = gcd(max(numerator, denominator), min(numerator, denominator));
    return Rational(numerator / divi, denominator /divi);
}

Rational operator/(const Rational& lop, const Rational& rop) {
    int numerator = lop.a * rop.b;
    int denominator = lop.b * rop.a;
    int divi = gcd(max(numerator, denominator), min(numerator, denominator));
    return Rational(numerator / divi, denominator /divi);
}

ostream& operator<<(ostream& os, const Rational& r) {
    if (r.b==1) {
			cout << (r.a) << endl;
		}
		else if(r.a*r.b>0)
			cout << abs(r.a) << "/" << abs(r.b) << endl;
		else 
			cout <<- abs(r.a) << "/" << abs(r.b) << endl;
    return os;
}

vector<string> split(const string& str, const string& pattern)
{
    vector<string> res;
    if (str == "")
        return res;
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }
    return res;
}

int main()
{
    string command;
    double a, b;
    cin >> command;
    vector<string> v = split(command, ",");
    Rational rat(stod(v[0]), stod(v[1]));
    while (cin >> command)
    {
        vector<string> v = split(command, ",");
        if (v[0] == "add") {
            rat=rat+Rational(stod(v[1]), stod(v[2]));
        }
        if (v[0] == "sub") {
           rat=rat-Rational(stod(v[1]), stod(v[2]));
        }
        if (v[0] == "mul") {
            rat=rat*Rational(stod(v[1]), stod(v[2]));
        }
        if (v[0] == "div") {
            rat=rat/Rational(stod(v[1]), stod(v[2]));
        }
    }
    cout<<rat<<endl;
    system("pause");
    return 0;
    
}