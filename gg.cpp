#include "duomenys.h"

int main()
{
	auto start = high_resolution_clock::now();
	duomenys D;
	ifstream klasiokai;
	klasiokai.open("studentai.txt");
	ofstream mldc;
	mldc.open("kieti.txt");

	mldc << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(33) << "Galutinis balas (Vid.)" << setw(25) << "Galutinis (Med.)" << endl;
	mldc << setfill('-') << setw(90) << "-" << endl;

	try {
		if (klasiokai.is_open())
		{
			klasiokai >> D.var >> D.pav;
			while (D.q != "Egz.") // perskaito visus namu darbus kiek ju yra
			{
				klasiokai >> D.q;
				if (D.q == "Egz.") {//teko iterpt nes nezinia del ko while nesibaidavo
					break;
				}
				D.ilgis++;
			}





			auto startt = high_resolution_clock::now();
			while (!klasiokai.eof())
			{
				klasiokai >> D.vardas >> D.pavarde;
				int xxx;
				for (int i = 1; i <= D.ilgis; i++)
				{
					klasiokai >> xxx;
					D.ndp.push_back(xxx);

				}
				klasiokai >> D.egzp;
				sort(D.ndp.begin(), D.ndp.end());
				D.galbal = (double)accumulate(D.ndp.begin(), D.ndp.end(), 0) / D.ndp.size() * 0.4 + D.egzp * 0.6;

				if (D.ndp.size() % 2 != 0)
				{
					D.med = (double)D.ndp[D.ndp.size() / 2];
				}
				else
				{
					D.med = (double)(D.ndp[(D.ndp.size() - 1) / 2] + D.ndp[D.ndp.size() / 2]) / 2.0;
				}

				D.ndp.clear();

				if (D.galbal < 5)
				{
					D.gaidz.push_back(D);
				}
				else
				{
					mldc << setfill(' ') << setw(17) << D.vardas << setw(20) << D.pavarde << setw(14) << setprecision(2) << fixed << D.galbal << setw(31) << setprecision(2) << fixed << D.med << endl;
				}
			}

			duration<double> di = high_resolution_clock::now() - startt;
			cout << "skirstymas i viena grupe ir irasymas vienos grupe truko: " << di.count() << " " << D.ilgis << endl;
			rasom(D.gaidz);
			D.gaidz.clear();

		}

	}
	catch (const ifstream::failure& e)
	{
		cout << "Nepavyko atidaryti failo";
	}
	mldc.close();
	klasiokai.close();

	duration<double> diff = high_resolution_clock::now() - start;
	cout << "viso failo skaitymas truko: " << diff.count() << endl;



	return 0;
}