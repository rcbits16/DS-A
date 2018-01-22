/*
*   Starts at the smallest prime number(2), and marks all it's multiples.(upto NUM)
*   Then marks all multiples of the next un-marked number.
*   --> At the end only prime numbers are left un-marked.
*   --> (I have marked all numbers with it's first visitor(smallest prime factor)).
*   --> Although we can easily identify prime numbers from the original array,
*   --> as these are the only one's still marked with (1), I have stored them separately in a vector.
*/
//Adding something here..
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

ulli NUM = 9973;

int main(void)
{

    ulli max_prime_factor=1;

    //This will store all the prime number's found
    vector<ulli> primes;

    //Initialize all numbers as prime.
    ulli nums[NUM];
    for(ulli i =0;i<NUM;i++)
        {
            nums[i] = 1;
        }
    //Fill the array with the numbers' smallest prime factors.
    for(ulli i=2;i<NUM;i++)
    {
        //If it's still unmarked:
        if(nums[i]==1)
        {
            //It's a prime
            primes.push_back(i);
            //Mark all it's multiples
            for(ulli j =i;j<NUM;j+=i)
            {
                nums[j] = i;
            }
        }
    }

    int sz = primes.size();

    for(int i=0;i<sz;i++)
    {
        cout << primes[i] <<" ";
        //Update largest prime factor of NUM
        if( NUM%(primes[i])==0 )  max_prime_factor = primes[i];
    }
    //If there are no factors, it's a prime number itself.
    if (max_prime_factor==1) max_prime_factor = NUM;

    cout << "\n" << max_prime_factor<<" is the answer\n";
}
