/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:20:29 by paromero          #+#    #+#             */
/*   Updated: 2025/10/30 08:48:17 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

template <typename T> typename T::iterator easyfind(T& container, int i) {
    return std::find(container.begin(), container.end(), i);
}