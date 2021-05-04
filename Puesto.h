#include <iostream>

using namespace std;

class Puesto{

    private : string id,puesto;

    public : Puesto(){

    }
    public: Puesto(string _id,string _puesto){
        id = _id;
        puesto = _puesto;
    }

    void set_Id (string _id){
        id = _id;
    }

    void set_Puesto(string _puesto){
        puesto = _puesto;
    }
    
    string get_Id(){
        return id;
    }
    string get_Puesto(){
        return puesto;
    }
};