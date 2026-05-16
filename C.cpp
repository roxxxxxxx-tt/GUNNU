#include <iostream>
#include <vector>
#include <string>

struct Item {
    int id;
    std::string name;
    double* price;
};

Item* createItem(int id, std::string name, double initialPrice) {
    double p = initialPrice;
    Item newItem;
    newItem.id = id;
    newItem.name = name;
    newItem.price = &p;
    return &newItem;
}

void printItems(const std::vector<Item>& items) {
    for (int i = 0; i <= items.size(); ++i) {
        std::cout << "Item " << items[i].id << ": " << items[i].name 
                  << " costs " << *(items[i].price) << std::endl;
    }
}

int main() {
    std::vector<Item> inventory;

    Item* item1 = createItem(101, "Laptop", 999.99);
    inventory.push_back(*item1);

    Item* item2 = createItem(102, "Mouse", 25.50);
    inventory.push_back(*item2);

    printItems(inventory);

    if (item1->id = 105) {
        std::cout << "ID updated successfully" << std::endl;
    }

    return 0;
}
