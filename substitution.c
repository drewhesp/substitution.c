#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n"); 
        return 1;
    }
    
    bool valid = true;
    
    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] < 65 || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122)
        {
            valid = false;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                valid = false;
            }
        }
    }
    
    if (!valid)
    {
        printf("Usage: ./substitution key\n"); 
        return 1;
    }
    else
    {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int shifters[26];
        
        for (int i = 0; i < 26; i++)
        {
            shifters[i] = toupper(argv[1][i]) - alphabet[i];
        }
        
        string plaintext = get_string("plaintext: ");
        char ciphertext[strlen(plaintext) + 1];
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plaintext[i]) == alphabet[j])
                {
                    ciphertext[i] = plaintext[i] + shifters[j];
                    // printf("Shifted %c by %i\n", plaintext[i], shifters[j]);
                }
                if(plaintext[i] < 65 || (plaintext[i] > 90 && plaintext[i] < 97) || plaintext[i] > 122)
                {
                    ciphertext[i] = plaintext[i];
                }
            }
        }
        
        ciphertext[strlen(plaintext)] = '\0';
        
        printf("ciphertext: %s\n", ciphertext);
        
        return 0;
    }
}
