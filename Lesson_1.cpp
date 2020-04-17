#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;
namespace fs = filesystem;

struct vivod
{
	char date[20];
	char value[5];
	char sek[2];
};

int main() {
	while (true)
	{   
		int amount_of_el = 0;
		int prover = 0;
		string pp;

		cout << "Enter the name of the device : "; 
		cin >> pp;
		cout << endl;

		
		for (auto& p : fs :: directory_iterator("logs")) {
			amount_of_el++;
		}

		
			vivod* itog = new vivod[amount_of_el];

		if (pp[0] == '\0' || pp[0] == '1' || pp[0] == '2' || pp[0] == '3' || pp[0] == '4' || pp[0] == '5' || pp[0] == '6' || pp[0] == '7' || pp[0] == '8' || pp[0] == '9'|| pp[0] == '0' || pp[0] == '\n') 
		{

		}
		else {

			int counter = 0;

			for (auto& p : fs::directory_iterator("logs")) {

				string oo = p.path().string();
				int s = 10;
				for (int i = 0; i < 16; i++) {
					itog[counter].date[i] = oo[s];
					s++;
				}
				itog[counter].date[16] = '\0';

				ifstream file(p.path());
				while (file) {
					string pp1;
					getline(file, pp1);
					itog[counter].sek[0] = pp1[0];
					itog[counter].sek[1] = '\0';
					if (pp1[0] == 32 || pp1[0] == '\0') {

					}
					else {
						int trriger = 0;
						int pokaz = 0;

						for (int i = 0; i < 40; i++) {
							if (pp1[i] == 58) {
								trriger++;
							}
							else if (trriger == 1 || trriger == 2) {
								if (trriger == 2) {
									int ee = pp1.size() - i;

									for (int r = 0; r < ee; r++) {
										itog[counter].value[r] = pp1[i + r];
									}
									itog[counter].value[ee] = '\0';
									prover = 1;
									
									counter++;
									break;
								}
								else {
									if (pp1[i] == pp[pokaz]) {


									}
									else if (pp1[i] != pp[pokaz]) {
										break;
									}

									pokaz++;
								}

							}
						}
					}

				}
				file.close();

			}
		}

		if (prover == 1) {
			cout << " Data***Time \t \t value" <<endl;
			cout << endl;

			for (int i = 0; i < amount_of_el; i++) {
				cout << itog[i].date << ":" << itog[i].sek << "\t" << itog[i].value << endl;

			}
		}
		else {
			cout << "device not found" << endl;
		}
	}
	
	return 0;
}
