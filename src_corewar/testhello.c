#include "corewar.h"

void    testhello()
{
    int			num;
    int			num2;
	int			i;
    uint8_t		*ptr;

    num = 0x307;
	ptr = (uint8_t*)&num;
    
	i = 0;
	while (i < 4)
	{
		num2 = *ptr;
		ft_printf("%d\n", num2);
		// write(0, ptr, 1);
		// write(0, "\n", 1);
		i++;
		ptr++;
	}
    ft_printf("Here is VM!");
    return ;
}
