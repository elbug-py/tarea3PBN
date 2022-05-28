#include"peleador.h"
#include <iostream>
#include <string>
#include <cmath>

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

string peleador::get_name(){
    cout << nombre << endl;
    return nombre;
}

void peleador::get_info(){
    cout << "Nombre: " << nombre << " Salud: " << Salud << " Fuerza: " << Fuerza << " Velocidad: " << Velocidad << " Inteligencia: "<< Inteligencia << " Resistencia: " << Resistencia << " Leyenda: " << leyenda << endl;
}


void peleador::set_Salud(int Salud) {this->Salud=Salud;}

void peleador::set_Fuerza(int Fuerza) {this->Fuerza=Fuerza;}

void peleador::set_Velocidad(int Velocidad) {this->Velocidad=Velocidad;}

void peleador::set_Inteligencia(int Inteligencia) {this->Inteligencia=Inteligencia;}

void peleador::set_Resistencia(int Resistencia) {this->Resistencia=Resistencia;}


int peleador::get_Salud(){return this->Salud;}

int peleador::get_Fuerza(){return this->Fuerza;}

int peleador::get_Velocidad(){return this->Velocidad;}

int peleador::get_Inteligencia(){return this->Inteligencia;}

int peleador::get_Resistencia(){return this->Resistencia;}

double peleador::desgaste(int Turno){
    if (Resistencia == 0) set_Resistencia(this->Resistencia + 1);
    double frac = 20*Turno/Resistencia;
    return (exp(frac*-1))*(1+frac);
    }

double peleador::golpe(){
    double frac = Velocidad * Fuerza / (Velocidad + Fuerza);
    double punch = frac + Inteligencia; //RECORDAR MULTIPLICAR ESTO POR desgaste(turno) Y POR EL NUMERO RANDOM
    return punch;
}