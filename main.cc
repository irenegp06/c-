// Práctica 1 — Catálogo de Recursos
// Aplicación de línea de comandos (Sección 6 del enunciado).
//
// Lee comandos de la entrada estándar y escribe el resultado
// en la salida estándar, sin prompts ni mensajes adicionales.

#include <iostream>
#include <sstream>
#include <string>

#include "Catalog.h"

using namespace std;

int main() {
    Catalog catalog;
    string line;

    while (getline(cin, line)) { //Puros if, elses.....
        istringstream iss(line);
        string command;
        if (!(iss >> command)) {
            continue;   // línea vacía
        }

        if (command == "EXIT") {
            break;
        } else if (command == "LOAD"){
            string filename;
            if(!(iss >> filename)){
                cout << "INVALIDCMD" << "\n";
                continue;
            }
            if (catalog.loadFromFile(filename)){
                cout << "OK" << catalog.size()<< "\n";
            }else{
                cout << "ERROR" << "\n";
            }
        }
        else if ( commad == "ADD"){
            string id, title, tags;
            int year;
            if (!(iss >> id >> year >> title >> tags)){
                cout << "INVALIDCM" << "\n";
                continue;
            }
            string title = replaceUnderscores(titleRaw);
            Resource r(id, year, title);
            if(tagsStr != "-"){
                istringstream tss(tagsStr);
                string tag;
                while (getline(tss, tag, ',')){
                    r.addTag(tag);
                }
            }
            if (catalog.add(r)){
                cout << "OK" << "\n"
            }else{
                cout << "DUPLICATE" << "\n";
            }
        }
        else if ( command == "DEL"){
            string id;
            if(!(iss>>id)){
                cout << "INVALIDCMD" << "\n";
                continue;
            }
            if (catalog.removeById(id)){
                 cout << "OK" << "\n"
            }else{
                cout << "NOTFOUND" << "\n";
            }
            
        }else if (command == "GET"){
            string id;
            if(!(iss>>id)){
                cout << "INVALIDCM" << "\n";
                continue;
            }
            Resource r = catalog.findById(id);
            if (r.getId().empty()){
                cout << "NOTFOUND" << "\n";
               
            }else{
                cout << r << "\n";
                continue;
            }
            vector<Resource> results = catalog.findByIdTag(tag);
            cout << "COUNT" << results.size() << "\n";
            for (size_t i = 0; i < result.size(); ++i){
                cout << results [i] << "\n";
            }   
        }else{
            cout << "INVALIDCM" << "\n";
        }

        // TODO: procesa el resto de comandos (LOAD, ADD, DEL, GET, FINDTAG)
        // Recuerda: si el comando no existe o faltan argumentos -> INVALIDCMD
    }

    return 0;
}
