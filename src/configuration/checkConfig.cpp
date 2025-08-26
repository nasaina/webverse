/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:21:02 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 11:48:52 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>

vectorString	configurations(std::string filename)
{
	std::fstream	fs;
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

void	checkConf(std::string filename)
{
	vectorString tmp = configurations(filename);

	if (Word((std::string)*(tmp.begin()), 0) != "server" && Word((std::string)*(tmp.begin()), 1) != "{")
		throw std::runtime_error("Error : configuration file should start with \"server {\"");
	for (vectorString::const_iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if (it->find('{', 0) != std::string::npos)
		{
			if (Word(*it, 0) != "server" && Word(*it, 0) != "cgi"
				&& Word(*it, 0) != "location" && (Word(*it, 1) != "}" || Word(*it, 2) != "}"))
				throw std::runtime_error("Error: configuration file");
		}
		if (it->find('}', 0) != std::string::npos && Word(*it, 0) != "}")
		{
			std::cout << Word(*it, 0).c_str() << std::endl;
			throw std::runtime_error("Error: configuration file");
		}
	}
}
