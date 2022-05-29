#include"arena.h"
#include <iostream>
#include <string>

using namespace std;

arena::arena(string nombre, string Salud, string Fuerza, string Velocidad, string Inteligencia, string Resistencia, string leyenda){
    this->nombre = nombre;
    this->Salud = Salud;
    this->Fuerza = Fuerza;
    this->Velocidad = Velocidad;
    this->Inteligencia = Inteligencia;
    this->Resistencia = Resistencia;
    this->leyenda = leyenda;
}


string arena::get_info(){
    return leyenda;
}

string arena::get_name(){return nombre;}