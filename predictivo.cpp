// incluye las librerias estandares

#include <iostream>
#include <fstream>
#include <string>

// declara el uso de namespace std
using namespace std;

int preanalisis;
string sr;

void expr()
{
    cout << "-- Llama a T -- " << endl;
    term();
    cout << "-- Llama a E' -- " << endl;
    exprp();
}

void exprp()
{
    cout << "-- Entra a E' -- " << endl;
    if (preanalisis == '+')
    {
        try
        {
            cout << "-- entra a + -- " << endl;
            empareja('+');
            term();
            exprp();
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '-')
    {
        try
        {
            cout << "-- entra a - -- " << endl;
            empareja('-');
            term();
            exprp();
        }
        catch (const char *msg)
        {
        }
    }
    else
    {
        cout << "-- entra a lambda -- " << endl;
    }
}

void term()
{
    cout << "-- Llama a F -- " << endl;
    exp();
    cout << "-- Llama a T' -- " << endl;
    termp();
}

void termp()
{
    cout << "-- Entra a T' -- " << endl;
    if (preanalisis == '*')
    {
        try
        {
            cout << "-- entra a * -- " << endl;
            empareja('*');
            exp();
            termp();
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '/')
    {
        try
        {
            cout << "-- entra a / -- " << endl;
            empareja('/');
            exp();
            termp();
        }
        catch (const char *msg)
        {
        }
    }
    else
    {
        cout << "-- entra a lambda -- " << endl;
    }
}

void exp()
{
    cout << "-- Entra a F -- " << endl;
    if (preanalisis == '(')
    {
        try
        {
            cout << "-- entra a ( -- " << endl;
            empareja('(');
            expr();
            empareja(')');
            cout << "-- sale de ) -- " << endl;
        }
        catch (const char *msg)
        {
        }
    }
    else
    {
        cout << "-- llamada a N --" << endl;
        digito();
    }
}

void digito()
{
    cout << "-- Entra a N -- " << endl;
    if (preanalisis == '0')
    {
        try
        {
            empareja('0');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '1')
    {
        try
        {
            empareja('1');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '2')
    {
        try
        {
            empareja('2');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '3')
    {
        try
        {
            empareja('3');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '4')
    {
        try
        {
            empareja('4');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '5')
    {
        try
        {
            empareja('5');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '6')
    {
        try
        {
            empareja('6');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '7')
    {
        try
        {
            empareja('7');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '8')
    {
        try
        {
            empareja('8');
        }
        catch (const char *msg)
        {
        }
    }
    else if (preanalisis == '9')
    {
        try
        {
            empareja('9');
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

void empareja(char c) throw(exception)
{
    cout << "-- Entra a empareja -- " << endl;
    if (preanalisis == c)
    {
        try
        {
            cout << "-- entra a empareja -- " << endl;
            preanalisis = sr[0];
            sr = sr.substr(1);
            cout << "-- sale de empareja -- " << endl;
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

int main()
{
    cout << "Ingrese la cadena a evaluar: ";
    cin >> sr;
    preanalisis = sr[0];
    sr = sr.substr(1);
    expr();
    cout << "La cadena es valida" << endl;
    // doasnflanf
    return 0;
}