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
string objeto::get_Salud(){return Salud;}
string objeto::get_Fuerza(){return Fuerza;}
string objeto::get_Velocidad(){return Velocidad;}
string objeto::get_Inteligencia(){return Inteligencia;}
string objeto::get_Resistencia(){return Resistencia;}

//CUANDO HAGA EL SET CONVERTIR LOS VALORES STRING A STOI() Y LUEGOA DECIMALES DIVIDIENDO EN 100
//SI HAY UN - LO REOTRNO MULTIPLICADO POR -1