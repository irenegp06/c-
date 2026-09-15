// Práctica 1 — Catálogo de Recursos
// Implementación del TAD Catalog.

#include "Catalog.h"
#include <algorithm>
#include <fstream>

    Catalog::Catalog(){

    };
    Catalog::Catalog(const Catalog& other){

    };
    Catalog& Catalog::operator=(const Catalog& other){
        if(this !=&other){
            data = other.data;
        }
        return *this;
    };
    Catalog::~Catalog(){};//Depurador
    bool Catalog::add(const Resource& r){ //Añade el recurso si su id no está vacío y no existe otro igual.Devuelve true si se añade, false si no
        if(r.getId().empty()) //Si esta vacio
            return false;
        for (size_t i = 0; i< data.size(); i++){
            if(data[i] == r) return false; //Existe otro igual
        }
        data.push_back(r); //Se añade
        return true;


    };
    Resource Catalog::findById(const string& id) const{
        for(size_t i = 0; i < data.size(); i++){
            if(data[i].getId() == id) return data[i]; //Devuelve el recurso si existe, o un nuevo recurso vacío
        }
        return Resource();
    };
    bool Catalog::removeById(const string& id){ //Elimina el recurso con ese identificador
        for (size_t i = 0; i<data.size();++i){
            if ( data[i].getId()==id){
                data.erase(data.begin() +1);
                return true; //Devuelve true si se elimina
            }

        }return false; //Devuelve falso si no existe 
    };
    vector<Resource> findByTag(const string& tag) const{ //REVISAR TRANQUILAMENTE EN CASA ESTA PARTE
        vector<Resource> result;
        for(size_t i = 0; i < data.size(); i++){
            if (data[i].hasTag(tag)) result.push_back(data[i]); //Devuelve los recursos que contienen esa etiqueta,
            //ordenados según la relación de orden que establece el operator< de Resource.
        }
            sort(result.begin(), result.end());
            return result;
        
    };


    int Catalog::size() const{
        return static_cast<int>(data.size()); //Devuelve el número de recursos almacenados
    };

    bool Catalog::loadFromFile(const string& filename){
        ifstream file(filename.c_str());//Abre el fichero
        if(!file.is_open()) return false;//Si falla: devuelve false

        data.clear(); //Limpiamos todo

        string line;
        while(getline(file,line)){ //Lee línea a línea
            int sepCount = 0;
            for (size_t i= 0; i<line.size(); i++){
                if (line[i] == '|') sepCount;
            }
            //Aqui ya me perdi....
        }
    };
