#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("coduri.txt");
ifstream c_a("cont_a.txt");
ifstream c_b("cont_b.txt");
ifstream c_c("cont_c.txt");

void meniu(int, int, int, int);
void eliberare_numerar(int, int, int, int);
void fara_chitanta(int, int, int, int, int);
void cu_chitanta(int, int, int, int, int);
void sold_cont(int);
void schimbare_cod_pin(int, int, int, int);
void schimbare_cod_pin_a(int);
void schimbare_cod_pin_b(int);
void schimbare_cod_pin_c(int);
int calculare_suma(int, int);

void meniu(int p1, int p2, int p3, int pn)
{

	int o, p;
	if (p1 == pn) p = pn;
	if (p2 == pn) p = pn;
	if (p3 == pn) p = pn;
	cout << "Selectati optiunea:" << endl << "1.ELIBERARE NUMERAR" << endl << "2.SOLD CONT" << endl << "3.SCHIMBARE COD PIN" << endl;
	cin >> o;
	switch (o) {
	case 1:  cout << "\x1B[2J\x1B[H";
		eliberare_numerar(p1, p2, p3, p);
		break;
	case 2: cout << "\x1B[2J\x1B[H";
		sold_cont(p);
		break;
	case 3: cout << "\x1B[2J\x1B[H";
		schimbare_cod_pin(p1, p2, p3, p);
		break;
	}
}
void eliberare_numerar(int p_1, int p_2, int p_3, int pn)
{
	int suma, C;
	cout << "\x1B[2J\x1B[H";
	cout << "Introduceti suma:" << endl << "10     200" << endl << "50     250" << endl << "100    300" << endl << "150    ALTA SUMA" << endl;
	cin >> suma;
	cout << "\x1B[2J\x1B[H";
	cout << "1.CU CHITANTA" << endl << "2.FARA CHITANTA" << endl;
	cin >> C;
	switch (C)
	{
	case 1: cout << "\x1B[2J\x1B[H";
		cu_chitanta(suma, p_1, p_2, p_3, pn);  break;
	case 2: cout << "\x1B[2J\x1B[H";
		fara_chitanta(suma, p_1, p_2, p_3, pn);  break;
	}
}

void cu_chitanta(int c, int p_1, int p_2, int p_3, int p)
{
	cout << " __________ " << endl << "| CHITANTA |" << endl << "| -------- |" << endl << "| ELIBERAT |" << endl;
	if (c < 10) {
		cout << "| " << c << " RON    |" << endl << "|__________|" << endl;
	}
	else if (c > 9 && c < 100) {
		cout << "| " << c << " RON   |" << endl << "|__________|" << endl;
	}
	else if (c > 99 && c < 1000) {
		cout << "| " << c << " RON  |" << endl << "|__________|" << endl;
	}
	else if (c > 999 && c < 10000) {
		cout << "| " << c << " RON |" << endl << "|__________|" << endl;
	}
	cout <<endl<< "Eliberare efectuata!" << endl << "Mai aveti suma de: " << calculare_suma(c, p)<<endl;
}

void fara_chitanta(int f, int p_1, int p_2, int p_3, int p)
{
	char da_nu;
	cout << endl << "DORITI SA CONTINUATI? (D/N): ";
	cin >> da_nu;
	switch (da_nu)
	{
	case 'D': cout << "\x1B[2J\x1B[H" << "Eliberare efectuata!" << endl << "Mai aveti suma de: " << calculare_suma(f, p);
		break;
	case 'N': cout << "\x1B[2J\x1B[H" << endl;
		meniu(p_1, p_2, p_3, p);
		break;
	}
}

int calculare_suma(int s, int p)
{
	int pin1, pin2, pin3, s1, s2, s3;
	c_a >> pin1 >> s1;
	c_b >> pin2 >> s2;
	c_c >> pin3 >> s3;
	if (p == pin1) return s1 - s;
	if (p == pin2) return s2 - s;
	if (p == pin3) return s3 - s;
}

void sold_cont(int s_pin)
{
	int s1, s2, s3, pin1, pin2, pin3;
	c_a >> pin1 >> s1;
	c_b >> pin2 >> s2;
	c_b >> pin3 >> s3;

	if (s_pin == pin1) cout << "In contul dvs. exista suma de: " << s1 << " RON";
	if (s_pin == pin2) cout << "In contul dvs. exista suma de: " << s2 << " RON";
	if (s_pin == pin3) cout << "In contul dvs. exista suma de: " << s3 << " RON";
}

void schimbare_cod_pin(int p1, int p2, int p3, int pn) 
{
	int pin_nou;
	cout << "Introduceti codul nou dorit: ";
	cin >> pin_nou;
	cout << "\x1B[2J\x1B[H";
	ofstream f("coduri.txt");
	if (pn == p1) {
		f << pin_nou << endl;
		f << p2 << endl;
		f << p3 << endl;
		f.close();
		schimbare_cod_pin_a(pin_nou);
	}
	else if (pn == p2) {
		f << p1 << endl;
		f << pin_nou << endl;
		f << p3 << endl;
		f.close();
		schimbare_cod_pin_b(pin_nou);
	}
	else if (pn == p3) {
		f << p1 << endl;
		f << p2 << endl;
		f << pin_nou << endl;
		f.close();
		schimbare_cod_pin_c(pin_nou);
	}
}

void schimbare_cod_pin_a(int pa)
{
	int pin1, s1;
	c_a >> pin1 >> s1;
	ofstream c_A("cont_a.txt");
	c_A << pa << endl << s1 << endl;
	c_A.close();
}

void schimbare_cod_pin_b(int pb)
{
	int pin2, s2;
	c_b >> pin2 >> s2;
	ofstream  c_B("cont_b.txt");
	c_B << pb << endl << s2 << endl;
	c_B.close();
}

void schimbare_cod_pin_c(int pc)
{
	int pin3, s3;
	c_c >> pin3 >> s3;
	ofstream c_C("cont_c");
	c_C << pc << endl << s3 << endl;
	c_C.close();
}

int main()
{
	int pin1, pin2, pin3, pin_citit;
	cout << "Introduceti pinul: " << endl;
	cin >> pin_citit;
	cout << "\x1B[2J\x1B[H";
	fin >> pin1 >> pin2 >> pin3;
	if (pin1 != pin_citit && pin2 != pin_citit && pin3 != pin_citit) {
		cout << "PINUL NU EXISTA" << endl;
	}
	else meniu(pin1, pin2, pin3, pin_citit);
	fin.close();

}