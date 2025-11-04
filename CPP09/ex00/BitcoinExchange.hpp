/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:59:26 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 12:34:33 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <climits>
#include <stdexcept>
#include <map>

class BitcoinExchange {
    private:
        std::vector<std::string>    _container;
        std::map<std::string, double> _csvContainer;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void openinput(std::string inputname);
        std::string transformLine(std::string line);
        std::string calculateMoney(std::string line);
        //!que hay que hacer?
        //! comprobar que al inicio del .txt pone date | value
        //! tenemos el .csv con todos los datos del bitcoin, y nos pasan un input.txt con varios datos
        //! hay que printear cuanto dinero tienen en base al input y el csv
        //! errores de fecha erronea, numero negativo, numero muy largo
        //! usar contenedores
        //abrir archivo.txt y usar el data.csv para los precios
};