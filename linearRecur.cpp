#include <iostream>
#include <math.h>

using namespace std;

int power2(int n){
    if(n == 0)
        return 1;
    else
        return (n%2)==0? pow(power2(n/2), 2) : 2*pow(power2(n/2), 2);
}
int main(){
    int n;
    while(cin >> n){
        cout << 2 << "^" << n << "=" << power2(n)<<endl;
    }
}
