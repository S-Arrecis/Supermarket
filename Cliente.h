#include "Persona.h"

class Cliente:Persona{

    private : string nit,correo;

    public: Cliente():Persona(){

    }
    
    public:
            Cliente(string _nombres,string _apellidos,string _telefono,string _fecha_ingreso,char _genero,string _nit,string _correo):Persona(_nombres,_apellidos,_telefono,_fecha_ingreso,_genero){

                nit = _nit;
                correo = _correo;
            }

};