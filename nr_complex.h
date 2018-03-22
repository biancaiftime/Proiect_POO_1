#ifndef NR_COMPLEX_H_INCLUDED
#define NR_COMPLEX_H_INCLUDED
#include<cmath>
class vector_nr_complex;
class nr_complex
{
    double Re,Im;
public:
    nr_complex(double x=0,double y=0)
    { Re=x; Im=y;}
    nr_complex(nr_complex &a)
    { Re=a.Re; Im=a.Im; }
    double modul()const
    {
        return sqrt(Re*Re+Im*Im);
    }
    friend std::istream &operator>>(std::istream &,nr_complex &);
    friend std::ostream &operator<<(std::ostream &,const nr_complex &);
    nr_complex &operator=(const nr_complex &c)
    {
        Re=c.Re; Im=c.Im;
        return *this;
    }
    friend nr_complex operator+(const nr_complex &,const nr_complex &);
    friend nr_complex operator-(const nr_complex &,const nr_complex &);
    friend nr_complex operator*(const nr_complex &,const nr_complex &);
    friend nr_complex operator/(const nr_complex &,const nr_complex &);
    bool operator==(const nr_complex &c)const
    {
        return (Re-c.Re==0)&&(Im-c.Im==0);
    }
    bool operator!=(const nr_complex &c)const
    {
        return (Re-c.Re!=0)||(Im-c.Im!=0);
    }
    bool operator<(const nr_complex &c)const
    {
        if(this->modul()<c.modul())return 1;
        return 0;
    }
    friend class vector_nr_complex;
};
std::istream & operator>>(std::istream &in,nr_complex &c)
{
    in>>c.Re>>c.Im;
    return in;
}
std::ostream & operator<<(std::ostream &out,const nr_complex &c)
{
    out<<c.Re<<"+"<<c.Im<<"i";
    return out;
}
nr_complex operator+(const nr_complex &a,const nr_complex &b)
{
    nr_complex c;
    c.Re=a.Re+b.Re;
    c.Im=a.Im+b.Im;
    return c;
}
nr_complex operator-(const nr_complex &a,const nr_complex &b)
{
    nr_complex c;
    c.Re=a.Re-b.Re;
    c.Im=a.Im-b.Im;
    return c;
}
nr_complex operator*(const nr_complex &a,const nr_complex &b)
{
    nr_complex c;
    c.Re=a.Re*b.Re-b.Im*a.Im;
    c.Im=a.Re*b.Im+a.Im*b.Re;
    return c;
}
nr_complex operator/(const nr_complex &a,const nr_complex &b)
{
   nr_complex c;
   double numitor;
   numitor=b.Re*b.Re+b.Im*b.Im;
    if(numitor==0) throw numitor;
    c.Re=a.Re*b.Re+b.Im*a.Im;
    c.Im=a.Im*b.Re-a.Re*b.Im;
    c.Re/=numitor;
    c.Im/=numitor;
   return c;
}
#endif // NR_COMPLEX_H_INCLUDED
