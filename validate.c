
#include "vbc.h"

# define DIG case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9'
# define ETOK "Unexpected token %c\n"

int	validate_str(char *str)
{
	size_t	idx = 0;
	enum {
		PARA,
		SYM,
		DIGIT
	}		last_type;
	int	pc = 0;
	switch (str[idx])
	{
	case '+':
	case '*':
		last_type = SYM;
		break;
	case '(':
		pc++;
		last_type = PARA;
		break ; 
	DIG:
		last_type = DIGIT;
		break ;
	default:
		printf(ETOK, str[idx]);
		return (0);
		break;
	}
	idx++;
	while (str[idx])
	{
		switch (last_type)
		{
		case PARA:
			if (!str[idx])
			{
				printf("Unexpected end of line.\n");
				return (0);
			}
			if (!isdigit(str[idx]))
			{
				printf(ETOK, str[idx]);
				return (0);
			}
			if (isdigit(str[idx]))
				last_type = DIGIT;
			break;
		case SYM:
			if (!str[idx])
			{
				printf("Unexpected end of line.\n");
				return (0);
			}
			else if (str[idx] == '(')
			{
				pc++;
				last_type = PARA;
			}
			else if (isdigit(str[idx]))
				last_type = DIGIT;
			else
			{
				printf(ETOK, str[idx]);
				return (0);
			}
			break;
		case DIGIT:
			if (str[idx] == '*' || str[idx] == '+')
				last_type = SYM;
			else if (str[idx] == ')')
			{
				last_type = DIGIT;
				pc--;
			}
			else
			{
				printf(ETOK, str[idx]);
				return (0);
			}
			break;
		default:
			break;
		}
		if (pc < 0)
		{
			printf(ETOK, str[idx]);
			return (0);
		}
		idx++;
	}
	if (pc != 0)
		printf("Unexpected end of line");
	return (1);
}