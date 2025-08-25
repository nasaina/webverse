/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:56:39 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:35:48 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <includes.hpp>

std::string	Word(std::string &word, int index);

class Location
{
	private:
		std::string	_root;
		mapString	_content;
		std::string	methods(std::string tmp);
	public:
		Location(vectorString::iterator *it);
		std::string	getRoot(void) const;
		mapString	getContent(void) const;
		void		printMap(std::ostream &os) const;
		~Location();
};

std::ostream	&operator<<(std::ostream &o, const Location &other);

#endif