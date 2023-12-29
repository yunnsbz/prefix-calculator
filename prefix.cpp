#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

bool islemKontrol(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool sayýKontrol(char c) { //karakter 0-9 arasýnda mý
    return (c >= 48 && c <= 57);
}

int islemYap(char islem, int sayi1, int sayi2) {
    switch (islem) {
    case '+':
        return sayi1 + sayi2;
    case '-':
        return sayi1 - sayi2;
    case '*':
        return sayi1 * sayi2;
    case '/':
        return sayi1 / sayi2;
    default:
        return 0;
    }
}

// * + * + 1 2 + 3 4 5 6

int prefixOku(string input) {
    stack<int> islemSonuclari;

    string output = input;

    for (int i = input.length() - 1; i >= 0; i--) {
        if (input[i] == ' ') {
            continue;
        }

        else if (islemKontrol(input[i])) {
            int sayi1 = islemSonuclari.top();
            islemSonuclari.pop();

            int sayi2 = islemSonuclari.top();
            islemSonuclari.pop();

            int sonuc = islemYap(input[i], sayi1, sayi2);
            islemSonuclari.push(sonuc);

            //her adýmý ekrana yazdýrma
            int indexIkinciParca = i + 2 + to_string(sayi1).length() + to_string(sayi2).length() + 1;
            output = output.substr(0, i) + to_string(sonuc) + output.substr(indexIkinciParca, output.length() - 1);
            cout << output << endl;

        }

        else if (sayýKontrol(input[i])) {
            string sayi = "";
            while (i >= 0 && sayýKontrol(input[i])) {
                //önceden aldýðý sayýnýn saðýna ekliyorum    45
                sayi = input[i] + sayi;
                i--;
            }
            i++;
            islemSonuclari.push(stoi(sayi));
        }
    }

    return islemSonuclari.top();  //geriye kalan inputun sonucu olur
}


int main() {
    string input;
    cout << "Prefix ifadeyi girin:\n\n";
    getline(cin, input);


    int sonuc = prefixOku(input);
    cout << "\nSonuc: " << sonuc << endl;

    return 0;
}
