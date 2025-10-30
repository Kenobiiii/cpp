/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:44:07 by paromero          #+#    #+#             */
/*   Updated: 2025/10/30 11:51:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::~Span() {
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _container(other._container) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_container = other._container;
        this->_maxSize = other._maxSize;
    }
    return *this;
}

void    Span::addNumber(int i) {
    if (this->_container.size() == this->_maxSize)
        throw std::out_of_range("Span is full");
    this->_container.push_back(i);
}

int Span::shortestSpan() const {
    if (_container.size() < 2)
        throw std::logic_error("Not enough elements for a span");

    std::vector<int>    tmp = this->_container;
    std::sort(tmp.begin(), tmp.end());
    int mindiff = INT_MAX;
    int diff = 0;
    for (size_t i = 0; i < tmp.size() -1; i++) {
        diff = tmp[i + 1] - tmp[i];
        if (diff < mindiff)
            mindiff = diff;
    }
    return mindiff;
}

int Span::longestSpan() const {
    if (_container.size() < 2)
        throw std::logic_error("Not enough elements for a span");
 
    std::vector<int>    tmp = this->_container;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();       
}