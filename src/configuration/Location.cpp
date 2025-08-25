/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:28:32 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:35:57 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Location.hpp>

void	Location::printMap(std::ostream &os) const
{
	for (mapString::const_iterator it = _content.begin(); it != _content.end(); it++)
	{
		os << it->first << " " << it->second << std::endl;
	}
	os << std::endl;
}


std::ostream	&operator<<(std::ostream &o, const Location &other)
{
	o << "Location  " << other.getRoot() << " {" << std::endl;
	other.printMap(o);
	o << "}" << std::endl;
	return (o);
}

std::string	Location::methods(std::string tmp)
{
	std::istringstream iss(tmp);
	std::string	out;
	std::string	result;

	iss >> out;
	while (iss >> out)
	{
		result.append(out);
		result.append(" ");
	}
	return (result);
}

std::string	Location::getRoot(void) const
{
	return (_root);
}

mapString	Location::getContent(void) const
{
	return (_content);
}

Location::Location(vectorString::iterator *it)
{
	_root = Word(*(*it), 1);
	*it += 1;
	while (Word(*(*it), 0) != "}")
	{
		if (Word(*(*it), 0) == "allow_methods" || Word(*(*it), 0) == "return")
		{
			_content.insert(std::make_pair(Word(*(*it), 0), methods(*(*it))));
			*it += 1;
			continue ;
		}
		_content.insert(std::make_pair(Word(*(*it), 0), Word(*(*it), 1)));
		*it += 1;
	}
}

Location::~Location()
{
}
