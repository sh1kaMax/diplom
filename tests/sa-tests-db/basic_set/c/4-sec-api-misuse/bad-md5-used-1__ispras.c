#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>

char *get_hash() {
    return "MD5";
}

int main(void)
{
    EVP_MD_CTX *ctx = NULL;
    EVP_MD *hash = NULL;
    const unsigned char msg[] = {
        0x00, 0x01, 0x02, 0x03
    };
    unsigned int len = 0;
    unsigned char *outdigest = NULL;
    int ret = 1;

    ctx = EVP_MD_CTX_new();
    if (ctx == NULL)
        goto err;

    hash = EVP_MD_fetch(NULL, get_hash(), NULL); // FLAW
    if (hash == NULL)
        goto err;

    if (!EVP_DigestInit_ex(ctx, hash, NULL))
       goto err;

    if (!EVP_DigestUpdate(ctx, msg, sizeof(msg)))
        goto err;

    outdigest = OPENSSL_malloc(EVP_MD_get_size(hash));
    if (outdigest == NULL)
        goto err;

    if (!EVP_DigestFinal_ex(ctx, outdigest, &len))
        goto err;

    BIO_dump_fp(stdout, outdigest, len);

    ret = 0;

 err:
    /* Clean up all the resources we allocated */
    OPENSSL_free(outdigest);
    EVP_MD_free(hash);
    EVP_MD_CTX_free(ctx);
    if (ret != 0)
       ERR_print_errors_fp(stderr);
    return ret;
}