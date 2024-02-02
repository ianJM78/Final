#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct vaccinated_data
{
    int grupo;
    int vacunados;
    int noVacunados;
};


struct relevant_data
{
    float promedio_vacunados = 0.0;
    int totalVacunados = 0;
    int total_noVacunados = 0;
    int total_number_of_people = 0;
};


class investigation
{
private:
    vaccinated_data DATA[100];
    int length_DATA = 0;
    relevant_data RELEVANT_DATA;
    
public:
    investigation(string path_data);
    int get_length_DATA();
    vaccinated_data get_DATA_elemennt(int i);

    void promedio_vacunados_y_no_vacunados();
    void guardar_en_archivo_de_resultados(string path_resultados);
};

investigation::investigation(string path_data)
{
    vaccinated_data auxiliary;
    ifstream value(path_data);
    while (!value.eof())
    {
        value >> auxiliary.grupo >> auxiliary.vacunados >> auxiliary.noVacunados;
        DATA[length_DATA] = auxiliary;
        length_DATA++;
    }
}



int investigation::get_length_DATA()
{
    return length_DATA;
}

vaccinated_data investigation ::get_DATA_elemennt(int i)
{
    return DATA[i];
}


void investigation ::promedio_vacunados_y_no_vacunados()
{
    RELEVANT_DATA.promedio_vacunados = 0.0;
    RELEVANT_DATA.total_noVacunados = 0;
    RELEVANT_DATA.totalVacunados = 0;
    RELEVANT_DATA.total_number_of_people = 0;

    for (int i = 0; i < length_DATA; i++)
    {
        RELEVANT_DATA.totalVacunados += DATA[i].vacunados;
        RELEVANT_DATA.total_noVacunados += DATA[i].noVacunados;
    }

    RELEVANT_DATA.total_number_of_people = (RELEVANT_DATA.totalVacunados + RELEVANT_DATA.total_noVacunados);
    RELEVANT_DATA.promedio_vacunados = RELEVANT_DATA.totalVacunados / RELEVANT_DATA.total_number_of_people;
    // cout << "total yes " << RELEVANT_DATA.totalVacunados << endl;
    // cout << "total no " << RELEVANT_DATA.total_noVacunados << endl;
    // cout << "total " << RELEVANT_DATA.total_number_of_people << endl;
    // cout  << "Promedio " << RELEVANT_DATA.promedio_vacunados << endl;
    //(RELEVANT_DATA.totalVacunados * 100) / (RELEVANT_DATA.total_number_of_people);
}




void investigation ::guardar_en_archivo_de_resultados(string path_resultados)
{
    ofstream value(path_resultados);

    value << "RESULTADO DEL PROCESO" << endl;
    value << "=====================" << endl;
    value << "Total vacunados: " << RELEVANT_DATA.totalVacunados << endl;
    value << "Total no vacunados: " << RELEVANT_DATA.total_noVacunados << endl;
    value << "Promedio: " << RELEVANT_DATA.promedio_vacunados << " %" <<  endl;

}

int main()
{
    string path_data = "C:/UNI/PROGRAMING/FINAL/data.txt";
    string path_resultado = "C:/UNI/PROGRAMING/FINAL/resultado.txt";
    investigation A(path_data);

    //! Print DATA vector
    int length_DATA = A.get_length_DATA();
    for (int i = 0; i < length_DATA; i++)
    {
        vaccinated_data auxiliar = A.get_DATA_elemennt(i);
        cout << auxiliar.grupo << " | " << auxiliar.vacunados << " | " << auxiliar.noVacunados << endl;
    }
    
    //! CALCULATE relevant data
    A.promedio_vacunados_y_no_vacunados();

    //! GUARDAR en archivo de resultados
    A.guardar_en_archivo_de_resultados(path_resultado);
    
}