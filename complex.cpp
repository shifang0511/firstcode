#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class Complex
{
private:
	double x; double y;
public:
	Complex(double a, double b) :x(a), y(b) {};
	Complex add(double a, double b)
	{
		x += a;
		y += b;
		return *this;
	}
	Complex sub(double a, double b)
	{
		x -= a;
		y -= b;
		return *this;
	}
	Complex mul(double a, double b)
	{
		double c = a * x - b * y;
		double d = x * b + y * a;
		x = c; y = d;
		return *this;
	}

	Complex div(double a, double b)
	{
		double real = (a * x + b * y)/(a*a+b*b);
		double img = ( y * a - x * b) / (a * a + b * b);
		x = real; y = img;
		return *this;
	}
	void print()
	{
		cout <<fixed<<setprecision(2)<< "(" << this->x << "," << this->y << ")" << endl;
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
	vector<string> v = split(command,",");
	Complex com(stod(v[0]), stod(v[1]));
	while (cin >> command)
	{
		vector<string> v = split(command, ",");
		if (v[0] == "add") { 
			com.add(stod(v[1]), stod(v[2])); 
		}
		if (v[0] == "sub") {
			com.sub(stod(v[1]), stod(v[2]));
		}
		if (v[0] == "mul") {
			com.mul(stod(v[1]), stod(v[2]));
		}
		if (v[0] == "div") {
			com.div(stod(v[1]), stod(v[2]));
		}
	}
	com.print();
	return 0;
}