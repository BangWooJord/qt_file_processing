#include "../headers/file_related.h"
#include <cstring>

int binary_write(std::string const &filename, std::string const &path, const char *data){
    char dash = (path.back() != '\\' && path.back() != '/')? '/' : NULL; // checking if the file path came with / \ on the end !=> assigning one
    std::string full_path = path + dash + filename + ".bin";
    std::ofstream file_write(full_path.c_str(), std::ios::binary | std::ios::app);
    if(!file_write) return ERROR_OPENING_OFILE;
    size_t data_size = strlen(data);
    //wf.write((char*)&data_size, sizeof(data_size));
    int i = 0;
    while (i < 60077770){
        long double wr = rand()%77777*i;
        file_write.write((char*)&wr, sizeof(wr));
        ++i;
    }
    // wf.write(data, data_size);
    file_write.close();
    return 0;
}
int binary_read(std::string const &path, long double &data, uint32_t file_size){
    std::ifstream file_read(path.c_str(), std::ios::binary);
    if(!file_read) return ERROR_OPENING_IFILE;
    file_read.seekg (0, std::ifstream::beg);
    while(file_read.read((char*)&data, sizeof(data))){
        process_data(data);
    }
    file_read.close();
    return 0;
}

void process_data(long double data){
    data = 0;
}

uint32_t file_length(std::string const &path){
    std::ifstream file_read(path.c_str(), std::ios::binary);
    if(!file_read) return ERROR_OPENING_IFILE;
    file_read.seekg (0, file_read.end);
    uint32_t file_size = file_read.tellg();
    file_read.close();
    return file_size;
}

bool remove_path(std::string &full_path){
    for(auto i = full_path.size()-1; i >=0; --i){
        if(full_path[i] == '\\' || full_path[i] == '/'){
            full_path.erase(0, i+1);
            return true;
        }
    }
    return false;
}