/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:24:38 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 20:15:01 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &str) {
    std::istringstream iss(str);
    std::string token;
    
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (this->_stack.size() < 2)
                throw std::runtime_error("Error");
            
            int b = this->_stack.top();
            this->_stack.pop();
            int a = this->_stack.top();
            this->_stack.pop();
            int result;
            
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error");
                result = a / b;
            }
            
            this->_stack.push(result);
        } 
        else {
            std::istringstream converter(token);
            int num;
            if (!(converter >> num))
                throw std::runtime_error("Error");
            this->_stack.push(num);
        }
    }
    
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error");
}

RPN::~RPN() {
}

RPN::RPN(const RPN &other) {
    this->_stack = other._stack;
}

RPN     &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

int     RPN::getResult() const {
    return this->_stack.top();
}