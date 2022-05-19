#include <string>

using namespace std;

class peleador
{
private:
    string nombre;
    int Salud; 
    int Fuerza; 
    int Velocidad;
    int Inteligencia;
    int Resistencia; 
    string leyenda;

public:

    peleador(string, int, int, int, int, int, string );
    void get_name();
    void get_info();

};


