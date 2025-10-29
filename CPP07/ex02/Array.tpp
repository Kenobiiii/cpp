/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:36:09 by paromero          #+#    #+#             */
/*   Updated: 2025/10/29 08:55:20 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array()
{
	array = new T[0];
	length = 0;
}

template <typename T> Array<T>::Array(unsigned int n)
{
	array = new T[n];
	length = n;
}

template <typename T> Array<T>::Array(const Array<T> &other)
{
	array = new T[other.length];
	length = other.length;
    for (size_t i = 0; i < length; i++)
        array[i] = other.array[i];
}

template <typename T> Array<T>::~Array() {
    delete[] array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        delete[] array;
        array = new T[other.length];
        length = other.length;
        for (size_t i = 0; i < length; i++)
            array[i] = other.array[i];
    }
    return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int i) {
    if (i >= length)
        throw std::out_of_range("Index out of bounds");
    return array[i];
}

template <typename T> int Array<T>::size() const {
    return  static_cast<int>(length);
}