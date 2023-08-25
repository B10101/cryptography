#include <stdio.h>
#include <string.h>

#define IV 0xAA
#define KEY 0x08

char cipher(unsigned char block, char key)
{
return (key+11*block)%256;
}

char inv_cipher(unsigned char block, char key)
{ // 163 is the inverse of 11 mod 256
return (163*(block-key+256))%256;
}

void CTR(const char ciphertext[], char buf[BUFSIZ], const int size) {
    // variable declaration
    int index;
    char nonce = (0xAA & 0b11111000); 
    char counter = 0; 

    // decryption
    for(index = 0; index < size; ++index) {
        counter &= 0b111;
        buf[index] =
        cipher(nonce | counter, KEY) ^
        ciphertext[index];
        ++counter;
    }

    // null termination
    buf[index] = '\0';
}

void ECB(const char ciphertext[], char buf[BUFSIZ], const int size) {
    // variable declaration
    int index;

    // decryption
    for(index = 0; index < size; ++index) {
        buf[index] =
        inv_cipher(ciphertext[index], KEY);
    }

    // null termination
    buf[index] = '\0';
}

void CFB(const char ciphertext[], char buf[BUFSIZ], const int size) {
    // variable declaration
    int index;

    // decryption
    buf[0] = cipher(IV, KEY) ^ ciphertext[0];
    for(index = 1; index < size; ++index) {
        buf[index] =
        cipher(ciphertext[index - 1], KEY) ^
        ciphertext[index];
    }

    // null termination
    buf[index] = '\0';
}

void CBC(const char ciphertext[], char buf[BUFSIZ], const int size) {
    // variable declaration
    int index;

    // decryption
    buf[0] = IV ^ inv_cipher(ciphertext[0], KEY);
    for(index = 1; index < size; ++index) {
        buf[index] =
        ciphertext[index - 1] ^
        inv_cipher(ciphertext[index], KEY);
    }

    // null termination
    buf[index] = '\0';
}

void OFB(const char ciphertext[], char buf[BUFSIZ], const int size) {
    // variable declaration
    int index;

    // decryption
    buf[0] = cipher(IV, KEY) ^ ciphertext[0];
    for(index = 1; index < size; ++index) {
        buf[index] =
        cipher(buf[index - 1] ^ ciphertext[index - 1], KEY) ^ ciphertext[index];
    }

    // null termination
    buf[index] = '\0';
}

int main() {
char buf[BUFSIZ];

{
const char ciphertext[] = { 0x21, 0x2C, 0x33, 0x0F,0x18,0x4E,0xBB };
CTR(ciphertext, buf, sizeof(ciphertext));
puts("CTR");
printf("Ciphertext: \"");
for(int i = 0; i < sizeof(ciphertext); ++i) {
printf("%c", ciphertext[i]);
}
printf("\"\nDecrypted: \"%s\"\n", buf);
}

{
const char ciphertext[] = { 0xAC, 0xCD, 0xF9, 0x04 };
ECB(ciphertext, buf, sizeof(ciphertext));
puts("ECB");
printf("Ciphertext: \"");
for(int i = 0; i < sizeof(ciphertext); ++i) {
printf("%c", ciphertext[i]);
}
printf("\"\nDecrypted: \"%s\"\n", buf);
}

{
const char ciphertext[] = { 0x32, 0x4F, 0x1F, 0x36,0x36, 0x23 };
CFB(ciphertext, buf, sizeof(ciphertext));
puts("CFB");
printf("Ciphertext: \"");
for(int i = 0; i < sizeof(ciphertext); ++i) {
printf("%c", ciphertext[i]);
}
printf("\"\nDecrypted: \"%s\"\n", buf);
}

{
const char ciphertext[] = { 0x5B, 0x5A, 0x91, 0xC9, 0x27,0x41,0x70 };
CBC(ciphertext, buf, sizeof(ciphertext));
puts("CBC");
printf("Ciphertext: \"");
for(int i = 0; i < sizeof(ciphertext); ++i) {
printf("%c", ciphertext[i]);
}
printf("\"\nDecrypted: \"%s\"\n", buf);
}

{
const char ciphertext[] = { 0x3E, 0xDF, 0x67, 0x38, 0x42 };
OFB(ciphertext, buf, sizeof(ciphertext));
puts("OFB");
printf("Ciphertext: \"");
for(int i = 0; i < sizeof(ciphertext); ++i) {
printf("%c", ciphertext[i]);
}
printf("\"\nDecrypted: \"%s\"\n", buf);
}

return 0;
}