#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void imprimir(string palabra);

// inicializa una lista de cadenas con los tipos de variables
string tipos_variables[] = {"INT", "FLOAT", "DOUBLE", "CHAR", "STRING"};
// obtenemos el tamaño de la lista
int size_tipos_variables = sizeof(tipos_variables) / sizeof(tipos_variables[0]);
// inicializa una lista de cadenas con las palabras reservadas
string palabras_reservadas[] = {"IF", "ELSE", "WHILE", "DO", "FOR", "SCAN", "PRINT"};
// obtenemos el tamaño de la lista
int size_palabras_reservadas = sizeof(palabras_reservadas) / sizeof(palabras_reservadas[0]);
// inicializa una lista de cadenas con los caracteres separadores
string caracteres_separadores[] = {",", ";", ":", "."};
// obtenemos el tamaño de la lista
int size_caracteres_separadores = sizeof(caracteres_separadores) / sizeof(caracteres_separadores[0]);
// inicializa una lista de cadenas con los operadores de agrupacion
string operadores_de_agrupacion[] = {"()", "{}", "[]", "{", "}", "(", ")", "[", "]"};
// obtenemos el tamaño de la lista
int size_operadores_de_agrupacion = sizeof(operadores_de_agrupacion) / sizeof(operadores_de_agrupacion[0]);
// inicializa una lista de cadenas con los operadores logicos
string operadores_comparacion[] = {"==", "!=", ">", "<", ">=", "<="};
// obtenemos el tamaño de la lista
int size_operadores_comparacion = sizeof(operadores_comparacion) / sizeof(operadores_comparacion[0]);
// inicializa una lista de cadenas con los operadores aritmeticos
string operadores_aritmeticos[] = {"+", "-", "*", "/", "%", "="};
// obtenemos el tamaño de la lista
int size_operadores_aritmeticos = sizeof(operadores_aritmeticos) / sizeof(operadores_aritmeticos[0]);

void imprimir(string palabra)
{
    // comparamos con el tipo de variable
    for (int i = 0; i < size_tipos_variables; i++)
    {
        if (palabra == tipos_variables[i])
        {
            cout << palabra << " es un tipo de variable" << endl;
            return;
        }
    }
    // comparamos con la palabra reservada
    for (int i = 0; i < size_palabras_reservadas; i++)
    {
        if (palabra == palabras_reservadas[i])
        {
            cout << palabra << " es una palabra reservada" << endl;
            return;
        }
    }
    // comparamos con el caracter separador
    for (int i = 0; i < size_caracteres_separadores; i++)
    {
        if (palabra == caracteres_separadores[i])
        {
            cout << palabra << " es un caracter separador" << endl;
            return;
        }
    }
    // comparamos con el operador de agrupacion
    for (int i = 0; i < size_operadores_de_agrupacion; i++)
    {
        if (palabra == operadores_de_agrupacion[i])
        {
            cout << palabra << " es un operador de agrupacion" << endl;
            return;
        }
    }
    // comparamos con el operador de comparacion
    for (int i = 0; i < size_operadores_comparacion; i++)
    {
        if (palabra == operadores_comparacion[i])
        {
            cout << palabra << " es un operador de comparacion" << endl;
            return;
        }
    }
    // comparamos con el operador aritmetico
    for (int i = 0; i < size_operadores_aritmeticos; i++)
    {
        if (palabra == operadores_aritmeticos[i])
        {
            cout << palabra << " es un operador aritmetico" << endl;
            return;
        }
    }
    // comparamos si es un numero
    if (palabra[0] >= '0' && palabra[0] <= '9')
    {
        cout << palabra << " es un numero" << endl;
        return;
    }
    // si no es ninguna de las anteriores
    // es un identificador
    cout << palabra << " es un identificador" << endl;
    return;
}

int main()
{
    // lee el archivo llamado Input.txt
    // lo guarda en la variable input
    ifstream input("Input.txt");
    string line;
    // lee linea por linea el archivo
    while (getline(input, line))
    {
        // inicializa una variable de tipo cadena para guardar la palabra
        string palabra = "";

        // imprime palabra por palabra
        for (int i = 0; i < line.length(); i++)
        {
            // verificamos si es un caracter separador
            if (line[i] == ',' || line[i] == ';' || line[i] == ':' || line[i] == '.')
            {
                if (palabra != "")
                {
                    imprimir(palabra);
                }
                palabra = line[i];
                // imprime la palabra
                imprimir(palabra);
                // limpia la variable palabra
                palabra = "";
                continue;
            }
            // verificamos si es un operador de agrupacion
            if (line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == '[' || line[i] == ']')
            {
                if (palabra != "")
                {
                    imprimir(palabra);
                }
                palabra = line[i];
                // imprime la palabra
                imprimir(palabra);
                // limpia la variable palabra
                palabra = "";
                continue;
            }
            // verificamos si es un operador de asignacion o comparacion
            if (line[i] == '=' || line[i] == '!' || line[i] == '>' || line[i] == '<')
            {
                if (palabra != "")
                {
                    imprimir(palabra);
                }
                palabra = line[i];
                // si es un operador de asignacion
                if (line[i + 1] == '=')
                {
                    palabra += line[i + 1];
                    i++;
                }
                // imprime la palabra
                imprimir(palabra);
                // limpia la variable palabra
                palabra = "";
                continue;
            }
            // verificamos si es un operador aritmetico
            if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%')
            {
                if (palabra != "")
                {
                    imprimir(palabra);
                }
                palabra = line[i];
                // imprime la palabra
                imprimir(palabra);
                // limpia la variable palabra
                palabra = "";
                continue;
            }
            // verificamos si es un espacio o un salto de linea o un tabulador o un retorno de carro
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\r')
            {
                // imprime la palabra
                if (palabra != "")
                {
                    imprimir(palabra);
                }
                // limpia la variable palabra
                palabra = "";
            }
            else
            {
                // almacena los caracteres en la variable palabra
                palabra += line[i];
            }
        }
    }

    return 0;
}
