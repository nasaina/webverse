/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:21:02 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/27 08:59:29 by nandrian         ###   ########.fr       */
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

void	validKey(std::string key)
{
	const char *ctmp[7] = {"server", "listen", "body_limit", "upload_path", "cgi", "location", "}"};
	vectorString	tmp(ctmp, ctmp + 7);
	const char *ccgi[3] = {"cgi_extension", "root_cgi", "exec_cgi"};
	vectorString	cgi(ccgi, ccgi + 3);
	const char	*clocation[5] = {"root", "index", "autoindex", "allow_methods", "return"};
	vectorString	location(clocation, clocation + 5);

	for (vectorString::const_iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if (*it == key)
			return ;
	}
	for (vectorString::const_iterator it = cgi.begin(); it != cgi.end(); it++)
	{
		if (*it == key)
			return ;
	}
	for (vectorString::const_iterator it = location.begin(); it != location.end(); it++)
	{
		if (*it == key)
			return ;
	}
	throw std::runtime_error("Error: configuration file");
}

void	checkConf(std::string filename)
{
	vectorString tmp = configurations(filename);

	if (Word((std::string)*(tmp.begin()), 0) != "server" && Word((std::string)*(tmp.begin()), 1) != "{")
		throw std::runtime_error("Error : configuration file should start with \"server {\"");
	for (vectorString::const_iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if (Word(*it, 0).size())
			validKey(Word(*it, 0));
		if (it->find('{', 0) != std::string::npos)
		{
			if (Word(*it, 0) != "server" && Word(*it, 0) != "cgi"
				&& Word(*it, 0) != "location")
				throw std::runtime_error("Error: configuration file");
			if ((Word(*it, 0) == "server" || Word(*it, 0) == "cgi") && (Word(*it, 1) != "{"))
				throw std::runtime_error("Error: configuration file");
			if ((Word(*it, 0) == "location") && (Word(*it, 2) != "{"))
				throw std::runtime_error("Error: configuration file");
		}
		if (it->find('}', 0) != std::string::npos && Word(*it, 0) != "}")
		{
			std::cout << Word(*it, 0).c_str() << std::endl;
			throw std::runtime_error("Error: configuration file");
		}
		else
		{
			if (Word(*it, 0).length() && !Word(*it, 1).size() && Word(*it, 0) != "}")
				throw std::runtime_error("Error: configuration file");
		}
		if ((Word(*it, 0) == "location") && (Word(*it, 2) != "{"))
			throw std::runtime_error("Error: configuration file");
	}
}
