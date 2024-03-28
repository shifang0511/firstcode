#include <iostream>

using namespace std;
class Vector
{
private:
    double *v;
    int len;

public:
    friend Vector operator+(Vector &, Vector &);
    friend Vector operator-(Vector &, Vector &);
    friend double operator*(Vector &, Vector &);
    friend ostream &operator<<(ostream &output, Vector &);
    friend istream &operator>>(istream &input, Vector &);
    Vector(int size):len(size){};
    Vector(double * array, int size):v(array),len(size){};
    ~Vector(){
        delete []v;
    };
    double &operator[](int i){return this->v[i];};
    Vector &operator=(Vector &);   
};
Vector operator+(Vector & v1, Vector &v2){   
    double a[v1.len];
    for(int i=0;i<v1.len;i++)a[i]=v1[i]+v2[i];
    Vector v3(a,v2.len);
    return v3;
}
Vector operator-(Vector & v1, Vector &v2){   
    double a[v1.len];
    for(int i=0;i<v1.len;i++)a[i]=v1[i]-v2[i];
    Vector v3(a,v2.len);
    return v3;
}
double operator*(Vector & v1, Vector &v2){   
    double ans=0;
    for(int i=0;i<v1.len;i++)ans+=v1[i]*v2[i];
    return ans;
}
ostream &operator <<(ostream &output,Vector &v)
{
    for(int i=0;i<v.len;i++)output<<v[i]<<" ";
    return output;
}

istream &operator >>(istream &input,Vector &v)
{
    for(int i=0;i<v.len;i++)input>>v[i];
    return input;
}
int main()
{
}