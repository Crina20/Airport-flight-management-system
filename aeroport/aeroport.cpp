#include<iostream>
#include<string>
#include<iomanip>

class Zbor {
private:
    std::string orass, orasp;
    int orap, minp, oras, mins;

public:
    void set_orass(std::string orass) { this->orass = orass; }
    void set_orasp(std::string orasp) { this->orasp = orasp; }
    void set_orap(int orap) { this->orap = orap; }
    void set_minp(int minp) { this->minp = minp; }
    void set_oras(int oras) { this->oras = oras; }
    void set_mins(int mins) { this->mins = mins; }

    std::string get_orass() { return orass; }
    std::string get_orasp() { return orasp; }
    int get_orap() { return orap; }
    int get_minp() { return minp; }
    int get_oras() { return oras; }
    int get_mins() { return mins; }

    void afisare()
    {
        std::cout << orasp << " - " << orass << '\n';
        std::cout << orap << ":" << minp << " - " << oras << ":" << mins << '\n';
    }

    void subpunct1(int nrzbor, Zbor vector[], int n)
    {
        if (n == 0)
        {
            for (int i = 0; i < nrzbor; ++i)
            {
                if (vector[i].get_orasp() == "Bucuresti")
                {
                    vector[i].afisare();
                }
            }
        }
        else if (n == 1)
        {
            for (int i = 0; i < nrzbor; ++i)
            {
                if (vector[i].get_orass() == "Bucuresti")
                {
                    vector[i].afisare();
                }
            }
        }
    }
    void subpunct2(int nrzbor, Zbor vector[], int o1, int m1, int o2, int m2)
    {
        for (int i = 0; i < nrzbor; ++i)
        {
            if (vector[i].get_orasp() == "Bucuresti")
            {
                if (vector[i].get_orap() >= o1 && vector[i].get_minp() >= m1 && vector[i].get_oras() <= o2 && vector[i].get_mins() <= m2)
                {
                    vector[i].afisare();
                }
            }
        }
    }

    void subpunct3(int nrzbor, int distanta)
    {
        int o = 0, m = 0;
        float p = 0;

        o = oras - orap;
        if (mins < minp)
        {
            m = 60 - (minp - mins);
            p = -1;
        }
        else
        {
            m = mins - minp;
        }
        p += (o + (float(m) / 60));

        std::cout << orasp << " - " << orass << '\n';
        std::cout << orap << ":" << minp << " - " << oras << ":" << mins << '\n';
        std::cout << std::fixed << std::setprecision(2) << (float(distanta) / p) << std::endl;
    }

    void subpunct4(int nrzbor, int distanta)
    {
        int o = 0, m = 0;
        float suma = 0, p = 0, cost = 0, profit = 0, pretBilete = 0, pretCombustibil = 0;

        o = oras - orap;
        if (mins < minp)
        {
            m = 60 - (minp - mins);
            o--;
        }
        else
        {
            m = mins - minp;
        }
        p = (o + (float(m) / 60)); // timpul de zbor
        pretCombustibil = float(10000 * p);
        pretBilete = float(0.15 * distanta * 400);
        profit = pretBilete - pretCombustibil;
        std::cout << orasp << "-" << orass << "\n";
        std::cout << std::fixed << std::setprecision(2) << float(profit) << "\n";
    }
};

int main()
{
    Zbor zboruri[20];
    std::string orass, orasp;
    int orap, minp, oras, mins, nrzbor, distanta[20];
    std::cin >> nrzbor;

    for (int i = 0; i < nrzbor; ++i)
    {

        std::cin >> orasp;
        std::cin >> orass;
        std::cin >> orap >> minp >> oras >> mins;

        zboruri[i].set_orasp(orasp);
        zboruri[i].set_orass(orass);
        zboruri[i].set_orap(orap);
        zboruri[i].set_minp(minp);
        zboruri[i].set_oras(oras);
        zboruri[i].set_mins(mins);
    }
    int comanda;
    std::cin >> comanda;

    switch (comanda)
    {
    case 1:
        int n;
        std::cin >> n;
        zboruri[0].subpunct1(nrzbor, zboruri, n);
        break;
    case 2:
        int o1, m1, o2, m2;
        std::cin >> o1 >> m1;
        std::cin >> o2 >> m2;

        zboruri[0].subpunct2(nrzbor, zboruri, o1, m1, o2, m2);
        break;

    case 3:
        for (int i = 0; i < nrzbor; ++i)
            std::cin >> distanta[i];
        for (int i = 0; i < nrzbor; ++i)
            zboruri[i].subpunct3(nrzbor, distanta[i]);
        break;

    case 4:
        for (int i = 0; i < nrzbor; ++i)
        {
            std::cin >> distanta[i];
        }
        for (int i = 0; i < nrzbor; ++i)
            zboruri[i].subpunct4(nrzbor, distanta[i]);
    }


}