#include <iostream>
#include <string>

int help(){
    std::cout << "Flag Help Ativada\n";
    return 1;
}

int main(int argc, char* argv[]){

    if(argc < 2){
        std::cerr << "ERRO: Não há argumentos\n";
        return 1;
    };

    std::string arquivo;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        // std::cout << "arg count: " << i << " | arg: " << arg << '\n';

        if(i == 1){
            std::string first = arg.substr(0, 1); 
            // std::cout << "Conteúdo de FIRST: " << first << '\n';
            if(first == "-"){
                if(i == 1 && arg == "-h"){
                    help();
                    return 1;
                }
            }
            
            /* é necessário checar se o tamanho do argumento é apropriado senão o comportamento é 
            * dado como indefinido, não satisfazendo os parâmetros da função substr(index_reference) 
            * (captura os caractêres a partir do índice definido) */
            if (arg.size() > 4) {
                std::string last = arg.substr(arg.size() - 3);
                // std::cout << "Conteúdo de LAST: " << last << '\n';
                if(i == 1 &&  last == ".md"){
                    arquivo = arg;
                    std::cout << "Arquivo Encontrado\n";
                    return 1;
                }
            }
        }

        if(i == 2){
            std::cerr << "ERRO: Argumento inesperado\n";
            return 1;
        }
    }
    return 0;
}