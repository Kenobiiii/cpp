/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:02 by paromero          #+#    #+#             */
/*   Updated: 2025/10/29 08:56:12 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a(3);
        for (int i = 0; i < a.size(); i++)
            a[i] = i + 1;

        std::cout << "Array a: ";
        for (int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;
        b[0] = 42;
        std::cout << "Array b (copia modificada): ";
        for (int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Array a (original): ";
        for (int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Intentando acceder a índice fuera de rango..." << std::endl;
        std::cout << a[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}