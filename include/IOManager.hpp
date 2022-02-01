#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP
#include <string>

//! Essa classe gerencia todas as interações com o usuário.
class IOManager {
    public:
        /*! Retorna o termo de busca inserido pelo usuário pela entrada padrão.
            @return O termo de busca.
        */
        std::string input_term();

        /*! Imprime na saída padrão a lista de resultados.
            @param result A lista de resultados.
        */
        void print(std::string result);

        /*! Imprime as possíveis saídas de erros do sistema.
            @param code Um número interno indicando um erro.
            @return Código de erro do sistema.
        */
        unsigned error(unsigned code);

        //! Exibe uma mensagem de saída para o usuário.
        void close();
};
#endif //IOMANAGER_HPP
