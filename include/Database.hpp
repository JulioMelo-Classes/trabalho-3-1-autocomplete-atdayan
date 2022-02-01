#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Result.hpp"

/*! Esta classe representa a base de dados do sistema, processa o arquivo de entradas
    e as armazena, bem como realiza as buscas.
*/
class Database {
    private:
        //! Lista com todas as entradas peso-palavra do arquivo fonte.
        std::vector<std::shared_ptr<std::pair<unsigned long, std::string>>> m_entries;

    public:
        /*! Realiza a leitura e processamento do arquivo que contém as palavras e seus pesos,
            e informa se esse procedimento foi bem sucedido ou não.
            @param filename O caminho para o arquivo.
            @return Um booleano informando se a leitura foi realizada.
        */
        bool read_file(std::string filename);

        /*! Executa a pesquisa na lista de entradas a partir do trecho informado pelo usuário,
            retornando essa faixa de pares peso-palavra em um objeto do tipo Resultado.
            @param search_term O termo de busca.
            @return Uma referência para Resultado.
        */
        std::unique_ptr<Result> query(std::string search_term);
};
#endif //DATABASE_HPP
