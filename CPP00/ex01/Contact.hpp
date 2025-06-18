/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/17 12:08:54 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class   Contact
{
    private:
        std::string	name_;
		std::string	surname_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	darkestSecret_;
    public:
        // Constructor
        Contact();
        // Destructor
        ~Contact();
        
        // Setters (modify the private vars)
        void setName(const std::string& name);
        void setSurname(const std::string& surname);
        void setNickname(const std::string& nickname);
        void setPhoneNumber(const std::string& phoneNumber);
        void setDarkestSecret(const std::string& darkestSecret);
        
        // Getters (gets the private vars)
        std::string getName() const;
        std::string getSurname() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        
        // Utility functions
        void displayContact() const;
        std::string truncateField(const std::string& field) const;
};

#endif