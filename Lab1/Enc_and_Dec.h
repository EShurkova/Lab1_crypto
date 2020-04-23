//#pragma once

class Enc_and_Dec {
private:

	unsigned char *iv;

public:
	
	Enc_and_Dec(); //Constructor of class
		
	char *KeyGen(); //Key for function Enc, Dec
	
	int Enc(const char *key, const char *plain_text, char *encrypted_text); //Function for encryption 
	//Parametrs: key - key from function KeyGen; plain_text - not encrypted text; encrypted_text - encrypted text
	
	int Dec(const char *key, const char *encrypted_text, char *plain_text, int len); //Function for decryption
	//Parametrs: key - key from function KeyGen; plain_text - not encrypted text; encrypted_text - encrypted text; len - length key

	~Enc_and_Dec(); //Destructor of class

};
