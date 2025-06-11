/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:21 by lprieto-          #+#    #+#             */
/*   Updated: 2025/06/11 16:13:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <cctype>
// #include <string>

// int main(int argc, char **argv)
// {
//     int i;
//     int j;

//     if (argc < 2)
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
//     else {
//         i = -1;
//         while (i < argc)
//         {
//             j = 0;
//             while (argc > 1 && argv && argv[++i])
//             {
//                 j = -1;
//                 while (i > 0 && argv[i][++j])
//                 {
//                     std::cout << (char)std::toupper(argv[i][j]);
//                     std::cout << " ";
//                 }
//                 if (i < argc -1  && i != 0)
//                     std::cout << "   ";
//             }
//         }
//         std::cout << std::endl;
//     }
//     return (0);
// }


// puro C++ //

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv){
    int arg; int pos; char ch;
    if(argc < 2){
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        arg = 1;
        while(arg < argc){
            std::string s = argv[arg];
            pos = 0;
            while(pos < static_cast<int>(s.length())){
                ch = s[pos];
                if(ch >= 'a' && ch <= 'z')
                    ch = ch - 'a' + 'A';
                std::cout<<ch;
                pos++;
                if(pos < static_cast<int>(s.length()))
                    std::cout<<' ';
            }
            if(arg < argc - 1)
                std::cout<<"   ";
            arg++;
        }
    }
    std::cout<<std::endl;
    return 0;
}
