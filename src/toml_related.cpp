#include "../headers/toml_related.h"

bool openConfig(std::string const &cfg_path, std::string const &value, std::set<std::string> &unique_path){
    toml::value cfg_data;
    try{
        cfg_data = toml::parse(cfg_path);
    }catch(const std::runtime_error &err){
        return false;
    }
    std::vector<std::string> data;
    try {
        data = toml::find<std::vector<std::string>>(cfg_data, value);
    }catch(const std::out_of_range& e){
        std::cerr << "Couldn't find specified string vector" << std::endl;
        return false;
    }
    for(const auto &file: data){ //rewrite all file names into a set, if file name matches with the name inside of set - don't save it
        if(unique_path.find(file) == unique_path.end()) {
            unique_path.insert(file);
        }
    }
    return true;
}