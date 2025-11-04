/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:21:09 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 20:19:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <climits>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<int>     _stack;
    
    public:
        RPN(const std::string &line);
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);

        int getResult() const;
};