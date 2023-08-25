#include <stdio.h>
#include <string.h>

// declaring pre-processor derivative
// Initializing vector and key
#define IV 0xAA
#define KEY 0x08

// cipher block as defined.
char cipher(unsigned char block, char key)
{
    return (key + 11 * block) % 256;
}

void CTRMode(const char *plaintext, const int n, char ciphertext[BUFSIZ])
{
    // declaring variables
    int count;
    int nonce;
    int counter;

    // parameter initializing
    nonce = 0xAA & 0b11111000;
    counter = 0;

    for (count = 0; count < n; ++count)
    {
        // masking the counter variable
        counter &= 0b111;

        // filling the ciphertext
        ciphertext[count] =
            cipher(nonce | counter, KEY) ^
            plaintext[count];

        // incrementing the counter
        ++counter;
    }
}

void ECBMode(const char *plaintext, const int n, char ciphertext[BUFSIZ])
{
    // declaring the looping variable
    int count;

    for (count = 0; count < n; ++count)
    {

        ciphertext[count] =
            cipher(plaintext[count], KEY);
    }
}

void CFBMode(const char *plaintext, const int n, char ciphertext[BUFSIZ])
{
    // declaring the looping variable
    int count;

    ciphertext[0] =
        cipher(IV, KEY) ^
        plaintext[0];
    for (count = 1; count < n; ++count)
    {
        // filling the ciphertext
        ciphertext[count] =
            cipher(ciphertext[count - 1], KEY) ^
            plaintext[count];
    }
}

void CBCMode(const char *plaintext, const int n, char ciphertext[BUFSIZ])
{
    // declaring the looping variable
    int count;

    ciphertext[0] =
        cipher(plaintext[0] ^ IV, KEY);
    for (count = 1; count < n; ++count)
    {
        // filling the ciphertext
        ciphertext[count] =
            cipher(plaintext[count] ^
                       ciphertext[count - 1],
                   KEY);
    }
}

void OFBMode(const char *plaintext, const int n, char ciphertext[BUFSIZ])
{
    // declaring the looping variable
    int count;

    ciphertext[0] =
        cipher(IV, KEY) ^
        plaintext[0];
    for (count = 1; count < n; ++count)
    {
        // filling the ciphertext
        ciphertext[count] =
            cipher(ciphertext[count - 1] ^
                       plaintext[count - 1],
                   KEY) ^
            plaintext[count];
    }
}

int main()
{
    // declaring hexadecimal values.
    const char *hex = "0123456789ABCDEF";
    char ciphertext[BUFSIZ];

    {
        // initializing the plaintext
        const char *plaintext = "agent99";
        const int n = strlen(plaintext);

        // counter encryption mode
        CTRMode(plaintext, n, ciphertext);
        printf("nCTR Mode:n"
               "plaintext: %sn"
               "ciphertext: 0x",
               plaintext);
        for (int count = 0; count < n; ++count)
        {
            printf("%c%c",
                   hex[(ciphertext[count] >> 4) & 0b1111],
                   hex[(ciphertext[count]) & 0b1111]);
        }
        puts("");
    }

    {
        // initializing the plaintext
        const char *plaintext = "congo";
        const int n = strlen(plaintext);

        // Electronic codebook encryption mode
        ECBMode(plaintext, n, ciphertext);
        printf("nECB Mode:n"
               "plaintext: %sn"
               "ciphertext: 0x",
               plaintext);
        for (int count = 0; count < n; ++count)
        {
            printf("%c%c",
                   hex[(ciphertext[count] >> 4) & 0b1111],
                   hex[(ciphertext[count]) & 0b1111]);
        }
        puts("");
    }

    {
        // initializing the plaintext
        const char *plaintext = "longo";
        const int n = strlen(plaintext);

        // Cipher Feedback encryption mode
        CFBMode(plaintext, n, ciphertext);
        printf("nCFB Mode:n"
               "plaintext: %sn"
               "ciphertext: 0x",
               plaintext);
        for (int count = 0; count < n; ++count)
        {
            printf("%c%c",
                   hex[(ciphertext[count] >> 4) & 0b1111],
                   hex[(ciphertext[count]) & 0b1111]);
        }
        puts("");
    }

    {
        // initializing the plaintext
        const char *plaintext = "smokey";
        const int n = strlen(plaintext);

        // cipher block chaining encryption mode
        CBCMode(plaintext, n, ciphertext);
        printf("nCBC Mode:n"
               "plaintext: %sn"
               "ciphertext: 0x",
               plaintext);
        for (int count = 0; count < n; ++count)
        {
            printf("%c%c",
                   hex[(ciphertext[count] >> 4) & 0b1111],
                   hex[(ciphertext[count]) & 0b1111]);
        }
        puts("");
    }

    {
        // initializing the plaintext
        const char *plaintext = "heart";
        const int n = strlen(plaintext);

        // Output feedback encryption mode
        OFBMode(plaintext, n, ciphertext);
        printf("nOFB Mode:n"
               "plaintext: %sn"
               "ciphertext: 0x",
               plaintext);
        for (int count = 0; count < n; ++count)
        {
            printf("%c%c",
                   hex[(ciphertext[count] >> 4) & 0b1111],
                   hex[(ciphertext[count]) & 0b1111]);
        }
        puts("");
    }

    return 0;
}