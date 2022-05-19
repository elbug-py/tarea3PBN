#include"peleador.h"
#include <iostream>
#include <string>

using namespace std;

peleador::peleador(string nombre, int Salud, int Fuerza, int Velocidad, int Inteligencia, int Resistencia, string leyenda){
    this->nombre = nombre;
    this->Salud = Salud;
    this->Fuerza = Fuerza;
    this->Velocidad = Velocidad;
    this->Inteligencia = Inteligencia;
    this->Resistencia = Resistencia;
    this->leyenda = leyenda;
}

void peleador::get_name(){
    cout << nombre << endl;
}

void peleador::get_info(){
    cout << "Nombre: " << nombre << " Salud: " << Salud << " Fuerza: " << Fuerza << endl;
}
