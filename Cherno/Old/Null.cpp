#include <iostream>

class Entity {
public: Entity() = default;
	  const std::string& GetName() const { return m_Name; }

	  void PrintType() {
		  std::cout << "Entity\n";
	}

private:
	Entity* m_Parent;
	std::string m_Name;
};

struct EntityData {
	EntityData* m_Parent; // 0
	std::string m_Name; // 8
};

const std::string& Entity_GetName(const EntityData* self) {
	// self == nullptr
	uint64_t offset = offsetof(EntityData, m_Name);
	return self->m_Name;
}

void Entity_PrintType(const EntityData* self) {
	// self == nullptr
	std::cout << "Entity\n";
}

int main() {
	Entity* entity = nullptr;
	entity->PrintType();
	uint64_t offset = offsetof(EntityData, m_Name);
	offset = (uint64_t)& ((EntityData*)nullptr)->m_Name; 
	//  ((EntityData*)nullptr)->m_Name; is a bit-shit from null to m_Name to determine the offset (bytes distance)
	// Then take address of the way

	std::cout << "Offset of m_Name: " << offset << std::endl;
	std::cout << entity->GetName() << std::endl;
	
	return 0;
}