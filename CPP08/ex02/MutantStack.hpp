/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:58:43 by paromero          #+#    #+#             */
/*   Updated: 2025/10/30 12:55:00 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <stack>

template <typename T> class   MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        ~MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        //! que significa lo de arriba?¿ typedef crea un alias para poder usar mas facil lo que viene luego
        //! typename le indica al compilador que es un tipo y no una funcion ni variable 
        //! std::stack<T>::container_type::iterator usamos el iterador que está dentro del container que a su vez está dentro de stack, puesto que stack no tiene iterador
        //! iterator es el alias de typedef ej typedef <lo que queremos sustituir> "nombre a sustituir para acortar"
        iterator   begin() {
            return this->c.begin();
        }
        iterator   end() {
            return this->c.end();
        }
};