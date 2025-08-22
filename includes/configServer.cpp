/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configServer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:31:09 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/22 17:38:14 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <configServer.hpp>

std::string	eraseSpace(std::string tmp)
{
	std::string	out = "";

	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == ' ' || tmp[i] == '\t')
			continue ;
		out.append(tmp, i, 1);
	}
	return (out);
}

void	countBrace(std::string tmp, int *brace)
{
	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '{')
			*brace += 1;
		if (tmp[i] == '}')
			*brace -= 1;
	}
}

int	countServer(vectorString &tmp)
{
	vectorString::iterator	it;
	int									count = 0;

	it = tmp.begin();
	while (it != tmp.end())
	{
		if (eraseSpace(*it) == "server{")
			count++;
		it++;
	}
	return (count);
}

std::vector<vectorString>	getServer(vectorString &tmp)
{
	vectorString::iterator	it;
	std::vector<vectorString>	in;
	std::string							str;
	int									brace;
	size_t								count;
	
	it = tmp.begin();
	count = countServer(tmp);
	brace = 0;
	for (size_t i = 0; i < count; i++)
	{
		str = "";
		vectorString			out;
		while (it != tmp.end())
		{
			if (eraseSpace(*it).length() == 0)
			{
				it++;
				continue ;
			}
			countBrace(*it, &brace);
			out.push_back(*it);
			if (!brace)
			{
				it++;
				break ;
			}
			it++;
		}
		in.push_back(out);
	}
	return (in);
}

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

void	configServer::getElement(std::vector<vectorString>::iterator it)
{
	for (vectorString::iterator strIt = (*it).begin(); strIt != (*it).end(); strIt++)
	{
		std::string	second = Word(*strIt, 1);
		if (Word(*strIt, 0) == "listen")
			_port = second;
		else if (Word(*strIt, 0) == "body_limit")
			_bodyLimit = std::atoi(second.c_str());
		else if (Word(*strIt, 0) == "upload_path")
			_uploadPath.insert(std::make_pair(second, Word(*strIt, 2)));
		else if (Word(*strIt, 0) == "cgi" && Word(*strIt, 1) == "{")
			_cgi = checkCgi(&strIt);
		else if (Word(*strIt, 0) == "location" && Word(*strIt, 2) == "{")
		{
			Location tmp(&strIt);
			_location.push_back(tmp);
		}
	}
}

configServer::configServer(std::vector<vectorString>::iterator it)
{
	getElement(it);
}

std::string	configServer::getPort(void) const
{
	return (_port);
}

size_t	configServer::getLimit(void) const
{
	return (_bodyLimit);
}

mapString	configServer::getPath(void) const
{
	return (_uploadPath);
}

mapString	configServer::getCgi(void) const
{
	return (_cgi);
}

std::vector<Location>	configServer::getLocation(void) const
{
	return (_location);
}

void	configServer::printLocation(std::ostream &os) const
{
	for (std::vector<Location>::const_iterator it = _location.begin(); it != _location.end(); it++)
	{
		os << *it;
	}
}

void	configServer::printMap(std::ostream &os) const
{
	os << std::endl << "upload_path : ";
	for (mapString::const_iterator it = _uploadPath.begin(); it != _uploadPath.end(); it++)
	{
		os << it->first << " " << it->second;
	}
	os << std::endl;
	os << "cgi : {" << std::endl;
	for (mapString::const_iterator it = _cgi.begin(); it != _cgi.end(); it++)
	{
		os << it->first << " : " << it->second << std::endl;
	}
	os << "}" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, const configServer &other)
{
	o << "port : " << other.getPort();
	o << ", body limit : " << other.getLimit();
	other.printMap(o);
	other.printLocation(o);
	return (o);
}

configServer::~configServer()
{
}
