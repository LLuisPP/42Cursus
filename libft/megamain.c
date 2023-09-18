/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megamain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:11:10 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/18 08:30:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

int	main(void)
{


	/*IS ALPHA*/
	printf("IS ALPHA------IS ALPHA-------IS ALPHA------IS ALPHA-----%c", '\n');
	printf("ORIGINAL > isalpha (0 = null) ===> %d, %c", isalpha(0), '\n');
	printf("LIB   > ft_isalpha (0 = null) ===> %d, %c", ft_isalpha(0), '\n');
	printf("ORIGINAL > isalpha (62 = b) ===> %d, %c", isalpha(62), '\n');
	printf("LIB   > ft_isalpha (62 = b) ===> %d, %c", ft_isalpha(62), '\n');
	printf("ORIGINAL > ft_isalpha (29 = )) ===> %d, %c", isalpha(29), '\n');
	printf("LIB      > ft_isalpha (29 = )) ===> %d, %c", ft_isalpha(29), '\n');
	printf("ORIGINAL > ft_isalpha (300 = )) ===> %d, %c", isalpha(300), '\n');
	printf("LIB      > ft_isalpha (300 = )) ===> %d, %c", ft_isalpha(300), '\n');
	/*IS ALPHA END*/

	/*TO UPPER*/
	printf("TO UPPER -------TO UPPER--------TO UPPER--------TO UPPE---%c", '\n');
	printf("ORIGINAL > toupper (0 = null) ===> %d, %c", toupper(0), '\n');
	printf("LIB   > ft_itoupper (0 = null) ===> %d, %c", ft_toupper(0), '\n');
	printf("ORIGINAL > toupper (62 = b) ===> %d, %c", toupper(62), '\n');
	printf("LIB   > ft_toupper (62 = b) ===> %d, %c", ft_toupper(62), '\n');
	printf("ORIGINAL > toupper (29 = )) ===> %d, %c", toupper(29), '\n');
	printf("LIB      > ft_toupper (29 = )) ===> %d, %c", ft_toupper(29), '\n');
	printf("ORIGINAL > toupper (300 = )) ===> %d, %c", toupper(300), '\n');
	printf("LIB      > ft_toupper (300 = )) ===> %d, %c", ft_toupper(300), '\n');
	/*TO UPPER END */

	/*IS DIGIT*/
	printf("IS DIGIT-----IS DIGIT------IS DIGIT--------IS DIGIT-------%c", '\n');
	printf("ORIGINAL > isdigit (0 = null) ===> %d, %c", isdigit(0), '\n');
	printf("LIB   > ft_isdigit (0 = null) ===> %d, %c", ft_isdigit(0), '\n');
	printf("ORIGINAL > isdigit (62 = b) ===> %d, %c", isdigit(62), '\n');
	printf("LIB   > ft_isdigit (62 = b) ===> %d, %c", ft_isdigit(62), '\n');
	printf("ORIGINAL > isdigit (29 = )) ===> %d, %c", isdigit(29), '\n');
	printf("LIB      > ft_isdigit (29 = )) ===> %d, %c", ft_isdigit(29), '\n');
	printf("ORIGINAL > isdigit (300 = )) ===> %d, %c", isdigit(300), '\n');
	printf("LIB      > ft_isdigit (300 = )) ===> %d, %c", ft_isdigit(300), '\n');
	/*IS DIGIT */

	return(0);
}

/* int main(int argc, char argv**)*/
