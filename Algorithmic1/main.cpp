#include <iostream>
#include <fstream>
#include <map>

// Структура для хранения информации о товаре
struct Product {
    std::string name;
    double price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("products.txt");
    std::map<std::string, Product> products;

    // Считывание данных из файла
    Product temp;
    // Артикул
    std::string code;
    while (file >> temp.name >> code >> temp.price) {
        if (products.count(code) && products[code].name != temp.name) {
            std::cout << "Ошибка: два товара имеют одинаковый артикул, но разные названия." << std::endl;
            return 1;
        }
        products[code] = temp;
    }

    // Вывод первых 10 товаров
    int count = 0;
    for (const auto& pair : products) {
        if (count >= 10) break;
        std::cout << pair.second.name << " " << pair.first << " " << pair.second.price << std::endl;
        ++count;
    }

    // Проверка наличия товара с заданным кодом
    std::cout << "Введите код товара: ";
    std::cin >> code;

    if (products.count(code)) {
        std::cout << "Товар с таким кодом есть в списке." << std::endl;
    }
    else {
        std::cout << "Товара с таким кодом нет в списке." << std::endl;
    }

    return 0;
}
