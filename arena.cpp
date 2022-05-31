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

float arena::get_Salud(){
    int pos = Salud.find("%");
    float Salud_flt = stoi(Salud.substr(0, pos));
    return 1 + (Salud_flt/100);}

float arena::get_Fuerza(){
    int pos = Fuerza.find("%");
    float Fuerza_flt = stoi(Fuerza.substr(0, pos));
    return 1 + (Fuerza_flt/100);}

float arena::get_Velocidad(){
    int pos = Velocidad.find("%");
    float Velocidad_flt = stoi(Velocidad.substr(0, pos));
    return 1 + (Velocidad_flt/100);}

float arena::get_Inteligencia(){
    int pos = Inteligencia.find("%");
    float Inteligencia_flt = stoi(Inteligencia.substr(0, pos));
    return 1 + (Inteligencia_flt/100);}

float arena::get_Resistencia(){
    int pos = Resistencia.find("%");
    float Resistencia_flt = stoi(Resistencia.substr(0, pos));
    return 1 + (Resistencia_flt/100);}