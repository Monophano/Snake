#pragma once

#include <fstream>
#include <cstring>

/// @brief Classe chargé d'ouvrir un fichier passé en paramètre au constructeur et écrire dessus ou lire ses données
class File
{
    public:
        /// @brief Constructeur de la classe
        /// @param file_name nom du fichier à ouvrir
        File(std::string file_name);

        /// @brief Méthode permettant de récupérer les données du fichier texte courant
        /// @return données récupérés dans le fichier
        std::string get_data();

        /// @brief Méthode permettant d'écrire dans le fichier courant
        /// @param value valeur à écrire dans la fichier
        void set_data(std::string value);

    private:
        std::string file_name;
};
