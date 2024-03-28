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
class Rational
{
private:
	int x; int y;
public:
	friend int gcd(int a, int b);
	Rational(int a, int b) :x(a), y(b) {};
	Rational(Rational &c) :x(c.x), y(c.y) {};
	Rational add(int a, int b)
	{
		int num=x*b+a*y;
		int den = y * b;
		x = num; y = den;
		int divi = gcd(max(x, y), min(x, y));
		x /= divi; y /= divi;
		return *this;
	}
	Rational sub(int a, int b)
	{
		int num = x * b - a * y;
		int den = y * b;
		x = num; y = den;
		int divi = gcd(max(x, y), min(x, y));
		x /= divi; y /= divi;
		return *this;
	}
	Rational mul(int a, int b)
	{
		x *=a; y *=b;
		int divi = gcd(max(x, y), min(x, y));
		x /= divi; y /= divi;
		return *this;
	}

	Rational div(int a, int b)
	{
		x *= b; y *= a;
		int divi = gcd(max(x, y), min(x, y));
		x /= divi; y /= divi;
		return *this;
	}
	void print()
	{
		if (this->y==1) {
			cout << (this->x) << endl;
		}
		else if(this->x*this->y>0)
			cout << abs(this->x) << "/" << abs(this->y) << endl;
		else 
			cout <<- abs(this->x) << "/" << abs(this->y) << endl;
	}
};
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
			rat.add(stod(v[1]), stod(v[2]));
		}
		if (v[0] == "sub") {
			rat.sub(stod(v[1]), stod(v[2]));
		}
		if (v[0] == "mul") {
			rat.mul(stod(v[1]), stod(v[2]));
		}
		if (v[0] == "div") {
			rat.div(stod(v[1]), stod(v[2]));
		}
	}
	rat.print();
	return 0;
}