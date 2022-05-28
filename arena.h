#include <string>

using namespace std;

class arena
{
private:
    string nombre;
    string Salud; 
    string Fuerza; 
    string Velocidad;
    string Inteligencia;
    string Resistencia; 
    string leyenda;

public:
    arena(string, string, string, string, string, string, string );
    void get_info();
    string get_name();

};