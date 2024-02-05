/**
 * to_lower - Converts a character to it's lower case
 * @s: Character to convert
 *
 * Return: ASCII value of the character
 */

int *to_lower(char s)
{
    if (s >= 'A' && s <= 'Z')
        return (s - 'A' + 'a');
    return (s);
}

/**
 * is_alpha_num - Checks if a character is alphanumeric
 * @s: Character to Check
 *
 * Return: True if alphanumeric and false if not
 */

bool is_alpha_num(char s)
{
    if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || (s >= 'a' && s <= 'z'))
        return (true);
    return (false);
}


/**
 * isPalindrome - Checks if a string is Palindrome
 * @s: String to check
 *
 * Return: True if Palindrome, otherwise false
 */

bool isPalindrome(char* s) {
   char *start = s;
   char *end = s + strlen(s);

    while (start < end)
    {
        while (start < end && !is_alpha_num(*start))
            start++;
        while (start < end && !is_alpha_num(*end))
            end--;
        
        if (to_lower(*start) != to_lower(*end))
            return (false);
        
        start++;
        end--;
    }
    return (true);
}
