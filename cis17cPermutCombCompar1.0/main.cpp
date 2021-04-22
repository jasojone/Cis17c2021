/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on April 21, 2021, 9:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float permWithReplace(int, int);    //Permutation with replacement
float perm(int, int);               //Permutation with out replacement
float combWithReplace(int, int);    //Combination with replacement  
float comb(int, int);               //combination without replacement
float factorial(int);               //Converts the 


int main(int argc, char** argv) 
{
    cout<<"P -> Permutation(Order Matters)" <<endl;
    cout<<"C -> Combination(Order does not matter)" <<endl;
    cout<<"Rep -> with replacement" <<endl;
    cout<<"no Rep -> no replacement" <<endl;
    cout<<"N -> Number of total elements" <<endl;
    cout<<"M -> Number of elements to take from the total" <<endl<<endl;
    
    
    cout<<"  N   M \tP Rep\t\t P no Rep \t       C Rep        \t  C no Rep"<<endl;
    cout<<"        \tN^M  \t\t N!/(N-M)!\t(N+M-1)!/((N-1)!M!) \t N!/((N-M)!M!)" <<endl<<endl;
    
    
    for (int n = 2; n<27; n++)
    {
        for (int m = 0; m<n+1; m++)
        {
            printf ("%3d", n);
            printf ("%4d", m);
            printf ("%14G", permWithReplace(n,m));
            printf ("%20G", perm(n,m));
            printf ("%25G", combWithReplace(n,m));
            printf ("%20G", comb(n,m));
            printf ("\n");
        }
       printf ("\n");
    }
            
            

    return 0;
}

float factorial(int n)
{
    float ret = 0.0f;
    
    for (int i = 1; i<n+1; i++)
    {
        ret+=log2f(i);
    }
    return ret;
}

float permWithReplace(int n, int m)
{
    return pow(n,m);
}

float perm(int n, int m)
{
    return pow(2,(factorial(n)-factorial(n-m)));
}

float combWithReplace(int n, int m)
{
    return pow(2, (factorial(n+m-1)-factorial(n-1)-factorial(m)));
}

float comb(int n, int m)
{
    return pow(2, ((factorial(n)-factorial(n-m)-factorial(m))));
}
