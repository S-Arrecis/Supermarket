#include <iostream>
using namespace std;

class Marca{

    //private: int id;
    private: string marca;
    //Metodos COnstructores
    public: Marca(){

    }

    public: Marca(string _marca){
        marca = _marca;
    }
    //metodos set
    public: void set_Marca(string _marca){
        marca = _marca;
    }
    //metodos get
    public: string get_Marca(){
        return marca;
    }

};