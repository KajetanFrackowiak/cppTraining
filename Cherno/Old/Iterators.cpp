#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // for (int i = 0; i < vec.size(); i++) {
    //     std::cout << vec[i] << std::endl;
    // }

    // for (auto& value : vec) {
    //     std::cout << value << std::endl;
    // }

    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    //     std::cout << *it << std::endl;
    // }
    
    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Cherno"] = 5;
    map["C++"] = 5;
    map["C"] = 3;
    map["Java"] = 2;
    map["Python"] = 3;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << std::endl;
    }
    std::cout << std::endl;

    for (auto kv : map) {
        auto& key = kv.first;
        auto& value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }
    std::cout << std::endl;

    for (auto& [key, value] : map) {
        std::cout << key << " = " << value << std::endl;
    }

    size_t size = map.size();
    size_t middle_posstion = size / 2;

    // Iterator to the middle element
    auto it = map.begin();
    std::advance(it, middle_posstion);

    std::cout << "Middle element: " << it->first << " = " << it->second << std::endl;

    return 0;
}