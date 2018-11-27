#include <iostream>
#include "Bignum.h"
using namespace std;
bool isNumber(string s);
int instructions();
void add();
void sub();
void mult();
void divide();
void modulo();
void expon();
void isGreater();
void isLess();
void areEqual();
void addM();
void subM();
void multM();
void divideM();
void exponM();
void squareRoot();

int main()
{
    int k;
    do{
        k = instructions();
        switch(k){
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mult();
            break;
        case 4:
            divide();
            break;
        case 5:
            modulo();
            break;
        case 6:
            expon();
            break;
        case 7:
            isGreater();
            break;
        case 8:
            isLess();
            break;
        case 9:
            areEqual();
            break;
        case 10:
            addM();
            break;
        case 11:
            subM();
            break;
        case 12:
            multM();
            break;
        case 13:
            divideM();
            break;
        case 14:
            exponM();
            break;
        case 15:
            squareRoot();
            break;
        case 16:
            systemEq();
            break;
        case 17:
            return 0;
        default:
            break;
        }
        system("pause");

    }while (k != 17);

    return 0;
}

bool isNumber(string s){
    if (s.length()==0)
        return false;
    if (s[0]!='-' && (s[0]<'0' || s[0]>'9'))
        return false;
    for (int i=1; i<s.length(); i++)
        if (s[i]<'0' || s[i]>'9')
        return false;
    return true;
}

int instructions(){
    string st;
    int k = -1;
    bool flag = true;
    do{
        cout << " 1. Add numbers\n 2. Subtract\n 3. Multiply\n 4. Divide\n 5. Modulo\n 6. Power\n ";
        cout << "Compare numbers:\n  7. >\n  8. <\n  9. =\n ";
        cout << "With modulo:\n  10. Add\n  11. Subtract\n  12. Multiply\n  13. Divide\n  14. Power\n";
        cout << " 15. Square root\n 16. System of congruence equations\n 17. Finish\n";
        cout << "Choose operation: ";
        cin >> st;
        if (isNumber(st) && st.length()<10)
            k = stoi(st);
        if (k < 0 || k > 17)
            cout << "Ooops, try again\n";
        else
            flag = false;
    }while(flag);
    return k;
}

void add(){
    string s;
    cout << "Enter first summand: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter second summand: \n";
    cin >> s;
    BigNum B(s);
    cout << "Sum: \n";
    BigNum V = A+B;
    V.output();
    cout << endl;
}

void sub(){
    string s;
    cout << "Enter minuend: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter subtrahend: \n";
    cin >> s;
    BigNum B(s);
    cout << "Difference: \n";
    BigNum V = A-B;
    V.output();
    cout << endl;
}

void mult(){
    string s;
    cout << "Enter multiplier: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter multiplicand: \n";
    cin >> s;
    BigNum B(s);
    cout << "Product: \n";
    BigNum V = A*B;
    V.output();
    cout << endl;
}

void divide(){
    string s;
    cout << "Enter dividend: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter divisor: \n";
    cin >> s;
    if (s=='0'){
        cout << "Try again\n";
        return;
    }
    BigNum B(s);
    cout << "Quotient: \n";
    BigNum V = A/B;
    V.output();
    cout << endl;
}

void modulo(){
    string s;
    cout << "Enter dividend: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter divisor: \n";
    cin >> s;
    BigNum B(s);
    cout << "Remainder: \n";
    BigNum V = A%B;
    V.output();
    cout << endl;
}

void expon(){
    string s;
    cout << "Enter base: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter exponent: \n";
    cin >> s;
    BigNum B(s);
    cout << "Power: \n";
    BigNum V = binPow(A,B);
    V.output();
    cout << endl;
}

void isGreater(){
    string s;
    cout << "Enter first number: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter second number: \n";
    cin >> s;
    BigNum B(s);
    cout << "Answer: ";
    if (A>B)
        cout << "true\n";
    else cout << "false\n";
    cout << endl;
}

void isLess(){
    string s;
    cout << "Enter first number: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter second number: \n";
    cin >> s;
    BigNum B(s);
    cout << "Answer: ";
    if (A<B)
        cout << "true\n";
    else cout << "false\n";
    cout << endl;
}

void areEqual(){
    string s;
    cout << "Enter first number: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter second number: \n";
    cin >> s;
    BigNum B(s);
    cout << "Answer: ";
    if (A==B)
        cout << "true\n";
    else cout << "false\n";
    cout << endl;
}

void addM(){
    string s;
    cout << "Enter first summand: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter second summand: \n";
    cin >> s;
    BigNum B(s);
    cout << "Enter modulo: \n";
    cin >> s;
    BigNum C(s);
    cout << "Sum: \n";
    BigNum V = (A+B)%C;
    V.output();
    cout << endl;
}

void subM(){
    string s;
    cout << "Enter minuend: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter subtrahend: \n";
    cin >> s;
    BigNum B(s);
    cout << "Enter modulo: \n";
    cin >> s;
    BigNum C(s);
    cout << "Difference: \n";
    BigNum V = (A-B) % C;
    V.output();
    cout << endl;
}

void multM(){
    string s;
    cout << "Enter multiplier: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter multiplicand: \n";
    cin >> s;
    BigNum B(s);
    cout << "Enter modulo: \n";
    cin >> s;
    BigNum C(s);
    cout << "Product: \n";
    BigNum V = (A*B)%C;
    V.output();
    cout << endl;
}

void divideM(){
    string s;
    cout << "Enter dividend: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter divisor: \n";
    cin >> s;
    BigNum B(s);
    cout << "Enter modulo: \n";
    cin >> s;
    if (s=='0'){
        cout << "Try again\n";
        return;
    }
    BigNum C(s);
    cout << "Quotient: \n";
    BigNum V = (A/B)%C;
    V.output();
    cout << endl;
}

void exponM(){
    string s;
    cout << "Enter base: \n";
    cin >> s;
    BigNum A(s);
    cout << "Enter exponent: \n";
    cin >> s;
    BigNum B(s);
    cout << "Enter modulo: \n";
    cin >> s;
    BigNum C(s);
    cout << "Power: \n";
    BigNum V = binPowMod(A,B,C);
    V.output();
    cout << endl;
}

void squareRoot(){
    string s;
    cout << "Enter number: \n";
    cin >> s;
    BigNum A(s);
    cout << "Square root: \n";
    BigNum V = A.square();
    V.output();
    cout << endl;
}
