/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megamain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:11:10 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 20:02:59 by lprieto-         ###   ########.fr       */
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

/*BZERO ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
void ft_bzero(void *s, size_t n);*

	printf("BZERO----BZERO----BZERO----BZERO----%c", '\n');
	printf("ORIGINAL >  (holamundo, -1) ===> %s, %c", bzero("holamundo", -1), '\n');
	printf("LIB  	 >  (holamundo, -1) ===> %s, %c", ft_bzero("holamundo", -1), '\n');
	* * * * * * * * * * * * * * * * * *

*BZERO END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/
----
/*IS MEMSET ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
void *ft_memset(void *b, int c, size_t len);*

	printf("MEMSET----MEMSET----MEMSET----MEMSET----%c", '\n');
	printf("ORIGINAL >  (holamundo, '*', 10) ===> %p, %c", memset("holamundo", 7, 9), '\n');
	printf("LIB 	 >  (holamundo, '10', 10) ===> %p, %c", ft_memset("holamundo", 7, 9), '\n');
	* * * * * * * * * * * * * * * * * *i
	int main(int argc, char **argv)
	{
		if (argc != 4)
			return (0);
		char *resultado_ft_memset = ft_memset(argv[1], atoi(argv[2]), atoi(argv[3]));
		char *resultado_memset = ft_memset(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("ft_memset:%s \n", resultado_ft_memset);
		printf("memset:%s", resultado_memset);
		return(0);
	}
*TO MEMSET END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* STRNCMP ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_strncmp(const char *s1, const char *s2, size_t n);*

	printf("STRNCMP----STRNCMP----STRNCMP----STRNCMP----%c", '\n');
	printf("ORIGINAL >  (holamundo, -1) ===> %s, %c", strncmp("holamundo", -1), '\n');
	printf("LIB  	 >  (holamundo, -1) ===> %s, %c", ft_strncmp("holamundo", -1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 4)
			return (0);
		printf("ft_strncmp:%d \n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("strncmp:%d", strncmp(argv[1], argv[2], atoi(argv[3])));
		return(0);
	}
*STRCHR END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* STRLEN ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
size_t	ft_strlen(const char *s);*

	printf("STRLEN----STRLEN----STRLEN----STRLEN----%c", '\n');
	printf("ORIGINAL >  (holamundo, -1) ===> %s, %c", strlen("holamundo", -1), '\n');
	printf("LIB  	 >  (holamundo, -1) ===> %s, %c", ft_strlen("holamundo", -1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_strlen:%zu \n", ft_strlen(argv[1]));
		printf("strlen:%zu", strlen(argv[1]));
		return(0);
	}
*STRLEN END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* STRRCHR ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
char	*ft_strrchr(const char *s, int c);*

	printf("STRRCHR----STRRCHR----STRRCHR----STRRCHR----%c", '\n');
	printf("ORIGINAL >  (holamundo, -1) ===> %s, %c", strrchr("holamundo", -1), '\n');
	printf("LIB  	 >  (holamundo, -1) ===> %s, %c", ft_strrchr("holamundo", -1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 3)
			return (0);
		printf("ft_strrchr:%s \n", ft_strrchr(argv[1], atoi(argv[2])));
		printf("strrchr:%s", strrchr(argv[1], atoi(argv[2])));
		return(0);
	}
*STRCHR END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* IS PRINT ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_isprint(int c);*

	printf("IS PRINT----IS PRINT----IS PRINT----IS PRINT----%c", '\n');
	printf("ORIGINAL >  (3) ===> %p, %c", isprint(3), '\n');
	printf("LIB  	 >  (3) ===> %p, %c", ft_isprint(3), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_isprint:%d \n", ft_isprint(atoi(argv[1])));
		printf("isprint:%d", isprint(atoi(argv[1])));
		return(0);
	}	
*IS PRINT END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* IS ASCII ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_isascii(int c);*

	printf("IS ASCII----IS ASCII----IS ASCII----IS ASCII----%c", '\n');	
	printf("ORIGINAL > (holamundo, -1) ===> %s, %c", isascii(-1), '\n');
	printf("LIB 	 > (-1) ===> %s, %c", ft_isascii(-1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_isascii:%d \n", ft_isascii(atoi(argv[1])));
		printf("isascii:%d", isascii(atoi(argv[1])));
		return(0);
	}
*IS ASCII END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* STRCHR ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
char *ft_strchr(const char *s, int c);*

	printf("STRCHR----STRCHR----STRCHR----STRCHR----%c", '\n');
	printf("ORIGINAL >  (holamundo, -1) ===> %s, %c", strchr("holamundo", -1), '\n');
	printf("LIB  	 >  (holamundo, -1) ===> %s, %c", ft_strchr("holamundo", -1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 3)
			return (0);
		printf("ft_strchr:%s \n", ft_strchr(argv[1], atoi(argv[2])));
		printf("strchr:%s", strchr(argv[1], atoi(argv[2])));
		return(0);
	}
*STRCHR END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* IS ALNUM ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_isalnum(int c);*

	printf("IS ALNUM----IS ALNUM----IS ALNUM----IS ALNUM----%c", '\n');
	printf("ORIGINAL >  (0 = null) ===> %d, %c", isalnum('\0'), '\n');
	printf("LIB	 >  (0 = null) ===> %d, %c", ft_isalnum('\0'), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);`
		printf("ft_isalnum:%d \n", ft_isalnum(atoi(argv[1])));
		printf("isalnum:%d", isalnum(atoi(argv[1])));
		return(0);
	}
*IS ALNUM END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/
	
/* TO LOWER ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_tolower(int c);*

	printf("TO LOWER----TO LOWER----TO LOWER----TO LOWER----%c", '\n');
	printf("ORIGINAL >  (0 = null) ===> %d, %c", tolower(0), '\n');
	printf("LIB  	 >  (0 = null) ===> %d, %c", ft_tolower(0), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_tolower:%d \n", ft_tolower(atoi(argv[1])));
		printf("tolower:%d", tolower(atoi(argv[1])));
		return(0);
	}
*TO LOWER END  ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* IS DIGIT ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_isdigit(int c);*

	printf("IS DIGIT----IS DIGIT----IS DIGIT----IS DIGIT----%c", '\n');
	printf("ORIGINAL >  (0 = null) ===> %d, %c", isdigit(0), '\n');
	printf("LIB  	 >  (0 = null) ===> %d, %c", ft_isdigit(0), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_isdigit:%d \n", ft_isdigit(atoi(argv[1])));
		printf("isdigit:%d", isdigit(atoi(argv[1])));
		return(0);
	}
*IS DIGIT END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/
	
/* TO UPPER ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_toupper(int c);*

	printf("TO UPPER----TO UPPER----TO UPPER----TO UPPER----%c", '\n');
	printf("ORIGINAL >  (0 = null) ===> %d, %c", toupper(0), '\n');
	printf("LIB 	 >  (0 = null) ===> %d, %c", ft_toupper(0), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_toupper:%d \n", ft_toupper(atoi(argv[1])));
		printf("toupper:%d", toupper(atoi(argv[1])));
		return(0);
	}	
*TO UPPER END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* IS ALPHA ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_isalpha(int c);* 

	printf("IS ALPHA----IS ALPHA----IS ALPHA----IS ALPHA----%c", '\n');
	printf("ORIGINAL >  (0 = null) ===> %d %c", isalpha(0), '\n');
	printf("LIB 	 >  (0 = null) ===> %d %c", ft_isalpha(0), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 2)
			return (0);
		printf("ft_isalpha:%d \n", ft_isalpha(atoi(argv[1])));
		printf("isalpha:%d", isalpha(atoi(argv[1])));
		return(0);
	}
*IS ALPHA END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

	return(0);
}
