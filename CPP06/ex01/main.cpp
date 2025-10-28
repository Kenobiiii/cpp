/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:46:23 by paromero          #+#    #+#             */
/*   Updated: 2025/10/28 08:48:08 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
	Data mis_datos;
	mis_datos.i1 = 1;
	mis_datos.i2 = 2;

	std::cout << "Mis datos: i1 = " << mis_datos.i1 << "| i2 = " << mis_datos.i2 << std::endl;
	uintptr_t mis_datos_serializados = Serializer::serialize(&mis_datos);
	std::cout << "Dirección de memoria serializada: " << mis_datos_serializados << std::endl;
	Data *mis_datos_deserializados = Serializer::deserialize(mis_datos_serializados);
	std::cout	<< "Datos deserializados: i1 = "
				<< mis_datos_deserializados->i1
				<< " | i2 = " << mis_datos_deserializados->i2 << std::endl;
}