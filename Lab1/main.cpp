//#include <iostream>
//#include "Enc_and_Dec.h"
//#include <stdio.h>

using namespace std;

int main() {

	Enc_and_Dec *obj = new Enc_and_Dec();
	char *key = obj->KeyGen();
	
	char plain_text[] = "First lab";
	cout << "plain texe - " << plain_text << endl;

	char enc[256];
	int a = obj->Enc(key, plain_text, enc);
	cout <<"encrypted text - " << enc << endl;

	char dec[256];
	int len_dec_text = obj->Dec(key, enc, dec, a);
	dec[len_dec_text] = 0;
	cout << "decrypred text - " << dec << endl;

	free(obj);

	system("pause");
	return 0;
}
