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

int objeto::get_Salud(){
    int Salud_int = 0;
    if (Salud[0] == '+' || Salud[0] == '-'){
        Salud_int = stoi(Salud.substr(1));
        if (Salud[0] == '-') Salud_int *= -1;
        }
    else Salud_int = stoi(Salud);
    return Salud_int;}

float objeto::get_Fuerza(){
    int Fuerza_int = 0;
    if (Fuerza[0] == '+' || Fuerza[0] == '-'){
        Fuerza_int = stoi(Fuerza.substr(1));
        if (Fuerza[0] == '-') Fuerza_int *= -1;
        }
    else Fuerza_int = stoi(Fuerza);
    return Fuerza_int;}

float objeto::get_Velocidad(){
    int Velocidad_int = 0;
    if (Velocidad[0] == '+' || Velocidad[0] == '-'){
        Velocidad_int = stoi(Velocidad.substr(1));
        if (Velocidad[0] == '-') Velocidad_int *= -1;
        }
    else Velocidad_int = stoi(Velocidad);
    return Velocidad_int;}

float objeto::get_Inteligencia(){
    int Inteligencia_int = 0;
    if (Inteligencia[0] == '+' || Inteligencia[0] == '-'){
        Inteligencia_int = stoi(Inteligencia.substr(1));
        if (Inteligencia[0] == '-') Inteligencia_int *= -1;
        }
    else Inteligencia_int = stoi(Inteligencia);
    return Inteligencia_int;}

float objeto::get_Resistencia(){
    int Resistencia_int = 0;
    if (Resistencia[0] == '+' || Resistencia[0] == '-'){
        Resistencia_int = stoi(Resistencia.substr(1));
        if (Resistencia[0] == '-') Resistencia_int *= -1;
        }
    else Resistencia_int = stoi(Resistencia);
    return Resistencia_int;}

//CUANDO HAGA EL SET CONVERTIR LOS VALORES STRING A STOI() Y LUEGOA DECIMALES DIVIDIENDO EN 100
//SI HAY UN - LO REOTRNO MULTIPLICADO POR -1