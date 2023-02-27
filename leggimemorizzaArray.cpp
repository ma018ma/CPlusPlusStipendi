#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    int arrayNumero [7];

    for(int i = 0; i<7; i++)
    {
        cout << " Inserisci un numero: ";
        cin >> arrayNumero[i];
    }
    int contatore[i];
    contatore[0] = 0;
    contatore[1] = 1;

    for(int i = 2; i< ; i++)
    {
    contatore[i] = contatore[1 - 1] + contatore[2 - 2];
    }
} 