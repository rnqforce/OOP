
#include<bits/stdc++.h>

using namespace std;

struct nrComplex{
    int a , b ;
};

struct pisica{
    char nume[20],stapan[20];
    int age;

};

struct persoana{
    char nume[20],prenume[20];
    int age;
};

struct masina{
    char marca[20] , nrInmatrculare[20];
    int age;
};

int f(float n , bool isRoundedTo100 = false){
    if(isRoundedTo100 == false)
        if(((int)n + 0.5 ) >= n ){
            n = (int)n;
        }
        else
            n = int(n) + 1 ;
    else {
        float aux = n - (int)n/100*100;
        if(aux < 50)
            n -= aux;
        else
            n = n - aux + 100 ;
    }
    return n ;
}

int f(int x){
    return sizeof(x);
}

int f(double x){
    return sizeof(x);
}

int f(char* x){

    return strlen(x);
}

float modul(float x){
    return fabs(x);
}

float modul(nrComplex x){

    return sqrt(x.a*x.a + x.b*x.b);
}

template<typename T>
T max(T a,T b ,T c){
    T aux ;
    if(a > b)
        aux = a;
    else
        aux = b ;
    if(aux < c)
        aux = c;
    return aux;
}

template<typename A>
void interSchimb(A a , A b){
    A aux;
    aux = a ;
    a = b ;
    b = aux ;
}

template <typename B>
B Max(B a, B b) {
	return a < b ? b : a;
}


int main(){
    float n ;
    cin >> n ;
    n = f(n,1);
    cout << n ;

    double x ;
    cin >> x;
    cout << f(x) ;

    char s[20];
    cin >> s ;
    cout<< f(s);

}
