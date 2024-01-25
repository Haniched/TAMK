#include <iostream>
#include <string>

int main() {
	using namespace std;

	cout << "Aloitus: ";
	string aloitus;
	getline(cin, aloitus);

	cout << "Opettaja: ";
	string opettaja;
	getline(cin, opettaja);

	cout << "Kotitehtavan laji: ";
	string laji;
	getline(cin, laji);

	cout << "Lemmikin nimi: ";
	string lemmikin_nimi;
	getline(cin, lemmikin_nimi);

	cout << "Lemmikin laji: ";
	string lemmikin_laji;
	getline(cin, lemmikin_laji);

	cout << "Mita lemmikki teki: ";
	string lemmikki_teki;
	getline(cin, lemmikki_teki);

	cout << aloitus << ", " << opettaja;
	cout << ". En tieda mihin se " << laji << " joutui! ";
	cout << "Lemmikki" << lemmikin_laji << "ni " << lemmikin_nimi;
	cout << " varmaankin " << lemmikki_teki << " sen.";
}
