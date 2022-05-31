#include"peleador.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

peleador::peleador(string nombre, int Salud, int Fuerza, int Velocidad, int Inteligencia, int Resistencia, string leyenda, string Objetos){
    this->nombre = nombre;
    this->Salud = Salud;
    this->Fuerza = Fuerza;
    this->Velocidad = Velocidad;
    this->Inteligencia = Inteligencia;
    this->Resistencia = Resistencia;
    this->leyenda = leyenda;
    this->objetos = Objetos;
}



string peleador::get_info(){
    string info;

    info += "Nombre: ";
    info += nombre;
    info += "\n- Salud: ";
    info += to_string(Salud);
    info += "\n- Fuerza: ";
    info += to_string(Fuerza);
    info += "\n- Velocidad: ";
    info += to_string(Velocidad);
    info += "\n- Inteligencia: ";
    info += to_string(Inteligencia);
    info += "\n- Resistencia: ";
    info += to_string(Resistencia);
    info += "\n";


    return info;
}


void peleador::set_Salud(int Salud) {if(Salud>=0) this->Salud=Salud;
                                    else this->Salud = 0;}

void peleador::set_Fuerza(int Fuerza) {if(Fuerza>=0) this->Fuerza=Fuerza;
                                    else this->Fuerza = 0;}

void peleador::set_Velocidad(int Velocidad) {if(Velocidad>=0) this->Velocidad=Velocidad;
                                    else this->Velocidad = 0;}

void peleador::set_Inteligencia(int Inteligencia) {if(Inteligencia>=0) this->Inteligencia=Inteligencia;
                                    else this->Inteligencia = 0;}

void peleador::set_Resistencia(int Resistencia) {if(Resistencia>=0) this->Resistencia=Resistencia;
                                    else this->Resistencia = 0;}


string peleador::get_name(){return nombre;}

int peleador::get_Salud(){return this->Salud;}

int peleador::get_Fuerza(){return this->Fuerza;}

int peleador::get_Velocidad(){return this->Velocidad;}

int peleador::get_Inteligencia(){return this->Inteligencia;}

int peleador::get_Resistencia(){return this->Resistencia;}

string peleador::get_objects(){return this->objetos;}

double peleador::desgaste(int Turno){
    if (Resistencia > 1){
        double frac = 20*Turno/Resistencia;
        return (exp(frac*-1))*(1+frac);
    }
    else return 0;
    }

double peleador::golpe(){
    double frac = Velocidad * Fuerza / (Velocidad + Fuerza);
    double punch = frac + Inteligencia; //RECORDAR MULTIPLICAR ESTO POR desgaste(turno) Y POR EL NUMERO RANDOM
    return punch;
}

void peleador::add_object(string obj){this->objetos += obj;
                                    this->objetos+=" ";}

void peleador::kIng_of_the_dead(){
    Inteligencia *= 0.5F;
}

void peleador::last_breath(){
    set_Salud(1);
    set_Fuerza(get_Fuerza()*1.5F);
    set_Velocidad(get_Velocidad()*1.5F);
    set_Resistencia(get_Resistencia()*1.5F);
}

void peleador::last_breath_undo(){
    set_Fuerza(get_Fuerza()/1.5F);
    set_Velocidad(get_Velocidad()/1.5F);
    set_Resistencia(get_Resistencia()/1.5F);
}
