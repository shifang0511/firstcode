// a) 这个HugeInteger类是用来表示大整数的。它使用一个静态常量n来定义一个数组digits的大小，数组中的每个元素都是一个整数，用来存储大整数的每一位。negative变量用来表示这个大整数是否为负数。len变量用来表示这个大整数的长度。

// 类的构造函数将所有的位初始化为0，并将negative设置为false。

// operator==函数用来比较两个HugeInteger对象是否相等。它通过比较两个对象的每一位来实现这个功能。

// input函数用来从输入中读取一个HugeInteger对象。

// b) 这个类的限制主要有两个。首先，它只能表示长度为n的整数，如果需要表示更大的整数，就需要增加n的值。其次，它只能表示整数，不能表示小数。另外，这个类还没有实现所有的算术运算，例如加法、减法、乘法和除法。
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class HugeInteger {
private:
    static const int n = 40;
    int digits[n];
    bool negative;
    int len;

public:
    HugeInteger() {
        memset(digits, 0, sizeof(digits));
        negative = false;
    }
    bool operator==(const HugeInteger& other) const {
        for (int i = 0; i < n; i++) {
            if (digits[i] != other.digits[i]) return false;
        }
        return true;
    }
    void input() {
        string number;
        cout << "Enter a number: ";
        cin >> number;
        len = number.length();
        if (number[0] == '-') {
            negative = true;
            len--;
        }
        for (int i = 0; i < len; i++) {
            digits[n - len + i] = number[i + (negative ? 1 : 0)] - '0';
        }
    }
    void output() {
        if (negative) {
            cout << "-";
        }
        int i = 0;
        while (i < n && digits[i] == 0) {
            i++;
        }
        if (i == n) {
            cout << "0";
        } else {
            while (i < n) {
                cout << digits[i++];
            }
        }
        cout << endl;
    }

    HugeInteger operator+(const HugeInteger& other) const {
        HugeInteger result;
        int carry = 0;

        if (negative == other.negative) {
            for (int i = n - 1; i >= 0; i--) {
                int sum = digits[i] + other.digits[i] + carry;
                result.digits[i] = sum % 10;
                carry = sum / 10;
            }
            result.negative = negative;
        } else {
            HugeInteger abs1 = *this;
            HugeInteger abs2 = other;
            abs1.negative = false;
            abs2.negative = false;

            if (abs1>abs2) {
                result = abs1-abs2;
                result.negative = negative;
            } else {
                result = abs1-abs2;
                result.negative = other.negative;
            }
        }
        return result;
    }
    HugeInteger operator+(int x) const {
        HugeInteger result;
        int carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            if (i == n - 1) {
                sum += x;
            }
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }

        result.negative = negative;
        return result;
    }
    HugeInteger operator-(const HugeInteger& other)  const{
        HugeInteger result;
        int borrow = 0;
        HugeInteger abs1 = *this;
        HugeInteger abs2 = other;
        if (negative != other.negative) {
            abs1.negative = false;
            abs2.negative = false;

            if (abs1>abs2) {
                result = abs1+abs2;
                result.negative = negative;
            } else {
                result = abs2+abs1;
                result.negative = !other.negative;
            }
        } else {
            if (*this>other) {
                for (int i = n - 1; i >= 0; i--) {
                    int diff = digits[i] - other.digits[i] - borrow;
                    if (diff < 0) {
                        diff += 10;
                        borrow = 1;
                    } 
                    else borrow = 0;
                    result.digits[i] = diff;
                }
                result.negative = negative;
            } 
            else if (*this == other) {
                result.negative = false;
            } 
            else {
                result = other-*this;
                result.negative = !negative;
            }
        }
        return result;
    }
    HugeInteger operator*(int x) const {
        HugeInteger result;
        int carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            int product = digits[i] * x + carry;
            result.digits[i] = product % 10;
            carry = product / 10;
        }

        result.negative = negative;
        return result;
    }
    
    HugeInteger operator*(const HugeInteger& other) const {
        HugeInteger result;
        int carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            HugeInteger  product = other*digits[i]*pow(10,n-1-i);
            result=result+product;
            }
        result.negative = negative != other.negative;
        return result;
    }
    HugeInteger operator/(int x) const {
        HugeInteger result;
        int remainder = 0;

        for (int i = 0; i < n; i++) {
            int dividend = remainder * 10 + digits[i];
            result.digits[i] = dividend / x;
            remainder = dividend % x;
        }

        result.negative = negative;
        return result;
    }
    HugeInteger operator/(const HugeInteger& other) const {
        HugeInteger result,quotient;
        HugeInteger dividend = *this;
        HugeInteger divisor = other;
        while(dividend>=divisor){
            dividend=dividend-divisor;
            quotient=quotient+1;
        }
        result = quotient;
        return result;
    }

    bool operator!=(const HugeInteger& other)  {
        return !(*this==other);
    }

    bool operator>(const HugeInteger& other) const {
        if (negative && !other.negative) {
            return false;
        } else if (!negative && other.negative) {
            return true;
        } else if (negative && other.negative) {
            return !(*this<other);
        } else {
            for (int i = 0; i < n; i++) {
                if (digits[i] > other.digits[i]) {
                    return true;
                } else if (digits[i] < other.digits[i]) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator<(const HugeInteger& other) const {
        if (negative && !other.negative) {
            return true;
        } else if (!negative && other.negative) {
            return false;
        } else if (negative && other.negative) {
            return !(*this>other);
        } else {
            for (int i = 0; i < n; i++) {
                if (digits[i] < other.digits[i]) {
                    return true;
                } else if (digits[i] > other.digits[i]) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator>=(const HugeInteger& other)  {
        return (*this>other) || (*this==other);
    }

    bool  operator<=(const HugeInteger& other)  {
        return (*this<other) || (*this==other);
    }

    bool isZero()  {
        for (int i = 0; i < n; i++) {
            if (digits[i] != 0) {
                return false;
            }
        }
        return true;
        }
};
int main(){
    HugeInteger num1, num2, sum;
    num1.input();
    num2.input();
    sum = num1+num2;
    sum.output();
    sum = num1-num2;
    sum.output();
    sum = num1*num2;
    sum.output();
    sum = num1/num2;
    sum.output();
    system("pause");
}