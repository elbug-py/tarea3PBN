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
    string get_Salud();
    string get_Fuerza();
    string get_Velocidad();
    string get_Inteligencia();
    string get_Resistencia();

};


