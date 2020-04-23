//#include <cstring>
//#include <iostream>
//#include "Enc_and_Dec.h"
//#include "openssl/ssl.h"
//#include "openssl/err.h"
//#include "openssl/bio.h"
//#include <openssl/evp.h>

Enc_and_Dec::Enc_and_Dec() {
	iv = (unsigned char *)EVP_chacha20();
}


char *Enc_and_Dec::KeyGen() {
	return (char *)EVP_chacha20();
}

static void Errors() {
	ERR_print_errors_fp(stderr);
	abort();
}

int Enc_and_Dec::Enc(const char *key, const char *plain_text, char *encrypted_text) {
	EVP_CIPHER_CTX *ctx;
	if (!(ctx = EVP_CIPHER_CTX_new()))
		Errors();
	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, this->iv))
		Errors();
	int len;

	if (1 != EVP_EncryptUpdate(ctx, (unsigned char *)encrypted_text, &len, (unsigned char *)plain_text,
		strlen((char *)plain_text)))
		Errors();
	int encrypted_text_len = len;

	if (1 != EVP_EncryptFinal_ex(ctx, (unsigned char *)encrypted_text + len, &len))
		Errors();
	encrypted_text_len += len;
	EVP_CIPHER_CTX_free(ctx);
	return encrypted_text_len;
}

int Enc_and_Dec::Dec(const char *key, const char *encrypted_text, char *string, int lenght) {
	EVP_CIPHER_CTX *ctx;
	if (!(ctx = EVP_CIPHER_CTX_new()))
		Errors();
	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, this->iv))
		Errors();
	int len;

	if (1 != EVP_DecryptUpdate(ctx, (unsigned char *)string, &len, (unsigned char *)encrypted_text, lenght))
		Errors();
	int plain_text_len = len;

	if (1 != EVP_DecryptFinal_ex(ctx, (unsigned char *)encrypted_text + len, &len))
		Errors();
	plain_text_len += len;
	EVP_CIPHER_CTX_free(ctx);
	return plain_text_len;
}

Enc_and_Dec::~Enc_and_Dec() {
	free(iv);
}
