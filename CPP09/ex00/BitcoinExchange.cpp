/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:33:49 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 11:18:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_container = other._container;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_container = other._container;
    return *this;
}

static  bool esBisiesto(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static  std::string dateVerifier(std::string date) {
    int year_;
    int month_;
    int day_;
    static int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::stringstream ssyear(date.substr(0, 4));
    ssyear >> year_;
    std::stringstream ssmonth(date.substr(5, 2));
    ssmonth >> month_;
    std::stringstream ssday(date.substr(8, 2));
    ssday >> day_;
    if (date[4] != '-' || date[7] != '-')
        return "Invalid date";
    if (year_ < 2009 || year_ > 2022)
        return "Invalid year";
    if (month_ < 1 || month_ > 12 || (year_ == 2022 && month_ > 3))
        return "Invalid month";
    if (year_ == 2009 && month_ == 1 && day_ < 2)
        return "Invalid day, too early";
    if (year_ == 2022 && (month_ > 3 || (month_ == 3 && day_ > 29)))
        return "Invalid day, too late";
    int maxDay = daysInMonth[month_ - 1];
    if (month_ == 2 && esBisiesto(year_))
        maxDay = 29;
    if (day_ < 1 || day_ > maxDay)
        return "Invalid day";
    return date;
}
static  std::string transformLine(std::string line) {
    std::string Date;
    std::string Value;
    std::string newLine;

    if (line[0] < 48 || line[0] > 57)
        return "doesn't start with a date";
    if (line.find(' ') != 10)
        return "Invalid date";
    line = dateVerifier(line);
    std::cout << "Linea: " << line << std::endl;
    
    //! Limites de fecha 2009.1.02 - 2022.03.29
    return line;
}

void    BitcoinExchange::openinput(std::string inputname) {
    std::ifstream file(inputname.c_str());

    if (!file.is_open())
    {
        std::cerr << "Couldn't open the file" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        this->_container.push_back(transformLine(line));
        if (!file.eof())
        this->_container.push_back("\n");
    }
}