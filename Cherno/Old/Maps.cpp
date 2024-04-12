#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

struct CityRecord {
    std::string Name;
    uint64_t Population;
    double Latitude, Longitude;

    // Comparison operator overload
    bool operator<(const CityRecord& other) const {
        return Name < other.Name; // You can define the comparison based on any field
    }
};

namespace std {
template <>
struct hash<CityRecord> {
    size_t operator()(const CityRecord& key) const {
        return hash<std::string>()(key.Name);
    }
};
}  // namespace std

int main() {
    std::unordered_map<std::string, CityRecord> cityMap;
    cityMap["Toronto"] = CityRecord{"Toronto", 2731571, 43.7, -79.42};
    cityMap["New York"] = CityRecord{"New York", 8175133, 40.7, -74.0};
    cityMap["San Francisco"] =
        CityRecord{"San Francisco", 870887, 37.7, -122.4};

    cityMap["Los Angeles"] = CityRecord{"Los Angeles", 3971883, 34.0, -118.2};

    // std::map<CityRecord, uint32_t> cityFounded;
    // cityFounded["Toronto", 2731571, 43.7, -79.42];


    CityRecord& TorontoData = cityMap["Toronto"];
    std::cout << "Population of Toronto: " << TorontoData.Population << std::endl;

    const auto& cities = cityMap;
    if (cities.find("Toronto") != cities.end()) {
        const CityRecord& torontoData = cities.at("Toronto"); 
    }

    CityRecord& newYorkData = cityMap["New York"];
    newYorkData.Name = "New York City";
    newYorkData.Population = 1000000;

    for (const auto& [name, city] : cityMap) {
        std::cout << "City: " << name << ", Population: " << city.Population << std::endl;
    }

    cityMap.erase("Toronto");
    std::cout << "----------" << std::endl;
    for (const auto& kv : cityMap) {
        const std::string& name = kv.first;
        const CityRecord& city = kv.second;
        std::cout << "Name: " << name << " population: " << city.Population << std::endl;
    }

    return 0;
}

