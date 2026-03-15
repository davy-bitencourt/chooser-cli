#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    if(argc < 2){
        std::cerr << "ERRO: Não há argumentos\n";
        return 1;
    };

    bool help = false;
    std::string arquivo;
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];

        if(arg == "-h" || arg == "--help"){
            help = true;
        }

        // if(arquivo.empty()){
        //     arquivo = arg;
        // } else {
        //     std::cerr << "ERRO: Argumento inesperado\n";
        //     return 1;
        // }
    }

    if(help){
        std::cout << "Flag Help Ativada\n";
        return 1;
    };

    return 0;
}