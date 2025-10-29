/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:05:44 by paromero          #+#    #+#             */
/*   Updated: 2025/10/29 08:11:33 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void swap(T &x, T &y) {
    T tmp;
    
    tmp = x;
    x = y;
    y = tmp;
}

template <typename T> T min(T x, T y) {
    if (x < y)
        return x;
    return y;
}

template <typename T> T max(T x, T y) {
    if (x > y)
        return x;
    return y;
}