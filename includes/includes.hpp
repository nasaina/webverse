/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:06 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/22 17:27:40 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_HPP
# define INCLUDES_HPP

# include <iostream>
# include <map>
# include <vector>
# include <fstream>
# include <sstream>
# include <cstdlib>

typedef std::map<std::string, std::string>	mapString;
typedef	std::vector<std::string>			vectorString;

std::string	Word(std::string &word, int index);
bool		checkBrace(std::string tmp);
std::vector<vectorString>	getServer(vectorString &tmp);

#endif