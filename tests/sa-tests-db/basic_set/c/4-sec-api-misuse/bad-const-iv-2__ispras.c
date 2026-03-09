#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>

static unsigned char iv[16] = { 0x16, 0x4f, 0x26, 0xdd, 0x16, 0x4f, 0x26, 0xdd, 0x16, 0x4f, 0x26, 0xdd, 0x16, 0x4f, 0x26, 0xdd };

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        return -1;
    }

    EVP_CIPHER* algo = EVP_CIPHER_fetch(NULL, "AES-128-CBC", NULL);

    if(1 != EVP_EncryptInit_ex(ctx, algo, NULL, key, iv)) { // FLAW
        return -1;
    }

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        return -1;
    }
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        return -1;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}