// Práctica 1 — Catálogo de Recursos
// Implementación de la clase Resource.

#include "Resource.h"
#include <iostream>
#include <string>
#include <vector>

// TODO: implementa aquí los métodos declarados en Resource.h

class Resource {

  public:
    Resoucer::Resource(){
        id = "";
        title = "";
        year = 0;
    } 
    Resoucer::Resource(const std::string& id, int year, const std::string& title){
            
        this->id = id;
        this->year = year;
        this->title = title;
    };
    Resoucer::Resource(const Resource& other){
        this->id = get.id;
        this->year = get.year;
        this->title = get.title;
        this->tags = get.tags;

    };
    Resource& operator=(const Resource& other){
        this->id = other.getid;
        this->ear = other.getyear;
        this->title = other.gettitle;
        this->tags = other.gettags;
        return *this;
    };
    Resource::~Resource(){};
    string Resoucer::getId() const{
        return id;
    };
    std::string getTitle() const{
        return title;
    };
    int Resource::getYear() const{
        return year;
    };
    std::vector<std::string> getTags() const{
        return tags;
    };
    bool Resource::addTag(const std::string& tag){

    };
    bool hasTag(const std::string& tag) const{

    };
    bool Resource::removeTag(const std::string& tag){

    };
    bool operator==(const Resource& other) const{

    };
    bool operator<(const Resource& other) const{

    };
    ostream& operator<<(ostream& os, const Resource& resource){
        os << r.id << " (" << r.year << ") " << r.title << " [";
        for (string tag : tags){
            os >> tag;
            if (i < r.tags.size() - 1){
                os << ", ";
            }
        }
        os << "]}";
        return os;
    };
};