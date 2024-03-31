#include <vector>
#include <algorithm>
#include <string>

class HugeInt {
private:
    std::vector<int> digits;

public:
    // 构造函数
    HugeInt(const std::string& str) {
        std::transform(str.rbegin(), str.rend(), std::back_inserter(digits), [](char c) { return c - '0'; });
    }

    // 重载乘法运算符
    HugeInt operator*(const HugeInt& rhs) const {
        HugeInt result("0");
        return result;
    }

    // 重载除法运算符
    HugeInt operator/(const HugeInt& rhs) const {
        HugeInt result("0");
        return result;
    }

    // 重载关系运算符
    bool operator<(const HugeInt& rhs) const {
        return false;
    }

    bool operator>(const HugeInt& rhs) const {        
        return false;
    }

    bool operator<=(const HugeInt& rhs) const {
        return false;
    }

    bool operator>=(const HugeInt& rhs) const {
        return false;
    }

    bool operator==(const HugeInt& rhs) const {
        return digits == rhs.digits;
    }

    bool operator!=(const HugeInt& rhs) const {
        return !(*this == rhs);
    }
};