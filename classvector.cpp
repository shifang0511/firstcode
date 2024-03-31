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
    Vector(int size):len(size){
        v=new double[len];
    };
    Vector(double * array, int size):len(size){
        v=new double[len];
        for(int i=0;i<len;i++)v[i]=array[i];
    };
    Vector(Vector &v1):len(v1.len){
        v=new double[len];
        for(int i=0;i<len;i++)v[i]=v1[i];
    };
    ~Vector(){
        delete v;
    };
    double &operator[](int i){return this->v[i];};
    const double &operator[](int i)const{return this->v[i];};
    Vector &operator =(const Vector& v1){
        if(this==&v1)return *this;
        delete []v;
        len=v1.len;
        v=new double[len];
        for(int i=0;i<len;i++)v[i]=v1[i];
        return *this;
    }   
}; 
Vector operator+(Vector& v1, Vector &v2){   
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
    double a[]={1,2,3};
    double b[]={4,5,6};
    Vector v1(a,3),v2(b,3),v3(3);
    cout<<v1<<endl;
    cout<<v2<<endl;
    v3=v1+v2;
    cout<<v3<<endl;
    v3=v1-v2;
    cout<<v3<<endl;
    cout<<v1*v2<<endl;
    return 0;
}