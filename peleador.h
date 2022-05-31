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
    string objetos;

public:

    peleador(string, int, int, int, int, int, string, string );
    string get_name();
    string get_info();
    int get_Salud();
    int get_Fuerza();
    int get_Velocidad();
    int get_Inteligencia();
    int get_Resistencia();
    string get_objects();
    void set_Salud(int);
    void set_Fuerza(int);
    void set_Velocidad(int);
    void set_Inteligencia(int);
    void set_Resistencia(int);
    void add_object(string);
    double desgaste(int);
    double golpe();


};


