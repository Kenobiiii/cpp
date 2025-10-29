/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:31:08 by paromero          #+#    #+#             */
/*   Updated: 2025/10/29 08:55:45 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T> class Array {
    private:
        T *array;
        size_t length;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        
        Array &operator=(const Array &other);
        T &operator[](unsigned int i);
        int size() const;
};

#include "Array.tpp"
