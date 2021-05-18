#include <iostream>

using namespace std;

class Puesto{

    private : string puesto;

    public : Puesto(){

    }
    public: Puesto(string _puesto){
        puesto = _puesto;
    }


    void set_Puesto(string _puesto){
        puesto = _puesto;
    }
    
    string get_Puesto(){
        return puesto;
    }
};
