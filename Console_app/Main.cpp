#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <Windows.h>
#include <exception>
#include "ControlPanel.h"
#include "Recipe.h"
#include "Cake.h"
#include "DiabetesCake.h"
#include "NormalCake.h"
#include "CakeMaker.h"
#include "CakeDepot.h"
using namespace std;


int main()
{
    list<Cake*> list_possible_cakes;

    string cake_name;
    int max_capacity;
    string name;
    int time;
    int option;
    bool tip;//voi deduce ca prijiturile pentru diabetici au tipul 1 si cele normale tipul 0 care sunt precizate in fisier.
    int sugar;

    ifstream fin("retete.txt");

    fin >> max_capacity;
    CakeDepot* cake_depot = new CakeDepot(max_capacity);
    CakeMaker* cake_maker = new CakeMaker();


    ControlPanel* control_panel = new ControlPanel(cake_depot, cake_maker);

    while (fin >> name >> time) {
        // cout << "name: " << name << " time: " << time << endl;
        Recipe r(name, time);
        // cream o reteta 
        fin >> tip; //cout << "tip: " << tip << endl;
        if (tip == 0)
        {
            NormalCake* c = new NormalCake(name, r, tip);
            list_possible_cakes.push_back(c);
            control_panel->AddCake(c);

        }
        else {
            fin >> sugar;
            DiabetesCake* dc = new DiabetesCake(name, r, tip, sugar);
            list_possible_cakes.push_back(dc);
            control_panel->AddCake(dc);
        }
    }

    control_panel->Depot_initialization();

    do
    {
        cout << "\n1. Afisare prajituri posibile" << endl;
        cout << "2. Comanda prajitura" << endl;
        cout << "3. Afisare prajituri existente" << endl;
        cout << "4. Iesire" << endl;
        //cout << "Introduceti optiunea dorita: ";

        while (true) {

            cout << "Introduceti optiunea dorita: ";
            cin >> option;

            if (!cin.good()) {

                cout << "Introduceti un int!" << endl;
                cin.clear();
                cin.ignore();
            }
            else break;
        }

        cout << endl;

        try {

            switch (option)
            {
            case 1:

                for (auto it = list_possible_cakes.begin(); it != list_possible_cakes.end(); it++) {
                    (*it)->Display();
                    cout << endl;
                }
                break;

            case 2:


                cout << "Introduceti numele prajiturii dorite: ";
                cin >> cake_name;
                control_panel->TakeOrder(cake_name);
                break;


            case 3:
                control_panel->fill_deposit(cake_name);
                control_panel->DisplayCake();
                break;

            case 4: exit(0);

            default:
                throw exception("Comanda introdusa este incorecta!");
                break;
            }
        }
        catch (exception e) {
            cout << e.what() << endl; // afisam mesajul de eroare pe ecran
            ofstream log_file;
            log_file.open("log.txt", ios::app); // deschidem fisierul in modul "append" pentru a adauga informatia la finalul fisierului
            log_file << e.what() << endl; // scriem mesajul de eroare in fisier
            log_file.close();
        }

    } while (1);

    fin.close();

    std::system("pause");

    return 0;
}



bool equal(string name, string cake_name) {
    for (size_t i = 0; i < name.size(); ++i)
    {
        char character = tolower(name[i]);
        name[i] = character;
    }
    for (size_t i = 0; i < cake_name.size(); ++i)
    {
        char character = tolower(cake_name[i]);
        cake_name[i] = character;
    }
    if (name == cake_name) return true;
    else return false;
}