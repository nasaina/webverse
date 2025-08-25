/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:30 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:43:04 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>

std::string	trimSpace(std::string tmp)
{
	size_t	i;

	i = 0;
	while (i < tmp.length() && (isspace(tmp[i]) || tmp[i] == '\t'))
		i++;
	if (tmp[i] == 'c')
		return (tmp.substr(i, 3));
	if (tmp[i] == 'l')
		return (tmp.substr(i, 8));
	if (tmp[i] == 's')
		return (tmp.substr(i, 6));
	return ("");
}

bool	checkBrace(std::string tmp)
{
	int	brace = 0;

	if (tmp.substr(0, tmp.find('\n', 0)) != "server {")
		return (0);
	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '{')
			brace++;
		if (tmp[i] == '}')
			brace--;
		if (brace < 0)
			return (0);
	}
	if (brace)
		return (0);
	return (1);
}

std::string	Word(std::string &word, int index)
{
	std::istringstream	iss(word);
	std::string			first;
	std::string			second;
	std::string			third;

	iss >> first;
	iss >> second;
	iss >> third;
	if (index == 1)
		return (second);
	if (index == 2)
		return (third);
	return (first);
}

mapString	checkCgi(vectorString::iterator *it)
{
	mapString	tmp;

	*it += 1;
	while (Word(*(*it), 0) != "}")
	{
		tmp.insert(std::make_pair(Word(*(*it), 0), Word(*(*it), 1)));
		*it += 1;
	}
	return (tmp);
}

std::vector<vectorString>	getArg(char *av)
{
	std::fstream				fs;
	std::string					filename = (std::string)av;
	std::string					tmp;
	vectorString				cTmp;
	std::vector<vectorString>	config;

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: unable to open your file");
	std::string line;
	while (std::getline(fs, line))
	{
		tmp.append(line);
		if (line[line.length() - 1] == '{')
		{
			if (trimSpace(line) != "server" && trimSpace(line) != "location" && trimSpace(line) != "cgi")
				throw std::runtime_error("Error: config should start with \"server {\"");
		}
		cTmp.push_back(line);
		tmp.append("\n");
	}
	if (!checkBrace(tmp))
		throw std::runtime_error("Error: config should start with \"server {\"");
	config = getServer(cTmp);
	fs.close();
	return (config);
}
