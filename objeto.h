#include <string>

using namespace std;

class objeto
{
private:
    string nombre;
    string tipo;
    string Salud; 
    string Fuerza; 
    string Velocidad;
    string Inteligencia;
    string Resistencia; 
    string leyenda;

public:
    objeto(string, string, string, string, string, string, string, string );
    void get_info();
    string get_name();
    int get_Salud();
    float get_Fuerza();
    float get_Velocidad();
    float get_Inteligencia();
    float get_Resistencia();

};


