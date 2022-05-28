#include"arena.h"
#include"peleador.h"
#include"objeto.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){

    auto start = high_resolution_clock::now();

    srand(time(nullptr));

    int a = argc;

    cout << a << endl;

    ifstream input;
    ofstream output;

    string s;

    int i_p = 0;

    int i_a = 0;

    int i_o = 0;

    string file = argv[1];

    cout << file << argv[1] << endl;

    input.open(file);
    output.open("Salida.txt");

    while (std::getline(input, s)){
        
        string type;

        std::istringstream ss(s); //Convertir a ifstream para poder usar el delimitador de getline()
        
        std::getline(ss, type, ';');

        type = type.substr(1);

        if(type == "peleador" || type == "Peleador") i_p++;

        else if(type == "Arena" || type == "arena") i_a++;

        else if(type == "Objeto" || type == "objeto") i_o++;
        

    }

    peleador * fighters[i_p];

    arena * arenas[i_a];

    objeto * objects[i_o];


    input.clear();
    input.seekg(0, ios::beg);

    i_p = 0;
    i_a = 0;
    i_o = 0;
    
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
            while(std::getline(ss, sub, ';')){ leyenda = leyenda.append(sub);}
            
            fighters[i_p] = new peleador(nombre, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);

            i_p++;
        }

        else if(type == "Arena" || type == "arena"){

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
            while(std::getline(ss, sub, ';')){ leyenda = leyenda.append(sub);}

            arenas[i_a] = new arena(nombre, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);


            i_a++;
        }

        else if(type == "Objeto" || type == "objeto"){

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
            while(std::getline(ss, sub, ';')){ leyenda = leyenda.append(sub);}

            objects[i_o] = new objeto(nombre, tipo, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda);

            //DEBO ARREGLAR LA CONVERSION A DECIMAL PERO ESTÁ FUNCIONANDO
            fighters[i_p-1]->set_Inteligencia(fighters[i_p-1]->get_Inteligencia()*objects[i_o]->get_Inteligencia() + 1);

            i_o++;
        }

    }

    for (int i = 0; i < i_p; i++) output << fighters[i]->get_name() << fighters[i]->get_Inteligencia() <<endl;;

    for (int i = 0; i < i_a; i++) output << arenas[i]->get_name() << endl;

    for (int i = 0; i < i_o; i++) output << objects[i]->get_name() << objects[i]->get_Inteligencia() << endl;


    //for (int i = 0; i < 10; i++) output << fighters[0]->desgaste(i) * fighters[0]->golpe() * (rand() % 3) << endl;  ESTE ES EL CODIGO CON EL QUE SE CALCULAN LOS GOLPES

    int turno = 0;

    while (fighters[0]->get_Salud() > 0 && fighters[1]->get_Salud() > 0)
    {
        double golpe1 = fighters[0]->desgaste(turno) * fighters[0]->golpe() * (rand() % 3);

        if (golpe1 < 1 && golpe1 != 0) golpe1 = 1;

        fighters[1]->set_Salud(fighters[1]->get_Salud() - golpe1);

        output << "El peleador: " << fighters[0]->get_name() << " Realizo un golpe de: " << golpe1 << endl;
        output << "La salud restante de: " << fighters[1]->get_name() << " es: " << fighters[1]->get_Salud() << endl;

        turno++;
    }
    


//#LIBERAR LA MEMORIA UTILIZADA
    for (int i = 0; i < i_p; i++) delete fighters[i];

    for (int i = 0; i < i_a; i++) delete arenas[i];

    for (int i = 0; i < i_o; i++) delete objects[i];
    

    input.close();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << duration.count() << endl;

    return 0;
}