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
    cout << "Nombre: " << nombre << " Tipo: " << tipo << " Salud: " << Salud << " Fuerza: " << Fuerza << " Velocidad: " << Velocidad << " Inteligencia: "<< Inteligencia << " Resistencia: " << Resistencia << " Leyenda: " << leyenda << endl;
}

string objeto::get_name(){return nombre;}

int objeto::get_Salud(){return stoi(Salud);}

float objeto::get_Fuerza(){
    int Fuerza_int = stoi(Fuerza.substr(1));
    if(Fuerza[0] == '-') Fuerza_int = Fuerza_int*-1;
    return 1 + (Fuerza_int/100);}

float objeto::get_Velocidad(){
    int Velocidad_int = stoi(Velocidad.substr(1));
    if(Velocidad[0] == '-') Velocidad_int = Velocidad_int*-1;
    return 1 + (Velocidad_int/100);}

float objeto::get_Inteligencia(){
    int Inteligencia_int = stoi(Inteligencia);
    if(Inteligencia[0] == '-') Inteligencia_int = Inteligencia_int*-1;
    return 1 + (Inteligencia_int/100);}

float objeto::get_Resistencia(){
    int Resistencia_int = stoi(Resistencia.substr(1));
    if(Resistencia[0] == '-') Resistencia_int = Resistencia_int*-1;
    return 1 + (Resistencia_int/100);}

//CUANDO HAGA EL SET CONVERTIR LOS VALORES STRING A STOI() Y LUEGOA DECIMALES DIVIDIENDO EN 100
//SI HAY UN - LO REOTRNO MULTIPLICADO POR -1