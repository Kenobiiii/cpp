/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:00:52 by paromero          #+#    #+#             */
/*   Updated: 2025/10/30 10:08:53 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <climits>
#include <stdexcept>

class Span {
    private:
        unsigned int        _maxSize;
        std::vector<int>    _container;

    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);

        void    addNumber(int i);
        int     shortestSpan() const;
        int     longestSpan() const;
};