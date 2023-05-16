
#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;
class Oy {
private:
    string aday;
public:
    Oy(string aday) : aday(aday) {}

    string getAday() const {
        return aday;
    }
};

class Secmen {
private:
    string isim;
    vector<Oy> oyListesi;
public:
    Secmen(string isim) : isim(isim) {}

    void oyKullan(Oy oy) {
        oyListesi.push_back(oy);
    }

    string getIsim() const {
        return isim;
    }

    vector<Oy> getOyListesi() const {
        return oyListesi;
    }
};
class Secim {
private:
    vector<Secmen> secmenListesi;
    int oySayisiAday1;
    int oySayisiAday2;
    int oySayisiParti1;
    int oySayisiParti2;
    int oySayisiParti3;
public:
    Secim() : oySayisiAday1(0), oySayisiAday2(0), oySayisiParti1(0), oySayisiParti2(0), oySayisiParti3(0) {}

    void secmenEkle(Secmen secmen) {
        secmenListesi.push_back(secmen);
    }

    void oyHesapla() {
        for (const auto& secmen : secmenListesi) {
            vector<Oy> oyListesi = secmen.getOyListesi();
            for (const auto& oy : oyListesi) {
                if (oy.getAday() == "Ali ") {
                    oySayisiAday1++;
                } else if (oy.getAday() == "Veli") {
                    oySayisiAday2++;
                } else if (oy.getAday() == "A Partisi") {
                    oySayisiParti1++;
                } else if (oy.getAday() == "B Partisi") {
                    oySayisiParti2++;
                } else if (oy.getAday() == "C Partisi") {
                    oySayisiParti3++;
                }
            }
        }
    }

    void sonuclariGoster() {
        cout << "Cumhurbaşkanlığı adaylarından Ali: " << oySayisiAday1 << " oy\n";
        cout << "Cumhurbaşkanlığı adaylarından Veli: " << oySayisiAday2 << " oy\n";
        cout << "Milletvekilliği partilerinden A Partisi: " << oySayisiParti1 << " oy\n";
        cout << "Milletvekilliği partilerinden B Partisi: " << oySayisiParti2 << " oy\n";
        cout << "Milletvekilliği partilerinden C Partisi: " << oySayisiParti3 << " oy\n";

}
};
int main() {
    Secim secim;
    setlocale(LC_ALL, "Turkish");
    for (int i = 0; i < 10; i++) {
        string secmenIsim;
        cout << "Seçmen ismi: ";
        cin >> secmenIsim;

        Secmen secmen(secmenIsim);

        for (int j = 0; j < 2; j++) {
            string oy;
            cout << "Oy " << j + 1 << ": ";
            cin >> oy;

            secmen.oyKullan(Oy(oy));
        }

        secim.secmenEkle(secmen);
    }

    secim.oyHesapla();
    secim.sonuclariGoster();

    return 0;
}
