#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int B();
int Bp(int valorH);
int D();
void empareja(char c) throw(exception);

int preanalisis = 0, base = 0, diferencia = 55;
string sr;

int main()
{
    while (true)
    {
        do
        {
            cout << "Ingrese la BASE (entre 2 y 36) de la cadena a evaluar: ";
            cin >> base;
        } while (base < 2 || base > 36);

        cout << "Ingrese la cadena a evaluar: ";
        cin >> sr;

        // convert to mayus
        for (int i = 0; i < sr.length(); i++)
        {
            if (sr[i] >= 'a' && sr[i] <= 'z')
            {
                sr[i] = sr[i] - 32;
            }
        }

        cout << "La cadena ingresada es: " << sr << endl;
        cout << "--- Inicia el analisis ---" << endl;
        preanalisis = sr[0];
        cout << "Valor de B: " << B() << endl;
        cout << "--- Finaliza el analisis ---" << endl;
        }

    return 0;
}

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
    if (preanalisis >= '0' && preanalisis <= '9' || preanalisis >= 'A' && preanalisis <= 'Z')
    {
        valorD = D();
        valorB = Bp((valorH * base) + valorD);
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
    if (preanalisis >= '0' && preanalisis <= '9')
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
    else if (preanalisis >= 'A' && preanalisis <= 'Z')
    {
        try
        {
            valorD = preanalisis - diferencia;
            empareja(preanalisis);
        }
        catch (exception e)
        {
            cout << "Error en D" << endl;
        }
    }
    else
    {
        cout << "Error en D" << endl;
    }
    return valorD;
}

void empareja(char c) throw(exception)
{
    if (preanalisis == c)
    {
        try
        {

            if (sr.length() == 0)
            {
                preanalisis = '$';
            }
            else
            {
                sr = sr.substr(1);
                preanalisis = sr[0];
            }
        }
        catch (const char *msg)
        {
        }
    }
    else
    {
        cout << "-- Error de sintaxis -- " << endl;
        throw "Error de sintaxis";
    }
}
