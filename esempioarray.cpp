#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    std::cout << "inserisci il numero di registro";
    int numeroPartecipanti;
    cin>> numeroPartecipanti;

    std::cout << "inserisci i nomi";
    std::cout << " X per assente" << endl;
    std::cout << "0 per terminare" << endl;
    string registro [numeroPartecipanti];
    string nome;

    for (int i = 0; i<numeroPartecipanti; i++)
    {   cin>> nome;
        if (nome == "0")
        {
            break;
        }
        else if(nome == "x")
        {
            registro[i] = " Assente";
            std::cout << "Assente" << nome << endl;
        }
        else
        {
            registro[i] = nome;
        }
    }
    int dimensioneArray = sizeof(registro)/sizeof(registro[0]);
    std::cout << "Inseriti" << numeroPartecipanti << " partecipanti" << endl;

    for(int j = 0; j<registro[i].length(); j++)
    cout << 
}

