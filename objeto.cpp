#include"objeto.h"
#include <iostream>
#include <string>

using namespace std;

objeto::objeto( string nombre, string tipo, string Salud, string Fuerza, string Velocidad, string Inteligencia, string Resistencia, string leyenda){
    this->nombre = nombre;
    this->tipo = tipo;
    this->Salud = Salud;
    this->Fuerza = Fuerza;
    this->Velocidad = Velocidad;
    this->Inteligencia = Inteligencia;
    this->Resistencia = Resistencia;
    this->leyenda = leyenda;
}

void objeto::get_info(){
    cout << "Nombre: " << nombre << " Tipo: " << tipo << " Salud: " << Salud << " Fuerza: " << Fuerza << endl;
}