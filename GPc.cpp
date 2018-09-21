// Lets search numbers that palindromic in the decimal
// and binary base. We call them next.

#include <iostream>
#include <cmath>
using namespace std;

// Function "get_reverse" swap digits for decimal-input number and write it to rev.
int get_reverse(long long k, long long &rev)
{
    while (k)
        {
        rev=rev*10+(k%10);
        k/=10;
        }
}

// Function "get_reverse_bin" swap digits for binary-input number and write it to rev.
int get_reverse_bin(int k[], int rev[], int digits)
{
    int i;
    for (i=0;i<digits;i++)
        {
        rev[i]=k[digits-i-1];
        }
}

// Function "get_bin" create binary view of x-input number
int get_bin(long long x, int b[], int &digits)
{
    int c=0; int p=0;
    // Looking for greatest binary digit
    while(c<=x) {c=pow(2,++p);} 
    digits=p;
    LOOP:
    // Set "1" to the appropriate digit
    // in the binary number b.
    if ( (x>=pow(2,--p)) && (x<pow(2,(p+1))) )
        {
        b[p]=1;
        x-=pow(2,p);
        }
    // Repeat for all digits
    if (x>1) goto LOOP;
    if (x==1) b[0]=1;
}
 
int main()
{

// Declaring variables i-input number, j-reverse decimal(binary) number,
// b-original binary number.
    long long i, j; int b[100]; int br[100];
// Declaring and initialize count of digits for binary numbers.
    int digits=0;
// Declaring and set to "0" sum of double-base palindromic numbers.
    long long sum=0;
// Declaring and set to "0" count of double-base palindromic numbers.
    int z=0;
// Declaring and set higher number for research
    long long N=1000000;
 
    cout<<"Double-base palindromic numbers:"<<endl;
    cout<<""<<endl;

// Part of programm with searching for double-base palindromic numbers.
    for (i=1;i<N;i++)
    {
        // Even number can't be double-base palindromic, because of "0"
        // in the lowest digit, so skeep step.
        if (!(i%2)) continue;
        j=0;
        for (j=0;j<100;j++) {b[j]=0; br[j]=0;}
        j=0;
        get_reverse(i, j);
        // If not palindromic by decimal base - skeep step.
        if (j!=i) continue;
        get_bin(i, b, digits);
        get_reverse_bin(b, br, digits);
        // If not palindromic by binary base - skeep step.
        for (j=0;j<digits;j++) if (br[j]!=b[j]) goto END;
        // Print result.
        cout<<"#"<<++z<<". "<<"Decimal: "<<i<<"; Binary: ";
        for (j=0;j<digits;j++) cout<<b[j];
        cout<<";"<<endl;
        sum+=i;
        END:
        // Erase count of digits for b[i], br[i]
        digits=0;
    }

// Print sum of all double-base palindromic numbers bellow N.
    cout<<""<<endl;
    cout<<"Sum of double-base palindromic numbers bellow "<<N<<" is = "<<sum<<"."<<endl;
}