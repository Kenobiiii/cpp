/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:43:53 by paromero          #+#    #+#             */
/*   Updated: 2025/06/02 12:50:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseFile.hpp"
#include <fstream>
#include <iostream>

ParseFile::ParseFile(std::string file, std::string s1, std::string s2){
    this->filename = file;
    this->s1 = s1;
    this->s2 = s2;
}

ParseFile::~ParseFile(){
}

std::string ParseFile::readFile()
{
    //- what is .c_str: point to the array, ifstream only accepts const char*
    std::ifstream file(this->filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << this->filename << std::endl;
        return "";
    }
    
    std::string content;
    std::string line;
    

    
    while (std::getline(file, line)) {
        content += line;
        if (!file.eof()) {
            content += "\n";
        }
    }
    
    file.close();
    return content;
}

std::string ParseFile::search_and_replace(std::string content, std::string search, std::string change)
{
    //- you must initialize result in order to add later the string
    std::string result = "";
    size_t pos = 0;
    size_t found_pos;
    
    //- "npos" is the equivalent to not found
    while ((found_pos = content.find(search, pos)) != std::string::npos)
    {
        //- add previous content
        result += content.substr(pos, found_pos - pos);
        
        //- add the second string
        result += change;
        
        //- move to the end of search, this is to prevent the find function of stoping
        pos = found_pos + search.length();
    }
    
    result += content.substr(pos);
    
    return result;
}

bool ParseFile::writeFile(std::string content)
{
    std::string output_filename = "";
    
    //- find the last position of .
    size_t last_dot = this->filename.find_last_of(".");
    
    if (last_dot != std::string::npos)
        output_filename = this->filename.substr(0, last_dot) + ".replace";
    else
        output_filename = this->filename + ".replace";
        
    //- ofstream create a file
    std::ofstream output_file(output_filename.c_str());
    
    // Verificar si se pudo crear/abrir
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not create output file " << output_filename << std::endl;
        return false;
    }
    
    output_file << content;
    
    output_file.close();
    
    std::cout << "File successfully created: " << output_filename << std::endl;
    return true;
}

void ParseFile::processFile()
{
    // 1. Leer el archivo original
    std::string content = readFile();
    
    // 2. Si no se pudo leer, salir
    if (content.empty()) {
        std::cerr << "Error: Could not read file content" << std::endl;
        return;
    }
    
    // 3. Hacer el reemplazo
    std::string modified_content = search_and_replace(content, this->s1, this->s2);
    
    // 4. Escribir el archivo nuevo
    if (!writeFile(modified_content)) {
        std::cerr << "Error: Could not write output file" << std::endl;
    }
}



