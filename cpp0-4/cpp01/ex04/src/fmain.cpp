#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //para exit
// --- Colores para la salida en consola ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
// Funcion para mostrar un mensaje de error y terminar
void exitWithError(const std::string& message)
{
    std::cerr << BOLD << RED << "Error: " << message << RESET << std::endl;
    exit(1);
}
int main(int argc, char **argv)
{
    // Comprobamos que el numero de argumentos sea correcto (4)
    if (argc != 4)
    {
        std::cerr << BOLD << YELLOW << "Uso: " << argv[0]
                  << " <nombre_archivo> <palabra_a_buscar> <palabra_de_reemplazo>"
                  << RESET << std::endl;
        return (1);
    }
    // Guardamos los argumentos en variables
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string outfilename = filename + ".replace";
    // Proteccion: la palabra a buscar no puede estar vacia
    if (s1.empty())
        exitWithError("La palabra a buscar no puede estar vacia.");
    // Abrimos el archivo de entrada
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        exitWithError("No se ha podido abrir el archivo de entrada: " + filename);
    // Creamos el archivo de salida
    std::ofstream outputFile(outfilename.c_str());
    if (!outputFile.is_open())
        exitWithError("Error, no se ha podido crear el archivo de salida: " + outfilename);
    std::cout << CYAN << "Procesando : " << BOLD << filename << RESET << std::endl;
    // Leemos el archivo linea por linea
    std::string line;
    while (std::getline(inputFile, line))
    {
        //  Buscamos y reemplazamos todas las ocurrencias de s1 en la linea
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        // Escribimos la linea modificada en el archivo de salida
        outputFile << line << std::endl;
    }
    // Cerramos los archivos
    inputFile.close();
    outputFile.close();
    std::cout << GREEN << "Proceso completado.Salida creada: "
              << BOLD << outfilename << RESET << std::endl;
    return (0);
}
