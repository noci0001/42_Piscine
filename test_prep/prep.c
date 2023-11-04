#include <stdio.h>

int	ft_strlen(char *str);

char *ft_rev_array(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_rev_array(char *str)
{
	int	index;
	int	temporary;
	int	ArrayLength;

	index = 0;
	temporary = 0;
	ArrayLength = (ft_strlen(str)-1);
	while (index < ArrayLength)
	{
		temporary = str[index];
		str[index] = str[ArrayLength];
		str[ArrayLength] = temporary;
		index++;
		ArrayLength--;
	}
	return (str);
}

int	main(void)
{
	char arr[] = "DAS AUTO";
	ft_rev_array(arr);
	printf("%s", arr);
}