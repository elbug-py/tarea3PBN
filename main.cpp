#include"arena.h"
#include"peleador.h"
#include"objeto.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ifstream input;

    string s;

    peleador * fighters[100];

    arena * arenas[100];

    objeto * objects[100];

    int i_p = 0;

    int i_a = 0;

    int i_o = 0;

    input.open("data tarea 3.csv");

    
    while (std::getline(input, s))
    {
        string sub;

        string type;

        std::istringstream ss(s); //Convertir a ifstream para poder usar el delimitador de getline()
        
        std::getline(ss, type, ';');

        type = type.substr(1);

        //cout << "EL TIPO ES: " << type << endl;

        if(type == "peleador" || type == "Peleador"){

            std::getline(ss, sub, ';');
            string nombre = sub;
            std::getline(ss, sub, ';');
            int Salud = stoi(sub);
            std::getline(ss, sub, ';');
            int Fuerza = stoi(sub);
            std::getline(ss, sub, ';'); 
            int Velocidad = stoi(sub);
            std::getline(ss, sub, ';');
            int Inteligencia = stoi(sub);
            std::getline(ss, sub, ';');
            int Resistencia = stoi(sub);
            std::getline(ss, sub, ';');
            string leyenda = sub;

            fighters[i_p] = new peleador(nombre, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);

            i_p++;
        }

        if(type == "Arena" || type == "arena"){

            std::getline(ss, sub, ';');
            string nombre = sub;
            std::getline(ss, sub, ';');
            string Salud = sub;
            std::getline(ss, sub, ';');
            string Fuerza = sub;
            std::getline(ss, sub, ';'); 
            string Velocidad = sub;
            std::getline(ss, sub, ';');
            string Inteligencia = sub;
            std::getline(ss, sub, ';');
            string Resistencia = sub;
            std::getline(ss, sub, ';');
            string leyenda = sub;

            arenas[i_a] = new arena(nombre, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);


            i_a++;
        }

        if(type == "Objeto" || type == "objeto"){

            std::getline(ss, sub, ';');
            string nombre = sub;
            std::getline(ss, sub, ';');
            string tipo = sub;
            std::getline(ss, sub, ';');
            string Salud = sub;
            std::getline(ss, sub, ';');
            string Fuerza = sub;
            std::getline(ss, sub, ';'); 
            string Velocidad = sub;
            std::getline(ss, sub, ';');
            string Inteligencia = sub;
            std::getline(ss, sub, ';');
            string Resistencia = sub;
            std::getline(ss, sub, ';');
            string leyenda = sub;

            objects[i_o] = new objeto(nombre, tipo, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);

            i_o++;
        }

    }

    for (int i = 0; i < i_p; i++)
    {
        fighters[i]->get_info();
        delete fighters[i];
    }
    

    for (int i = 0; i < i_a; i++)
    {
        arenas[i]->get_info();
        delete arenas[i];
    }

    for (int i = 0; i < i_o; i++)
    {
        objects[i]->get_info();
        delete objects[i];
    }
    
    

    input.close();

    return 0;
}