// code template c++

#include <bits/stdc++.h>
using namespace std;

int main() {
    // solution

    // to make input/output more efficient
    ios::sync_with_studio(0);
    cin.tie(0);

    // to read input from a file
    freopen("input.txt", "r", stdin);

    // to write output to a file
    freopen("output.txt", "w", stdout);

    int a, b;
    string x;

    cin >> a >> b >> x;
    cout << a << b << x;

    // long long variable, suffix LL defines the number is long long
    long long x = 12324342342352352423423LL;

    // common issue, where multiplying 2 int's can give a long output but then I forget to declare it earlier
    int a = 1223224;
    long long x = (long long) a*a;
    cout << x << "\n";

    // to input whole line
    string s;
    getline(cin, s);

    // loop for input where there is large number of data
    while (cin >> x) {
        // code
    }


    // to shorten the code use typedef
    typedef long long ll;
    ll a = 1242342355;

    typedef vector<int> vi;
    typedef pair<int,int> pi;

    // macros: strings in the code will be changed before the compilation
    // macros are defined using #define keyword

    #define F first
    #define S second
    
    int d = v[i].F + v[i].S;

    // can be used in loops as well

    #define REP(i,a,b) for (int i = a; i <= b; i++)

    REP(i,1,n) {
        search(i);
    }

    // be concise

    #define SQ(a) (a)*(a)
    cout << SQ(3+3) << "\n";




}


// int is 32-bit whereas long long is 64-bit
// __int128_t is 128 bit type


// to compile the code we use
// g++ -std=c++11 -02 0-Wall test.cpp -o test

