#ifndef VECTOR_NR_COMPLEX_H_INCLUDED
#define VECTOR_NR_COMPLEX_H_INCLUDED
#include <algorithm>
#include "nr_complex.h"
class vector_nr_complex
{
    int dim;
    nr_complex *v;
public:
    ~vector_nr_complex()
    {
        if(dim!=0)
           delete[] v;
    }
    vector_nr_complex()
    {
        v=NULL; dim=0;
    }
    vector_nr_complex(int nr,nr_complex *a)
    {
        dim=nr;
        v=new nr_complex(dim);
        int i;
        for(i=0;i<nr;++i)v[i]=a[i];
    }
    vector_nr_complex(vector_nr_complex &a)
    {
        dim=a.dim;
        v=new nr_complex[a.dim];
        for(int i=0;i<a.dim;++i)v[i]=a.v[i];
    }
    vector_nr_complex &operator=(vector_nr_complex &a)
    {
        if(&a!=this)
       {
           if(dim!=0)delete[]v;
           dim=a.dim;
           v=new nr_complex[a.dim];
           for(int i=0;i<a.dim;++i)v[i]=a.v[i];
       }
        return *this;
    }
    double *module()
    {
        double *m=new double[dim];
        int i;
        for(i=0;i<dim;++i)m[i]=v[i].modul();
        return m;
    }
    void sortare()
    {
        std::sort(v,v+dim);
    }
    nr_complex suma()
    {
        nr_complex s(0,0);
        int i;
        for(i=0;i<dim;++i)s=s+v[i];
        return s;
    }

    friend std::istream &operator>>(std::istream &,vector_nr_complex&);
    friend std::ostream &operator<<(std::ostream &,const vector_nr_complex&);
    nr_complex &operator[](const int poz)
    {
        if(poz>=0&&poz<dim)
           return v[poz];
    }
    bool operator==(vector_nr_complex &a)const
    {
        if(dim!=a.dim)return 0;
        int i;
        for(i=0;i<dim;++i)
            if(a.v[i]!=v[i])return 0;
        return 1;
    }
    bool operator!=(const vector_nr_complex &a)const
    {
        if(dim==a.dim)return 0;
        int i,ok=0;
        for(i=0;i<dim;++i)
        if(a.v[i]==v[i]) ++ok;
        if(ok==dim)return 0;
        return 1;
    }
    bool operator<(const vector_nr_complex &a)const
    {
        int i;
        if(dim<a.dim)return 1;
        if(dim>a.dim)return 0;
        for(i=0;i<dim;++i)if(a.v[i]<v[i])return 0;
        return 1;
    }
    friend nr_complex operator*(const vector_nr_complex &,const vector_nr_complex &);
    vector_nr_complex operator-(const vector_nr_complex &);
};
nr_complex operator*(const vector_nr_complex &a,const vector_nr_complex &b)
{
    nr_complex s;
    int i;
    if(a.dim!=b.dim)return s;
    for(i=0;i<a.dim;++i)
        s=s+a.v[i]*b.v[i];
    return s;
}
std::istream &operator>>(std::istream &in,vector_nr_complex &a)
{
   int i;
   if(a.dim!=0)delete[]a.v;
   in>>a.dim;
   a.v=new nr_complex[a.dim];
   for(i=0;i<a.dim;++i)in>>a.v[i];
   return in;
}
std::ostream &operator<<(std::ostream &out,const vector_nr_complex &a)
{
    int i;
    for(i=0;i<a.dim;++i)out<<a.v[i]<<" ";
    return out;
}
vector_nr_complex vector_nr_complex::operator-(const vector_nr_complex &a)
{
    int i,k=0;
    for(i=0;i<dim;++i)
        if(v[i]!=a.v[i])break;
    vector_nr_complex b;
    b.dim=dim-i;
    if(dim-i<=0)throw(dim);
    b.v=new nr_complex[dim-i];
    while(i<dim)
    {
        b.v[k]=v[i];
        ++k;++i;
    }
    return b;
}
#endif // VECTOR_NR_COMPLEX_H_INCLUDED
