#include <iostream>
using namespace std;

void fUC(string s, int n)
{
    static int m = 0;
    if(m<=n){
        // cout<<"Entered if 1\n";
        if(s[m] >= 'A' && s[m] <= 'Z'){
            cout<<s[m]<<"\n";
            return;
        }else{
            ++m;
            fUC(s, n);
        }
    }else{
        cout<<"no uppercase letter\n";
        return;
    }
    m = 0;
}

int main()
{
    fUC("Jatin", 5);
    fUC("vashishT", 8);
    fUC("Hello", 5);
    fUC("stRing", 6);
    fUC("empty", 5);
    return 0;
}