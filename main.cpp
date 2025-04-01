/*
Esercizio 2, Esercitazione 1 IO
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void mapped_value(double &value);

int main()
{
    // Apertura del file di input
    std::ifstream input_file; 
    input_file.open("data.txt");

    // Controllo che il file di input sia stato aperto correttamente
    if(input_file.fail()){
        std::cerr << "Errore nell'apertura del file!" << std::endl;
        return 1;
    }


    // Apertura del file di output
    std::ofstream file_output("result.txt");

    // Scrivo sul file di output la riga di intestazione
    file_output << "# N Mean" << std::endl;

    // Scelgo il corretto formato di stampa sul file di output
    file_output << std::setprecision(16) << std::scientific;


    // Leggo i valori del file
    double sum = 0;
    double value;
    int n = 0;

    while (input_file >> value){
        mapped_value(value); // effettuo il cambio di scala del valore appena letto
        sum += value;
        n += 1;

        //std::cout << "valore: " << value << "valore mappato: " << mapped_value(value) << std::endl;
        file_output << n << " " << sum/((double)n) << std::endl;
    }

    input_file.close(); // chiudo il file di input
    file_output.close(); // chiudo il file di output

    return 0;
}



void mapped_value(double &value){
    /* se x appartiene all'intervallo [1, 5], il punto y corrispondente nel punto [-1,2]
    è tale per cui (x-1)/(5-1) = (y-(-1))/(2-(-1))
    quindi y = (x-1)*(2-(-1))/(5-1) + (-1) = (x-1)*3/4 - 1  */

    value = (value-1)*3/4 -1;
}
