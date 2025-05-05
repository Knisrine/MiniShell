char    *get_var(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(s[i])
    {
        if(s[i] == '=')
        {
            i++;
            while (s[i])
                s[i] = '\0';
            break;
        }
        i++;
    }
    return (&s[j]);
}

int main()
{
    char s[] = "PATH=/usr/bin";
    char *result = get_var(s);
    printf("Result: %s\n", result);
    return 0;
}