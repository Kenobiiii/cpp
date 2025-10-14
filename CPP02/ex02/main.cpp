/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:48:17 by paromero          #+#    #+#             */
/*   Updated: 2025/10/14 11:09:19 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;    
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// int main(void) {
//     std::cout << "=== CONSTRUCTORES ===" << std::endl;
//     Fixed a;
//     Fixed b(10);
//     Fixed c(42.42f);
//     Fixed d(b);
    
//     std::cout << "\n=== OPERADORES DE COMPARACIÓN ===" << std::endl;
//     Fixed x(5);
//     Fixed y(10);
    
//     std::cout << "x = " << x << ", y = " << y << std::endl;
//     std::cout << "x > y: " << (x > y) << std::endl;
//     std::cout << "x < y: " << (x < y) << std::endl;
//     std::cout << "x >= y: " << (x >= y) << std::endl;
//     std::cout << "x <= y: " << (x <= y) << std::endl;
//     std::cout << "x == y: " << (x == y) << std::endl;
//     std::cout << "x != y: " << (x != y) << std::endl;
    
//     std::cout << "\n=== OPERADORES ARITMÉTICOS ===" << std::endl;
//     Fixed n1(10.5f);
//     Fixed n2(2.5f);
    
//     std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
//     std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
//     std::cout << "n1 - n2 = " << (n1 - n2) << std::endl;
//     std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;
//     std::cout << "n1 / n2 = " << (n1 / n2) << std::endl;
    
//     std::cout << "\n=== PRE-INCREMENTO/DECREMENTO ===" << std::endl;
//     Fixed counter(5);
//     std::cout << "counter inicial: " << counter << std::endl;
//     std::cout << "++counter: " << ++counter << std::endl;
//     std::cout << "counter después: " << counter << std::endl;
//     std::cout << "--counter: " << --counter << std::endl;
//     std::cout << "counter después: " << counter << std::endl;
    
//     std::cout << "\n=== POST-INCREMENTO/DECREMENTO ===" << std::endl;
//     Fixed counter2(5);
//     std::cout << "counter2 inicial: " << counter2 << std::endl;
//     std::cout << "counter2++: " << counter2++ << std::endl;
//     std::cout << "counter2 después: " << counter2 << std::endl;
//     std::cout << "counter2--: " << counter2-- << std::endl;
//     std::cout << "counter2 después: " << counter2 << std::endl;
    
//     std::cout << "\n=== MIN Y MAX (no-const) ===" << std::endl;
//     Fixed m1(42.42f);
//     Fixed m2(21.21f);
    
//     std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
//     std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
//     std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
    
//     std::cout << "\n=== MIN Y MAX (const) ===" << std::endl;
//     const Fixed cm1(100.5f);
//     const Fixed cm2(50.25f);
    
//     std::cout << "cm1 = " << cm1 << ", cm2 = " << cm2 << std::endl;
//     std::cout << "min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
//     std::cout << "max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;
    
//     std::cout << "\n=== CONVERSIONES ===" << std::endl;
//     Fixed conv(1234.4321f);
//     std::cout << "Fixed(1234.4321f) como float: " << conv.toFloat() << std::endl;
//     std::cout << "Fixed(1234.4321f) como int: " << conv.toInt() << std::endl;
    
//     std::cout << "\n=== OPERADOR DE ASIGNACIÓN ===" << std::endl;
//     Fixed assign1(10);
//     Fixed assign2(20);
//     std::cout << "assign1 = " << assign1 << ", assign2 = " << assign2 << std::endl;
//     assign1 = assign2;
//     std::cout << "Después de assign1 = assign2:" << std::endl;
//     std::cout << "assign1 = " << assign1 << ", assign2 = " << assign2 << std::endl;
    
//     std::cout << "\n=== ASIGNACIÓN EN CADENA ===" << std::endl;
//     Fixed chain1, chain2, chain3;
//     chain1 = chain2 = chain3 = Fixed(99.9f);
//     std::cout << "chain1 = " << chain1 << std::endl;
//     std::cout << "chain2 = " << chain2 << std::endl;
//     std::cout << "chain3 = " << chain3 << std::endl;
    
//     return 0;
// }