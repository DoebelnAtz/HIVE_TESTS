#include "libft.h"
#include <stdio.h>

char *re_str(char *str, size_t size, const char* content)
{
	char *new;

	new = str;
	ft_strdel(&new);
	if (new)
	{
		printf("Test Failed\n");
		return (0);
	}
	new = ft_strnew(size);
	new = ft_strcpy(new, content);
	return (new);
}

int main(int argc, char const *argv[])
{
	char	*arr1;
	char	**split;
	int		num1;
	int		index;
	printf("ITOA and ATOI:\n");
	arr1 = ft_itoa(ft_atoi("-1"));
	printf("-1: %s | ", arr1);
	arr1 = ft_itoa(ft_atoi("-2147483648"));
	printf("-2147483648: %s | ", arr1);
	arr1 = ft_itoa(ft_atoi("2147483647"));
	printf("2147483647: %s | ", arr1);
	arr1 = ft_itoa(ft_atoi("0"));
	printf("0: %s\n", arr1);
	printf("\n__\n");
	printf("Strsplit:\n\n");
	index = 0;
	split = ft_strsplit("string1 string2 string3", ' ');
	while (split[index])
	{
		printf("%s\n", split[index]);
		index ++;
	}
	index = 0;
	printf("\n__\n Nothing: \n");
	split = ft_strsplit("", ' ');
	while (split[index])
	{
		printf("%s\n", split[index]);
		index ++;
	}
	index = 0;
	printf("\n__\n Nothing: \n");
	split = ft_strsplit("   ", ' ');
	while (split[index])
	{
		printf("%s\n", split[index]);
		index ++;
	}
	index = 0;
	printf("\n__\n");
	split = ft_strsplit(" string1     string2  string3   ", ' ');
	while (split[index])
	{
		printf("%s\n", split[index]);
		index ++;
	}
	printf("\nStrtrim:\n\n");
	arr1 = ft_strtrim("  hello  ");
	printf("hello: %s | ", arr1);
	arr1 = ft_strtrim("  hello");
	printf("hello: %s | ", arr1);
	arr1 = ft_strtrim("hello  ");
	printf("hello: %s | ", arr1);
	arr1 = ft_strtrim("  ");
	printf("Nothing: %s | ", arr1);
	arr1 = ft_strtrim("");
	printf("Nothing: %s \n", arr1);

	printf("\nStrlen && Strncat && Strcat && Strlcat && Strncpy: \n\n");
	char *arr2;
	char *arr3;
	arr2 = ft_strnew(strlen("World") + 1);
	arr2 = ft_strcat(arr2, "World");
	printf("World: %s | ", arr2);
	arr3 = ft_strnew(12);
	arr3 = ft_strncpy(arr3, "Hello ", sizeof("Hello World"));
	printf("Hello: %s | ", arr3);
	num1 = ft_strlcat(arr3, arr2, 12);
	printf("Hello World: %s | 11: %d\n", arr3, num1);
	arr2 = re_str(arr2, 7, " World");
	arr3 = re_str(arr3, 12, "Hello");
	num1 = strlcat(arr3, arr2, 8);
	printf("Hello W: %s | 11: %d\n", arr3, num1);
	arr2 = re_str(arr2, 7, " World");
	arr3 = re_str(arr3, 17, "Hello");
	num1 = strlcat(arr3, arr2, 3);
	printf("Hello: %s | 9: %d\n", arr3, num1);

	printf("\nStrClr && Strdel && Memalloc: \n\n");
	arr1 = re_str(arr1, 13, "Test Passed!");
	printf("%s \n", arr1);

	

	return (0);
}
