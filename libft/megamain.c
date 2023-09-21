/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megamain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:11:10 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/21 12:11:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/*BZERO ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
void ft_bzero(void *s, size_t n);*

	printf("BZERO----BZERO----BZERO----BZERO----%c", '\n');
	printf("ORIGINAL >  (holamundo, 3) ===> %s, %c", bzero("holamundo", 3), '\n');
	printf("LIB  	 >  (holamundo, 3) ===> %s, %c", ft_bzero("holamundo", 3), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 4)
			return (0);
		char *resultado_ft_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
		char *resultado_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("ft_memchr:%s \n", resultado_ft_memchr);
		printf("memchr:%s", resultado_memchr);
		return(0);
	}

*BZERO END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/*MEMCHR ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
void *ft_memchr(const void *s, int c, size_t n);*

	printf("MEMCHR----MEMCHR----MEMCHR----MEMCHR----%c", '\n');
	printf("ORIGINAL >  (hola, 2, 1) ===> %s, %c", memchr("hola", 2, 1), '\n');
	printf("LIB  	 >  (hola, 2, 1) ===> %s, %c", ft_memchr("hola",2, 1), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 4)
		return (0);
		char *resultado_ft_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
		char *resultado_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("ft_memchr:%s \n", resultado_ft_memchr);
		printf("memchr:%s", resultado_memchr);
		return(0);
	}
*MEMCHR END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/*IS MEMSET ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
void *ft_memset(void *b, int c, size_t len);*

	printf("MEMSET----MEMSET----MEMSET----MEMSET----%c", '\n');
	printf("ORIGINAL >  (holamundo, 5, 9) ===> %p, %c", memset("holamundo", 5, 9), '\n');
	printf("LIB 	 >  (holamundo, 5, 9) ===> %p, %c", ft_memset("holamundo", 5, 9), '\n');
	* * * * * * * * * * * * * * * * * *
	int main(int argc, char **argv)
	{
		if (argc != 4)
			return (0);
		char *resultado_ft_memset = ft_memset(argv[1], atoi(argv[2]), atoi(argv[3]));
		char *resultado_memset = memset(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("ft_memset:%s \n", resultado_ft_memset);
		printf("memset:%s", resultado_memset);
		return(0);
	}
*TO MEMSET END ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*/

/* STRNCMP ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~*
int ft_strncmp(const char *s1, const char *s2, size_t n);*

	printf("STRNCMP----STRNCMP----STRNCMP----STRNCMP----%c", '\n');
	printf("ORIGINAL >  (hola, mundo, 3) ===> %d, %c", strncmp("hola" "mundo", 3), '\n');
	printf("LIB  	 >  (hola, mundo, 3) ===> %d, %c", ft_strncmp("hola" "mundo", 3), '\n');
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
	printf("ORIGINAL >  (3) ===> %d, %c", isprint(3), '\n');
	printf("LIB  	 >  (3) ===> %d, %c", ft_isprint(3), '\n');
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
	printf("ORIGINAL > (-1) ===> %d, %c", isascii(-1), '\n');
	printf("LIB 	 > (-1) ===> %d, %c", ft_isascii(-1), '\n');
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
	printf("ORIGINAL >  (65 = A) ===> %d, %c", tolower(65), '\n');
	printf("LIB  	 >  (65 = A) ===> %d, %c", ft_tolower(65), '\n');
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
	printf("ORIGINAL >  (48 = 0) ===> %d, %c", isdigit(48), '\n');
	printf("LIB  	 >  (97 = a) ===> %d, %c", ft_isdigit(97), '\n');
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
	printf("ORIGINAL >  (97 = a) ===> %d, %c", toupper(97), '\n');
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
	printf("ORIGINAL >  (48 "0") ===> %d %c", isalpha(48), '\n');
	printf("LIB 	 >  (97 "a") ===> %d %c", ft_isalpha(97), '\n');
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
