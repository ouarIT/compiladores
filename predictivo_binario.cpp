#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int preanalisis = 0;
string sr;

int B();
int Bp(int valorH);
int D();
void empareja(char c) throw(exception);

int B()
{
    int valorD = -1, valorB = -1;
    valorD = D();
    valorB = Bp(valorD);
    return valorB;
}

int Bp(int valorH)
{
    int valorD = -1, valorB = -1;
    if (preanalisis == '0' || preanalisis == '1')
    {
        valorD = D();
        valorB = Bp((valorH * 2) + valorD);
    }
    else
    {
        valorB = valorH;
    }
    return valorB;
}

int D()
{
    int valorD = -1;
    if (preanalisis == '0' || preanalisis == '1')
    {
        try
        {
            valorD = preanalisis - '0';
            empareja(preanalisis);
        }
        catch (exception e)
        {
            cout << "Error en D" << endl;
        }
    }
    else
    {
        cout << "Error de sintaxis" << endl;
    }
    return valorD;
}

void empareja(char c) throw(exception)
{
    if (preanalisis == c)
    {
        sr = sr.substr(1);
        preanalisis = sr[0];
    }
    else
    {
        throw exception();
    }
}

int main()
{
    while (true)
    {
        // read console input
        cout << "Ingrese la cadena a evaluar: ";
        cin >> sr;
        cout << "Cadena a evaluar: " << sr << endl;
        cout << "---Predictivo binario---" << endl;
        // set preanalisis
        preanalisis = sr[0];

        cout << "Valor de B: " << B() << endl;
        cout << endl;
    }
}
