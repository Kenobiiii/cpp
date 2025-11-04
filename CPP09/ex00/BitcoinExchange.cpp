/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:33:49 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 12:43:06 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Couldn't open the file" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line != "date,exchange_rate" && line.length() > 11) {
            double value;
            std::stringstream ssvalue(line.substr(11));
            ssvalue >> value;
            this->_csvContainer.insert(std::make_pair(line.substr(0, 10), value));
        }
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_container = other._container;
    this->_csvContainer = other._csvContainer;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_container = other._container;
        this->_csvContainer = other._csvContainer;
    }
    return *this;
}

static  bool esBisiesto(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static  std::string dateVerifier(std::string line) {
    int year_;
    int month_;
    int day_;
    static int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::stringstream ssyear(line.substr(0, 4));
    ssyear >> year_;
    std::stringstream ssmonth(line.substr(5, 2));
    ssmonth >> month_;
    std::stringstream ssday(line.substr(8, 2));
    ssday >> day_;
    if (line[4] != '-' || line[7] != '-')
        return "Error: bad input => " + line.substr(0, 10);
    if (year_ < 2009 || year_ > 2022)
        return "Error: bad input => " + line.substr(0, 10);
    if (month_ < 1 || month_ > 12 || (year_ == 2022 && month_ > 3))
        return "Error: bad input => " + line.substr(0, 10);
    if (year_ == 2009 && month_ == 1 && day_ < 2)
        return "Error: bad input => " + line.substr(0, 10);
    if (year_ == 2022 && (month_ > 3 || (month_ == 3 && day_ > 29)))
        return "Error: bad input => " + line.substr(0, 10);
    int maxDay = daysInMonth[month_ - 1];
    if (month_ == 2 && esBisiesto(year_))
        maxDay = 29;
    if (day_ < 1 || day_ > maxDay)
        return "Error: bad input => " + line.substr(0, 10);
    return line.substr(0, 10);
}

std::string BitcoinExchange::calculateMoney(std::string line) {
    if (line.length() < 14)
        return "Error: bad input => " + line;
    
    std::string date = line.substr(0, 10);
    std::string valueStr = line.substr(13);
    
    double bitcoinAmount;
    std::stringstream ss(valueStr);
    if (!(ss >> bitcoinAmount)) {
        return "Error: bad input => " + line;
    }
    
    if (bitcoinAmount < 0) {
        return "Error: not a positive number.";
    }
    if (bitcoinAmount > 1000) {
        return "Error: too large a number.";
    }
    
    std::map<std::string, double>::iterator it = this->_csvContainer.find(date);
    double price;
    
    if (it != this->_csvContainer.end()) {
        price = it->second;
    } else {
        it = this->_csvContainer.lower_bound(date);
        if (it == this->_csvContainer.begin()) {
            return "Error: no previous date available";
        }
        --it;
        price = it->second;
    }
    
    double result = price * bitcoinAmount;
    
    std::stringstream output;
    output << date << " => " << bitcoinAmount << " = " << result;
    
    return output.str();
}

std::string BitcoinExchange::transformLine(std::string line) {
    std::string Date;
    std::string Value;
    std::string newLine;

    if (line.length() < 14)
        return "Error: bad input => " + line;
    if (line[0] < 48 || line[0] > 57)
        return "Error: bad input => " + line;
    if (line.find(" | ") != 10)
        return "Error: bad input => " + line;
    
    std::string dateResult = dateVerifier(line);
    if (dateResult != line.substr(0, 10) && dateResult.find("Error") == 0) {
        return dateResult;
    }
    
    return calculateMoney(line);
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
        if (line.empty())
            continue;
        this->_container.push_back(transformLine(line));
    }
    file.close();
}