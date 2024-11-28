#include "headers/file.hpp"

File::File(std::string file_name)
{
    this->file_name = file_name;
}

std::string File::get_data()
{
    std::string value = "";
    std::ifstream read_file(this->file_name);

    if (read_file)
        std::getline(read_file, value);

    read_file.close();

    return value;
}

void File::set_data(std::string value)
{
    std::ofstream write_file(this->file_name);

    if (write_file)
        write_file << value;

    write_file.close();
}
