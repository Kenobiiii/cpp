/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:17:14 by paromero          #+#    #+#             */
/*   Updated: 2025/06/02 10:49:30 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSEFILE_HPP
# define PARSEFILE_HPP

# include <iostream>
# include <fstream>
# include <string>

class ParseFile {
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        
    public:
        ParseFile(std::string file, std::string s1, std::string s2);
        ~ParseFile();
        
        std::string readFile();
        std::string search_and_replace(std::string content, std::string search, std::string change);
        bool writeFile(std::string content);
        void processFile();
};

#endif
