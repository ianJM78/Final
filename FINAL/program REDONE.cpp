#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct textData
{
    int group;
    int vaccinated;
    int nonVaccinated;
};

struct relevantData
{
    float promedio_vacunados = 0.0;
    int total_vacunados = 0;
    int total_nonVaccinated;
    int totalPeople;
};


class UNI
{
private:
    vector<textData> DATA;
    relevantData RELEVANT_DATA;
public:
    UNI(string path_data);
    void calculate();
    void save_to_file(string path_resultado);
};

UNI::UNI(string path_data)
{
    ifstream value(path_data);
    textData auxiliary;
    while(!value.eof())
    {
        value >> auxiliary.group >> auxiliary.vaccinated >> auxiliary.nonVaccinated;
        DATA.push_back(auxiliary);
    }

}

void UNI ::calculate()
{
    RELEVANT_DATA.promedio_vacunados = 0.0;
    RELEVANT_DATA.total_nonVaccinated = 0;
    RELEVANT_DATA.total_vacunados = 0;
    RELEVANT_DATA.totalPeople = 0;
    for (textData &element : DATA)
    {
        RELEVANT_DATA.total_vacunados += element.vaccinated;
        RELEVANT_DATA.total_nonVaccinated += element.nonVaccinated;
    }
    RELEVANT_DATA.totalPeople = (RELEVANT_DATA.total_vacunados + RELEVANT_DATA.total_nonVaccinated);
    RELEVANT_DATA.promedio_vacunados = (RELEVANT_DATA.total_vacunados * 100) / RELEVANT_DATA.totalPeople;
}

void UNI ::save_to_file(string path_resultado)
{
    ofstream value(path_resultado);

    value << "RESULTADO DEL PROCESO" << endl;
    value << "=====================" << endl;
    value << "Total vacunados: " << RELEVANT_DATA.total_vacunados << endl;
    value << "Total no vacunados: " << RELEVANT_DATA.total_nonVaccinated << endl;
    value << "Promedio: " << RELEVANT_DATA.promedio_vacunados << " %" <<  endl;

}

int main()
{
    string path_data = "C:/UNI/PROGRAMING/FINAL/data.txt";
    string path_resultado = "C:/UNI/PROGRAMING/FINAL/resultado.txt";

    UNI A(path_data);
    
    A.calculate();
    A.save_to_file(path_resultado);
}