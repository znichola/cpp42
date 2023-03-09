/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:00:08 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 00:57:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

static std::string ifstream_to_string(std::ifstream &ifs);

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage : ./looserSed <filename> <str1> <str2>" << std::endl;
		return 1;
	}

	std::string	filename(av[1]);
	std::string	s1 = av[2];			// this assignemnt is the same as
	std::string s2(av[3]);			// this one

	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}
	std::ofstream	ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cout << "Failed to open output file" << std::endl;
		ifs.close();
		return 1;
	}

	std::string fileContent = ifstream_to_string(ifs);
	ifs.close();

	std::size_t	pos = 0;
	while (1)
	{
		pos = fileContent.find(s1, 0);
		if (pos == std::string::npos)
		{
			ofs << fileContent;
			break ;
		}
		else
		{
			ofs	<< fileContent.substr(0, pos) << s2;
			fileContent = fileContent.substr(pos + s1.size());
			pos = 0;
		}
	}
	ofs.close();
	std::cout << "done! check the " << filename + ".replace" << " for results." << std::endl;
	return 0;
}

static std::string ifstream_to_string(std::ifstream &ifs)
{
	std::stringstream	buffer;
	buffer << ifs.rdbuf();
	return buffer.str();
}
