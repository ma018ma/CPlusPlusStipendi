#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string cerca(string nomefile, string cod)
{
    string risultato = "";
    ifstream fileAperto(nomefile);
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            for (int i = 0; i < 6; i++)
            {
                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4)
                {
                    for (int w = 6; w < line.length(); w++)
                    {   
                        risultato += line[w];
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Impossibile aprire il file .txt" << endl;
    }
    return risultato;
}

void findNameByCod(string cod)
{
    string risultato = cerca("matricola.txt", cod);
    cout << "La matricola: " << cod << " corrisponde al nome: " << risultato << endl;
}
void findSalaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("stipendi.txt", cod) << endl;
}

void findStraordinaryByCod(string cod)
{
    cout << "matricola: " << cod << " straordinario: " << cerca("straordinari.txt", cod) << endl;
}

void findSalaryByName(string nome)

{
    ifstream fileAperto("matricola.txt");
    string cod = "";
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            int k=0;
            for (int i = 6; i < line.length(); i++)
            {
                if (line[i] != nome[k])
                {
                    break;
                }
                else if (k == nome.length()-1)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cod += line[j];
                    }
                }
                k++;
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt" << endl;
    }
    string stipendioValore = cerca ("stipendi.txt", cod);
    std::cout << "Il nome: " << nome << " corrisponde alla matricola: " << cod << " e al stipendio: " << stipendioValore << endl;
}

void findSalaryAndStraordinaryByCod(string cod)
{
    int stipendio = stoi(cerca("stipendi.txt", cod));
    int straordinario = stoi(cerca("straordinari.txt", cod)) *35;
    cout<<"La matricola: "<< cod << " guadagna: "<< stipendio + straordinario <<endl;

}
int main()
{
    std::cout << "Benvenuto nel programma di calcolo stipendi" << endl;
    bool flag = true;
    while (flag)
    {
        std::cout << "Inserisci il numero della funzionalita che vuoi attivare" << endl;
        std::cout << "1. Matricola -> Nome" << endl;
        std::cout << "2. Matricola -> Stipendio" << endl;
        std::cout << "3. Matricola -> Straordinari" << endl;
        std::cout << "4. Nome -> Stipendio" << endl;
        std::cout << "5. Matricola -> Stipendio + straordinari (35£/h)" << endl;
        std::cout << "Inserisci quello che vuoi cercare" << endl;
        cout << "inserisci 0 per uscire" << endl;
        int scelta;
        cin >> scelta;
        cout << "Cosa cerchi?" << endl;
        string input = "";
        cin >> input;

        if (scelta < 0 || scelta > 5)
        {
            std::cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
                flag = true;
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
                flag = true;
            }
            else if (scelta == 3)
            {
                findStraordinaryByCod(input);
                flag = true;
            }
            else if (scelta == 4)
            {
                findSalaryByName(input);
                flag = true;
            }
            else if (scelta == 5)
            {
                findSalaryAndStraordinaryByCod(input);
                flag = true;
            }
            else if (scelta == 0)
            {
                flag = false;
            }
            else
            {
                std::cout << "Scelta non valida" << endl;
            }
        }
    }
    std::cout << "Fine" << endl;
}