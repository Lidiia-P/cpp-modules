/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lperekhr <lperekhr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/11 11:17:36 by lperekhr      #+#    #+#                 */
/*   Updated: 2025/12/11 11:23:56 by lperekhr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) 
{
  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      std::string textInput = argv[i];
      for (char c : textInput) // : range-based for loop is a C++11 extension
        std::cout << (char)toupper(c);
      if (argv[i] != NULL)
        std::cout << ' ';
    }
    std::cout << std::endl;
  }
  else
    std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  return 0;
}