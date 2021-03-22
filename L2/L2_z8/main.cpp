#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void sort_usd(std::vector<Exchange_rate> &v){
    bool pom;
    do{
        pom=0;
        size_t rozmiar=v.size();
        for(size_t i=0;i<rozmiar-1;i++){
            if(v[i].usd<v[i+1].usd){
                std::swap(v[i],v[i+1]);
                pom=1;
            }
        }
        rozmiar--;
    }while(pom==1);
}

void sort_eur(std::vector<Exchange_rate> &v){
    bool pom;
    do{
        pom=0;
        size_t rozmiar=v.size();
        for(size_t i=0;i<rozmiar-1;i++){
            if(v[i].eur<v[i+1].eur){
                std::swap(v[i],v[i+1]);
                pom=1;
            }
        }
        rozmiar--;
    }while(pom==1);
}

int binary_search(const std::vector<Exchange_rate> &v, double sz){
    size_t l=0, r=v.size()-1;
    int m;
    while(l<=r){
        m=(l+r)/2;
        if(v[m].usd==sz){
            return m;
        }
        if(v[m].usd>sz){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return -1;
}
int main()
{
    std::fstream file("kursy_usd_eur.csv", std::fstream::in);
    std::vector<Exchange_rate> rates;
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);                // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {       //wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);         //tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            std::getline(str, er.date, ',');     //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er);              //dodaje element do kolekcji
        }
    }
    sort_usd(rates);
    std::cout<<"10 dni z najwyższym kursem USD:"<<std::endl;
    for(size_t i=0;i<10;i++){
        std::cout<<rates[i].date<<"   "<<rates[i].usd<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"10 dni z najniższym kursem EUR:"<<std::endl;
    sort_eur(rates);
    for(int i=0; i<10; i++){
        size_t j=rates.size()-1;
        std::cout<<rates[j-i].date<<"   "<<rates[j-i].usd<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    double x=3.9011;
    sort_usd(rates);
    size_t szukana=binary_search(rates,x);
    std::cout<<"Kurs wynosił 3.9011 dnia: "<<rates[szukana].date<<std::endl;
    return 0;
}
