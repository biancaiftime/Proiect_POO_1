#include <iostream>
#include "vector_nr_complex.h"
using namespace std;
int main()
{
    vector_nr_complex *a;
    int n,i;
    cin>>n;
    a=new vector_nr_complex[n];
    for(i=0;i<n;++i)cin>>a[i];
    /*cout<<"Vectorii cititi sunt:\n";
    for(i=0;i<n;++i)cout<<a[i]<<"\n";
    sort(a,a+n);
    cout<<"Vectorii dupa sortare sunt:\n";
    for(i=0;i<n;++i)cout<<a[i]<<"\n";
    cout<<"Vectorii cu elementele sortate sunt:\n";
    for(i=0;i<n;++i)
    {
        a[i].sortare();
        cout<<a[i]<<"\n";
    }*/
    cout<<a[0]-a[1];
    return 0;
}
