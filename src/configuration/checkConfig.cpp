/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:21:02 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 11:28:28 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>

vectorString	configurations(std::string filename)
{
	std::fstream	fs;
	std::string		filename;
	vectorString	tmp;

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: unable to open your file");
	std::string line;
	while (std::getline(fs, line))
		tmp.push_back(line);
	fs.close();
	return (tmp);
}

bool	checkConf(std::string filename)
{
	vectorString tmp = configurations(filename);

	if (Word(*(tmp.begin()), 0) != "server" && Word(*(tmp.begin()), 1) != "{")
		throw std::runtime_error("Error : configuration file should start with \"server {\"");
	for (vectorString::const_iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if (it->find('{', 0))
		{
			if (Word(*(tmp.begin()), 0) != "server" && Word(*(tmp.begin()), 0) != "cgi"
				&& Word(*(tmp.begin()), 0) != "location")
				throw std::runtime_error("Error: configuration file");
		}
	}
	
}
