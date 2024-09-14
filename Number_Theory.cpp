#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

//fixed mod
int fixMod(int a, int b)
{
    return ((a%b)+b)%b;
}

//find divisors
vector<int> getDivisors(int n)      // O(sqrt(n))
{
    vector<int> ret;
    int i = 1;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    if (i * i == n)
    {
        ret.push_back(i);
    }
    return ret;
}

//find multiples
vector<int> getMultiples(int n, int m)      // O(m/x)
{
    vector<int> ans;
    for(int i=1; i*n<=m; i++){
        ans.push_back(n*i);
    }
    return ans;
}

//check for prime with divisors
bool isPrime(int n)     // O(sqrt(n))
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

//sieve
vector<bool> primes;
int N = 10e6 + 6;

void sieve()        // O(nloglogn)
{
    fill(primes.begin(), primes.begin() + N, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i < N; i++)
    {
        if (primes[i])
        {
            for (int m = 2 * i; m < N; m += i)
            {
                primes[m] = false;
            }
        }
    }
}

//Prime Factors
vector<pair<int, int> > getPrimeFactors(int n)   // O(sqrt(n))
{
    vector<pair<int, int> > ret;
    for (int p = 2; p * p <= n; p++)
    {
        int e = 0;
        while (n % p == 0)
        {
            n /= p;
            e++;
        }
        if (e > 0)
        {
            ret.push_back({ p, e });
        }
    }
    if (n > 1)
    {
        ret.push_back({ n, 1 });
    }
    return ret;
}


//GCD for multiple numbers
//normal GCD time complexity is O(logn)

int gcdArr(vector<int> arr)         // O(nlogn)
{
    int ans = arr[0];
    for(int e:arr)
    {
        ans = __gcd(ans,e);
        if(ans==1) return 1;  //means we don't need to cont.
    }
    return ans;
}

//LCM from GCD
int __lcm(int a,int b)          // O(logn)
{
    return a*b/__gcd(a,b);
}

//LCM for multiple numbers
int lcmArr(vector<int> arr)     // O(nlogn)
{
    int ans = arr[0];
    for(int e:arr)
    {
        ans = __lcm(ans,e);
        if(ans==1) return 1;  //means we don't need to cont.
    }
    return ans;
}

void printVector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
  }
}


int main()
{
    int i=5;
    double d=2.5;
    cout<<(i+d)<<endl;          //7.5
    cout<<(int)(i+d)<<endl;     //7
    cout<<ceil(i+d)<<endl;      //8
    cout<<floor(i+d)<<endl;     //7

    cout<<5/2<<endl;            //2
    cout<<11/3<<endl;           //3
    cout<<100000/45<<endl;      //2222

    cout<<5%2<<endl;            //1
    cout<<11%3<<endl;           //2
    cout<<100000%45<<endl;      //10

    cout<<-7%3<<endl;           //-1
    cout<<fixMod(-7,3)<<endl;   //2
    cout<<fixMod(7,3)<<endl;    //1

    primes.resize(N);
    sieve();

    vector<int> arr= {36,120,27,90};
    cout<<gcdArr(arr)<<endl;    //3
    cout<<lcmArr(arr)<<endl;    //1080

    return 0;
}
