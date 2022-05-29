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

    ifstream input;
    ofstream output;

    string s;

    int i_p = 0;

    int i_a = 0;

    int i_o = 0;

    string file;

    for (int i = 1; i < argc; i++)
    {
        file += argv[i];
        if (i < argc-1) file += " ";
    }
    

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

            
            fighters[i_p-1]->set_Salud(fighters[i_p-1]->get_Salud()+objects[i_o]->get_Salud());
            fighters[i_p-1]->set_Fuerza(fighters[i_p-1]->get_Fuerza()+objects[i_o]->get_Fuerza());
            fighters[i_p-1]->set_Velocidad(fighters[i_p-1]->get_Velocidad()+objects[i_o]->get_Velocidad());
            fighters[i_p-1]->set_Inteligencia(fighters[i_p-1]->get_Inteligencia()+objects[i_o]->get_Inteligencia());
            fighters[i_p-1]->set_Resistencia(fighters[i_p-1]->get_Resistencia()+objects[i_o]->get_Resistencia());
            

            i_o++;
        }

    }

    


    //for (int i = 0; i < 10; i++) output << fighters[0]->desgaste(i) * fighters[0]->golpe() * (rand() % 3) << endl;  ESTE ES EL CODIGO CON EL QUE SE CALCULAN LOS GOLPES

    output << fighters[0]->get_name() << " Equipado con: \n\nSe enfrenta a\n\n"<< fighters[1]->get_name() << " Equipado con: \n\nSe enfrentan en el "<< arenas[0]->get_info().substr(2)<<endl;
    output << "\n\natributos finales:------------------------------------------\n---------------------------------------------------------------\n------------------------------------------------------------------- " <<endl;
    for (int i = 0; i < i_p; i++) output << fighters[i]->get_info() <<endl;

    int turno = 0;
    output << "\n\nINICIO PELEA:\n\n"<<endl;
    while (fighters[0]->get_Salud() > 0 && fighters[1]->get_Salud() > 0)
    {
        int golpe1 = fighters[0]->desgaste(turno) * fighters[0]->golpe() * (rand() % 3);

        if (golpe1 < 1 && golpe1 != 0) golpe1 = 1;

        fighters[1]->set_Salud(fighters[1]->get_Salud() - golpe1);

        output << fighters[0]->get_name() << " Ataca a " << fighters[1]->get_name()<< " con un golpe de "<< golpe1 << endl;
        output << ".Vida de " << fighters[1]->get_name() << " queda en " << fighters[1]->get_Salud() << endl;

        if (fighters[1]->get_Salud() == 0) {
            output<<"--------- "<<fighters[1]->get_name()<<" muere----------------------\n-------------- Fin de la pelea ----------------------\n-------------- Ganador: "<< fighters[0]->get_name()<<" ----------------" <<endl;
            break;}

        int golpe2 = fighters[1]->desgaste(turno) * fighters[1]->golpe() * (rand() % 3);

        if (golpe2 < 1 && golpe2 != 0) golpe2 = 1;

        fighters[0]->set_Salud(fighters[0]->get_Salud() - golpe2);

        output << fighters[1]->get_name() << " Ataca a " << fighters[0]->get_name()<< " con un golpe de "<< golpe2 << endl;
        output << ".Vida de " << fighters[0]->get_name() << " queda en " << fighters[0]->get_Salud() << endl;

        if (fighters[0]->get_Salud() == 0) {
            output<<"--------- "<<fighters[0]->get_name()<<" muere----------------------\n-------------- Fin de la pelea ----------------------\n-------------- Ganador: "<< fighters[1]->get_name()<<" ----------------" <<endl;
            break;}

        turno++;

        output << "---------------Fin "<< turno << "° turno---------------------\n---------------------------\n-----------------------------------------------\n-------------------------"<<endl;
    }
    
    

//#LIBERAR LA MEMORIA UTILIZADA
    for (int i = 0; i < i_p; i++) delete fighters[i];

    for (int i = 0; i < i_a; i++) delete arenas[i];

    for (int i = 0; i < i_o; i++) delete objects[i];
    

    input.close();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;

    return 0;
}