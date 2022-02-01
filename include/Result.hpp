#ifndef RESULT_HPP
#define RESULT_HPP
#include <memory>
#include <string>
#include <utility>
#include <vector>

/*! Esta classe representa um resultado, um subconjunto das entradas disponíveis no arquivo fonte,
    mas apenas com as entradas que iniciam com o termo pesquisado pelo usuário.
*/
class Result {
    private:
        //! A lista com os resultados encontrados.
        std::vector<std::shared_ptr<std::pair<unsigned long, std::string>>> m_results;

    public:
        /*! Retorna a lista das palavras encontradas, ordenadas por relevância.
            @return Uma string com as palavras.
        */
        std::string results();

        /*! Adiciona um par com a palavra e o valor de seu peso no contêiner de resultados.
            @param entry Uma referência ao par peso-palavra.
        */
        void add_entry(std::shared_ptr<std::pair<unsigned long, std::string>> entry);
};
#endif //RESULT_HPP
