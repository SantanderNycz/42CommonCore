static char     *h_new_str(unsigned long value, int *strlen)
{
    int             i;
    char            *str;
    unsigned long   temp;

    i = 0;
    temp = value;
    while (temp)
    {
        temp = temp / 16;
        i++;
    }
    str = calloc(i + 1, sizeof(char));
    *strlen = i - 1;
    return (str);
}

int     ft_print_pointer(unsigned long value, int asc)
{
    unsigned long   temp_value;
    char            *printout;
    int             *iptr;
    int             i;

    iptr = &i;
    temp_value = value;
    printout = h_new_str(value, iptr);
    if (!printout)
        return (0);
    while (temp_value != 0 && i-- >= 0)
    {
        if ((temp_value % 16) < 10)
            printout[i + 1] = (temp_value % 16) + 48;
        else
            printout[i + 1] = (temp_value % 16) + asc;
        temp_value = temp_value / 16;
    }
    i = ft_strlen(printout);
    i = i + ft_putstr("0x");
    ft_putstr(printout);
    free(printout);
    if (value == 0)
        i += ft_putchar('0');
    return (i);
}