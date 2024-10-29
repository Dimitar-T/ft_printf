/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrendaf <dtrendaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:31:24 by dtrendaf          #+#    #+#             */
/*   Updated: 2024/10/29 17:59:20 by dtrendaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(va_list args)
{
	int		i;
	int		temp;
	int 	output;
	char	*string;

	string = va_arg(args, char *);
	i = 0;
	output = 0;
	while (string[i] != '\0')
	{
		temp = write(1,&string[i],1);
		if (temp == -1)
			return (-1);
		output += temp;
		i++;
	}	
	return (output);
}
int ft_print_void_ptr (va_list args)
{
	unsigned long	adr;
	char			*output;
	
	adr = va_arg(args, void *);
	
	
}

int ft_putchr(va_list args)
{
	char	c;
	
	c = va_arg(args, int);	
	return (write(1,&c,1));
}
int	cases(char c, va_list args)
{
	int	count;
	
	if (c == 'c')
		return(count = ft_putchr(args));
	else if (c == 's')
		return(count = ft_putstr(args));
	// else if(string == 'p')

	// else if(string == 'd')

	// else if(string == 'i')

	// else if(string == 'u')

	// else if(string == 'x')

	// else if(string == 'X')

	// else if(string == '%')
	
	// else
		return (-1);
}


int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int 	chr_count;
	int 	temp;
	
	va_start(args, string);
	i = 0;
	chr_count = 0;
	while(string[i] != '\0')
	{
		if (string[i] == '%')
			temp = cases(string[++i], args);
		else
			temp = write(1,&string[i],1);
		if (temp == -1)
			return (temp);
		chr_count += temp;	
		i++;	
	}
	return (chr_count);
}

int main(void)
{
	// int a = 111111;
	// printf("%n",  a);
	// printf("abdef");
	char *string = "dali be ludo\n";
	printf("the value of the custom function is: %d",ft_printf("ahahah %s", string));
	// printf("this is %p", string);
}
