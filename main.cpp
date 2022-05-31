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

    cout << "\n\nBIENVENID@ A MOCHA!\n\nPRESIONA ENTER PARA INICIAR LA PELEA:"<<endl;
    getchar();


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
            
            fighters[i_p] = new peleador(nombre, Salud, Fuerza, Velocidad, Inteligencia, Resistencia, leyenda, ""); //le añadí al constructor el atributo objetos para poder guardar los nombres de los objetos equipados

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

            
            fighters[0]->set_Salud(fighters[0]->get_Salud()*arenas[i_a]->get_Salud());
            fighters[0]->set_Fuerza(fighters[0]->get_Fuerza()*arenas[i_a]->get_Fuerza());
            fighters[0]->set_Velocidad(fighters[0]->get_Velocidad()*arenas[i_a]->get_Velocidad());
            fighters[0]->set_Inteligencia(fighters[0]->get_Inteligencia()*arenas[i_a]->get_Inteligencia());
            fighters[0]->set_Resistencia(fighters[0]->get_Resistencia()*arenas[i_a]->get_Resistencia());

            fighters[1]->set_Salud(fighters[1]->get_Salud()*arenas[i_a]->get_Salud());
            fighters[1]->set_Fuerza(fighters[1]->get_Fuerza()*arenas[i_a]->get_Fuerza());
            fighters[1]->set_Velocidad(fighters[1]->get_Velocidad()*arenas[i_a]->get_Velocidad());
            fighters[1]->set_Inteligencia(fighters[1]->get_Inteligencia()*arenas[i_a]->get_Inteligencia());
            fighters[1]->set_Resistencia(fighters[1]->get_Resistencia()*arenas[i_a]->get_Resistencia());

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
            fighters[i_p-1]->add_object(objects[i_o]->get_name());
            

            i_o++;
        }

    }

    int kod_0 = 0; //KING OF THE DEAD FIGHTER[0]
    int kod_1 = 0;
    int lb_0 = 0; //LAST BREATH FIGHTER[0]
    int lb_1 = 0;
    int reset0 = 0;// RESETEA LOS STATS LUEGO DE REALIZAR LA CONVERSION EN ULTIMO ALIENTO
    int reset1 = 0;

    int prob0 = rand() % 2;
    int prob1 = rand() % 2;

    int health_kod_0;
    int health_kod_1;

    if (prob0 == 0){
        kod_0++;
        health_kod_0 = fighters[0]->get_Salud()*0.5F;
        }
    else lb_0++;
    if (prob1 == 0){
        kod_1++;
        health_kod_1 = fighters[1]->get_Salud()*0.5F;
        }
    else lb_1++;




    output << fighters[0]->get_name() << " equipado con los objetos: "<< fighters[0]->get_objects() <<"\n\nSe enfrenta a\n\n"<< fighters[1]->get_name() << " equipado con los objetos: "<< fighters[1]->get_objects() <<"\n\nSe enfrentan en el "<< arenas[0]->get_info().substr(2)<<endl;
    output << "\n\natributos finales:------------------------------------------\n---------------------------------------------------------------\n-------------------------------------------------------------------\n" <<endl;
    for (int i = 0; i < i_p; i++) output << fighters[i]->get_info() <<endl;
    if (kod_0==1) output << "La arena a conferido a "<< fighters[0]->get_name() << " la habilidad \"rey de los muertos\"\n-----------------------------------------------------------------------"<<endl;
    
    if (lb_0==1) output << "La arena a conferido a "<< fighters[0]->get_name() << " la habilidad \"ultimo aliento\"\n-----------------------------------------------------------------------"<<endl;
    
    if (kod_1==1) output << "La arena a conferido a "<< fighters[1]->get_name() << " la habilidad \"rey de los muertos\"\n-----------------------------------------------------------------------"<<endl;

    if (lb_1==1) output << "La arena a conferido a "<< fighters[1]->get_name() << " la habilidad \"ultimo aliento\"\n-----------------------------------------------------------------------"<<endl;
    
    int turno = 0;
    output << "\n\nINICIO PELEA:\n\n"<<endl;
    while (fighters[0]->get_Salud() > 0 && fighters[1]->get_Salud() > 0)
    {   

        int finish1 = 0;//para ver si los golpes del jugador llegan a 0
        int finish2 = 0;
        int crit = (rand() % 3);
        int golpe1 = fighters[0]->desgaste(turno) * fighters[0]->golpe() * crit;

        if (fighters[0]->desgaste(turno) * fighters[0]->golpe() < 1) {
            finish1++;
            output << fighters[0]->get_name() << " se ha quedado sin resistencia para seguir golpeando" << endl;
        }

        else{
            fighters[1]->set_Salud(fighters[1]->get_Salud() - golpe1);

            if (crit == 0){ output << fighters[0]->get_name() << " falla el turno " << endl;}
            else if (crit == 1)
            {
            output << fighters[0]->get_name() << " Ataca a " << fighters[1]->get_name()<< " con un golpe de "<< golpe1;
                output << ", vida de " << fighters[1]->get_name() << " queda en " << fighters[1]->get_Salud() << endl;
            }
            else {
                output << fighters[0]->get_name() << " Ataca a " << fighters[1]->get_name()<< " con un golpe critico de "<< golpe1;
                output << ", vida de " << fighters[1]->get_name() << " queda en " << fighters[1]->get_Salud() << endl;
            }

            if(reset0 == 1){
                fighters[0]->last_breath_undo();
                reset0--;
            }

            if (fighters[1]->get_Salud()==0 && kod_1 == 1){
                int prob = rand() % 10 + 1;
                    if(prob <= 3){
                    output <<"---------------- " <<fighters[1]->get_name() <<" muere-----------" << endl;
                    output <<"-------- Habilidad especial Rey de los muerto activada -----------------------"<<endl;
                    fighters[1]->kIng_of_the_dead();
                    fighters[1]->set_Salud(health_kod_1);
                    }
            }
            else if (fighters[1]->get_Salud()<=10 && fighters[1]->get_Salud()>0 && lb_1 == 1){
                int prob = rand() % 10 + 1;
                    if(prob <= 4){
                    output <<"---------------- " <<fighters[1]->get_name() <<" está a punto de morir-----------" << endl;
                    output <<"-------- Habilidad especial Ultimo Aliento activada -----------------------"<<endl;
                    fighters[1]->last_breath();
                    reset1++;
                    }
            }
        }

        if (fighters[1]->get_Salud() == 0) {
            output<<"--------- "<<fighters[1]->get_name()<<" muere----------------------\n-------------- Fin de la pelea ----------------------\n-------------- Ganador: "<< fighters[0]->get_name()<<" ----------------" <<endl;
            break;}

        crit = rand() % 3;
        int golpe2 = fighters[1]->desgaste(turno) * fighters[1]->golpe() * crit;

        if (fighters[1]->desgaste(turno) * fighters[1]->golpe() < 1) {
            finish2++;
            output << fighters[1]->get_name() << " se ha quedado sin resistencia para seguir golpeando" << endl;
        }

        else{
            fighters[0]->set_Salud(fighters[0]->get_Salud() - golpe2);

            if (crit == 0){ output << fighters[1]->get_name() << " falla el turno " << endl;}
            else if (crit == 1)
            {
            output << fighters[1]->get_name() << " Ataca a " << fighters[0]->get_name()<< " con un golpe de "<< golpe2;
                output << ", vida de " << fighters[0]->get_name() << " queda en " << fighters[0]->get_Salud() << endl;
            }
            else {
                output << fighters[1]->get_name() << " Ataca a " << fighters[0]->get_name()<< " con un golpe critico de "<< golpe2;
                output << ", vida de " << fighters[0]->get_name() << " queda en " << fighters[0]->get_Salud() << endl;
            }

            if(reset1 == 1){
                fighters[1]->last_breath_undo();
                reset1--;
            }

            if (fighters[0]->get_Salud()==0 && kod_0 == 1){
                int prob = rand() % 10 + 1;
                    if(prob <= 3){
                    output <<"---------------- " <<fighters[0]->get_name() <<" muere-----------" << endl;
                    output <<"-------- Habilidad especial Rey de los muertos activada -----------------------"<<endl;
                    fighters[0]->kIng_of_the_dead();
                    fighters[0]->set_Salud(health_kod_0);
                    }
            }
            else if (fighters[0]->get_Salud()<=10 && fighters[0]->get_Salud()>0 && lb_0 == 1){
                int prob = rand() % 10 + 1;
                    if(prob <= 4){
                    output <<"---------------- " <<fighters[0]->get_name() <<" está a punto de morir-----------" << endl;
                    output <<"-------- Habilidad especial Ultimo Aliento activada -----------------------"<<endl;
                    fighters[0]->last_breath();
                    reset0++;
                    }
            }
        }

        if (fighters[0]->get_Salud() == 0) {
            output<<"--------- "<<fighters[0]->get_name()<<" muere----------------------\n-------------- Fin de la pelea ----------------------\n-------------- Ganador: "<< fighters[1]->get_name()<<" ----------------" <<endl;
            break;}

        if (finish1 > 0 && finish2 > 0){
            output << "---------------------------------Ninguno de los peleadores tiene resistencia para seguir luchando, es un empate------------------" << endl;
            output<<"-------------------------------\n-------------- Fin de la pelea ----------------------\n------------------------------" <<endl;    
            break;}
        

        turno++;

        output << "---------------Fin "<< turno << "° turno---------------------\n---------------------------\n-----------------------------------------------\n-------------------------\n"<<endl;
    }
    
    

//#LIBERAR LA MEMORIA UTILIZADA
    for (int i = 0; i < i_p; i++) delete fighters[i];

    for (int i = 0; i < i_a; i++) delete arenas[i];

    for (int i = 0; i < i_o; i++) delete objects[i];
    

    input.close();
    output.close();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;

    return 0;
}