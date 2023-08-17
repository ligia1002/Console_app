#pragma once
#include "CakeDepot.h"
#include "CakeMaker.h"
#include "Cake.h"

#include <string>

class ControlPanel {
private:
    CakeDepot* depot;
    CakeMaker* maker;
    list<Cake*> cakes;

public:
    ControlPanel(CakeDepot* depot, CakeMaker* maker)
    {
        this->depot = depot;
        this->maker = maker;
    }

    void AddCake(Cake* cake) {
        cakes.push_back(cake);
    }

    void DisplayCake()
    {
        cout << "Lista de prajiturile disponibile: " << endl;
        depot->DisplayCakes();
    }

    void Depot_initialization() {
        for (auto it = cakes.begin(); it != cakes.end() && depot->get_current_capacity() != depot->get_max_capacity(); it++) {
            depot->AddCake(*it);
        }
    }

    void AutoRefill(string name)
    {
        // Verificam daca ultima prajitura comandata se afla in depozit
        /*if (depot->get_current_capacity() != 0)
        for (auto it = depot->get_cakes().begin(); it != depot->get_cakes().end(); it++) {
            if ((*it)->get_tip()) {
                cout << "Depozitul este deja umplut." << endl;
                return;
            }
        }*/

        // Daca ultima prajitura comandata nu se afla in depozit, o preparam
        for (auto it = cakes.begin(); it != cakes.end(); it++) {
            if ((*it)->get_name() == name) {
                Cake* cake = maker->prepare_cake((*it)->get_recipe(), (*it)->get_tip(), (*it)->get_sugar_amount());
                depot->AddCake(cake);
                return;
            }
        }
        cout << "Nu s-a putut gasi o reteta pentru ultima prajitura comandata." << endl;

    }
    void fill_deposit(string cake_name)
    {
        int time;
        if (depot->get_current_capacity() < depot->get_max_capacity()) {
            if (depot->get_current_capacity() != depot->get_max_capacity()) {
                for (auto it = cakes.begin(); it != cakes.end(); it++)
                    if ((*it)->get_name() == cake_name)
                        time = depot->get_time_D(*it);

                cout << "Va rugam asteptati " << (depot->get_max_capacity() - depot->get_current_capacity()) * time << " minute pana se umple depozitul. " << endl;

                while (depot->get_current_capacity() < depot->get_max_capacity()) {
                    AutoRefill(cake_name);
                }

                cout << "Depozitul a fost umplut cu ultima prajitura comandata." << endl;
            }
        }
    }
    void TakeOrder(string cake_name)
    {

        if (depot->get_current_capacity() == 0)
            fill_deposit(cake_name);

        //depot->DisplayCakes();

        if (depot->check_if_in_deposit(cake_name) == true) {
            // Prajitura se afla in depozit
            depot->RemoveCake(cake_name);
            cout << "Prajitura " << cake_name << " a fost servita." << endl;
            if (depot->get_current_capacity() == 0)
                fill_deposit(cake_name);
            return;
        }
        // Prajitura nu se afla in depozit, trebuie sa o preparam folosind reteta aferenta

         //cout << depot->get_current_capacity() << endl;
        // cout << depot->get_max_capacity() << endl;

        if (depot->get_current_capacity() == depot->get_max_capacity()) cout << "Depozitul este plin cu alte prajituri, va rog comandati din acela ca sa se mai goleasca depozitul. " << endl;
        else
            for (auto it = cakes.begin(); it != cakes.end(); it++) {
                if ((*it)->get_name() == cake_name) {
                    cout << "Va rugam asteptati " << (*it)->get_recipe().get_time() << " minute pana se prepara prajitura. " << endl;
                    Cake* cake = maker->prepare_cake((*it)->get_recipe(), (*it)->get_tip(), (*it)->get_sugar_amount());
                    cout << "Prajitura " << cake_name << " a fost preparata si servita." << endl;
                    return;
                }
            }

        // Nu am gasit prajitura in depozit sau retetele disponibile
        cout << "Prajitura " << cake_name << " nu este disponibila." << endl;
    }

};