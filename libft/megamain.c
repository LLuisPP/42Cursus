/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megamain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:11:10 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/19 12:26:03 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int	main(void)
{

	/*MEMCPY*/
	printf("MEMCPY----MEMCPY---MEMCPY---MEMCPY----MEMCPY----%c", '\n');
	printf("ORIGINAL > memcpy (NULL NULL, 3) ===> %p, %c", memcpy(NULL, NULL, 3), '\n');
	printf("LIB   > ft_memcpy (NULL, NULL, 3) ===> %p, %c", ft_memcpy(NULL, NULL, 3), '\n');
//	printf("ORIGINAL > strchr (holamundo, 0) ===> %s, %c", strchr("holamundo", 0), '\n');
//	printf("LIB   > ft_strchr (holamundo, 0) ===> %s, %c", ft_strchr("holamundo", 0), '\n');
//	printf("ORIGINAL 	> strchr (holamundo, 9) ===> %s, %c", strchr("holamundo", 9), '\n');
//	printf("LIB      > ft_strchr (holamundo, 9) ===> %s, %c", ft_strchr("holamundo", 9), '\n');
//	printf("ORIGINAL > strchr (holamundo, 20) ===> %s, %c", strchr("holamundo", 20), '\n');
//	printf("LIB      > ft_strchr (holamundo, 20) ===> %s, %c", ft_strchr("holamundo", 20), '\n');
	/*TO LOWER END*/

	/*BZERO
	printf("BZERO----BZERO---BZERO---BZERO----BZERO----%c", '\n');
	printf("ORIGINAL > bzero (holamundo, -1) ===> %s, %c", bzero("holamundo", -1), '\n');
	printf("LIB   > ft_bzero (holamundo, -1) ===> %s, %c", ft_bzero("holamundo", -1), '\n');
	printf("ORIGINAL > bzero (holamundo, 0) ===> %s, %c", bzero("holamundo", 0), '\n');
	printf("LIB   > ft_bzero (holnmundo, 0) ===> %s, %c", ft_bzero("holamundo", 0), '\n');
	printf("ORIGINAL 	> bzero (holamundo, 9) ===> %s, %c", bzero("holamundo", 9), '\n');
	printf("LIB      > ft_bzero (holamundo, 9) ===> %s, %c", ft_bzero("holamundo", 9), '\n');
	printf("ORIGINAL > bzero (holamundo, 20) ===> %s, %c", bzero("holamundo", 20), '\n');
	printf("LIB      > ft_bzero (holamundo, 20) ===> %s, %c", ft_bzero("holamundo", 20), '\n');
	BZERO END */

	/*IS MEMSET
	printf("MEMSET----MEMSET----MEMSET----MEMSET----MEMESET----MEMSET----%c", '\n');
	printf("ORIGINAL > memset (holamundo, '*', 10) ===> %p, %c", memset("holamundo", 7, 9), '\n');
	printf("LIB   > ft_memset (holamundo, '10', 10) ===> %p, %c", ft_memset("holamundo", 7, 9), '\n');
	printf("ORIGINAL > memset (holamundo, 0) ===> %p, %c", memset("holamundo", 7, 9), '\n');
	printf("LIB   > ft_memset (holamundo, 0) ===> %p, %c", ft_memset("holamundo", 7, 9), '\n');
//	printf("ORIGINAL 	> memset (holamundo, 9) ===> %p, %c", memset("holamundo", 7, 19), '\n');
//	printf("LIB      > ft_memset (holamundo, 9) ===> %p, %c", ft_memset("holamundo", 10, 19), '\n');
//	printf("ORIGINAL > memset (holamundo, 20) ===> %p, %c", memset("holamundo", 7, -2), '\n');
//	printf("LIB      > ft_memset (holamundo, 20) ===> %p, %c", ft_memset("holamundo", 10, -2), '\n');
	TO MEMSET END*/

	/*IS STRCHR
	printf("STRNGCHR----STRCHR---STRCHR---STRCHR----STRCHR----%c", '\n');
	printf("ORIGINAL > strchr (holamundo, -1) ===> %s, %c", strchr("holamundo", -1), '\n');
	printf("LIB   > ft_strchr (holamundo, -1) ===> %s, %c", ft_strchr("holamundo", -1), '\n');
	printf("ORIGINAL > strchr (holamundo, 0) ===> %s, %c", strchr("holamundo", 0), '\n');
	printf("LIB   > ft_strchr (holamundo, 0) ===> %s, %c", ft_strchr("holamundo", 0), '\n');
	printf("ORIGINAL 	> strchr (holamundo, 9) ===> %s, %c", strchr("holamundo", 9), '\n');
	printf("LIB      > ft_strchr (holamundo, 9) ===> %s, %c", ft_strchr("holamundo", 9), '\n');
	printf("ORIGINAL > strchr (holamundo, 20) ===> %s, %c", strchr("holamundo", 20), '\n');
	printf("LIB      > ft_strchr (holamundo, 20) ===> %s, %c", ft_strchr("holamundo", 20), '\n');
	TO LOWER END */

	/*IS ASCII
	printf("ISACII----ISACII---ISACII---ISACII----ISACII----%c", '\n');
	printf("ORIGINAL > isascii (0 = null) ===> %d, %c", isascii('\0'), '\n');
	printf("LIB   > ft_isascii (0 = null) ===> %d, %c", ft_isascii('\0'), '\n');
	printf("ORIGINAL > isascii (62 = b) ===> %d, %c", isascii(62), '\n');
	printf("LIB   > ft_isascii (62 = b) ===> %d, %c", ft_isascii(62), '\n');
	printf("ORIGINAL > isascii (29 = )) ===> %d, %c", isascii(29), '\n');
	printf("LIB      > ft_isascii (29 = )) ===> %d, %c", ft_isascii(29), '\n');
	printf("ORIGINAL > isascii (300 = )) ===> %d, %c", isascii(300), '\n');
	printf("LIB      > ft_isascii (300 = )) ===> %d, %c", ft_isascii(300), '\n');
	TO LOWER END */
	
	/*TO LOWER
	printf("TO LOWER----TO LOWER----TO LOWER----TO LOWER----TO LOWER%c", '\n');
	printf("ORIGINAL > toupper (0 = null) ===> %d, %c", tolower(0), '\n');
	printf("LIB   > ft_itoupper (0 = null) ===> %d, %c", ft_tolower(0), '\n');
	printf("ORIGINAL > toupper (62 = b) ===> %d, %c", tolower(62), '\n');
	printf("LIB   > ft_toupper (62 = b) ===> %d, %c", ft_tolower(62), '\n');
	printf("ORIGINAL > toupper (29 = )) ===> %d, %c", tolower(29), '\n');
	printf("LIB      > ft_toupper (29 = )) ===> %d, %c", ft_tolower(29), '\n');
	printf("ORIGINAL > toupper (300 = )) ===> %d, %c", tolower(300), '\n');
	printf("LIB      > ft_toupper (300 = )) ===> %d, %c", ft_tolower(300), '\n');
	TO LOWER END */

	/*IS DIGIT
	printf("IS DIGIT-----IS DIGIT------IS DIGIT--------IS DIGIT-------%c", '\n');
	printf("ORIGINAL > isdigit (0 = null) ===> %d, %c", isdigit(0), '\n');
	printf("LIB   > ft_isdigit (0 = null) ===> %d, %c", ft_isdigit(0), '\n');
	printf("ORIGINAL > isdigit (62 = b) ===> %d, %c", isdigit(62), '\n');
	printf("LIB   > ft_isdigit (62 = b) ===> %d, %c", ft_isdigit(62), '\n');
	printf("ORIGINAL > isdigit (29 = )) ===> %d, %c", isdigit(29), '\n');
	printf("LIB      > ft_isdigit (29 = )) ===> %d, %c", ft_isdigit(29), '\n');
	printf("ORIGINAL > isdigit (300 = )) ===> %d, %c", isdigit(300), '\n');
	printf("LIB      > ft_isdigit (300 = )) ===> %d, %c", ft_isdigit(300), '\n');
	 DIGIT */
	
	/*TO UPPER
	printf("TO UPPER -------TO UPPER--------TO UPPER--------TO UPPE---%c", '\n');
	printf("ORIGINAL > toupper (0 = null) ===> %d, %c", toupper(0), '\n');
	printf("LIB   > ft_itoupper (0 = null) ===> %d, %c", ft_toupper(0), '\n');
	printf("ORIGINAL > toupper (62 = b) ===> %d, %c", toupper(62), '\n');
	printf("LIB   > ft_toupper (62 = b) ===> %d, %c", ft_toupper(62), '\n');
	printf("ORIGINAL > toupper (29 = )) ===> %d, %c", toupper(29), '\n');
	printf("LIB      > ft_toupper (29 = )) ===> %d, %c", ft_toupper(29), '\n');
	printf("ORIGINAL > toupper (300 = )) ===> %d, %c", toupper(300), '\n');
	printf("LIB      > ft_toupper (300 = )) ===> %d, %c", ft_toupper(300), '\n');
	TO UPPER END */

	/*IS ALPHA
	printf("IS ALPHA------IS ALPHA-------IS ALPHA------IS ALPHA----%c", '\n');
	printf("ORIGINAL > isalpha (0 = null) ===> %d %c", isalpha(0), '\n');
	printf("LIB   > ft_isalpha (0 = null) ===> %d %c", ft_isalpha(0), '\n');
	printf("ORIGINAL > isalpha (62 = b) ===> %d, %c", isalpha(62), '\n');
	printf("LIB   > ft_isalpha (62 = b) ===> %d, %c", ft_isalpha(62), '\n');
	printf("ORIGINAL > ft_isalpha (29 = )) ===> %d, %c", isalpha(29), '\n');
	printf("LIB      > ft_isalpha (29 = )) ===> %d, %c", ft_isalpha(29), '\n');
	printf("ORIGINAL > ft_isalpha (300 = )) ===> %d, %c", isalpha(300), '\n');
	printf("LIB      > ft_isalpha (300 = )) ===> %d, %c", ft_isalpha(300), '\n');
	printf("ORIGINAL > ft_isalpha (-5 = )) ===> %d, %c", isalpha(300), '\n');
	printf("LIB      > ft_isalpha (-5 = )) ===> %d, %c", ft_isalpha(300), '\n');
	IS ALPHA END*/

	return(0);
}

/* int main(int argc, char argv**)*/
