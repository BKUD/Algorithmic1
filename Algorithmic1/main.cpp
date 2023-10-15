#include <iostream>
#include <fstream>
#include <map>

// ��������� ��� �������� ���������� � ������
struct Product {
    std::string name;
    double price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("products.txt");
    std::map<std::string, Product> products;

    // ���������� ������ �� �����
    Product temp;
    // �������
    std::string code;
    while (file >> temp.name >> code >> temp.price) {
        if (products.count(code) && products[code].name != temp.name) {
            std::cout << "������: ��� ������ ����� ���������� �������, �� ������ ��������." << std::endl;
            return 1;
        }
        products[code] = temp;
    }

    // ����� ������ 10 �������
    int count = 0;
    for (const auto& pair : products) {
        if (count >= 10) break;
        std::cout << pair.second.name << " " << pair.first << " " << pair.second.price << std::endl;
        ++count;
    }

    // �������� ������� ������ � �������� �����
    std::cout << "������� ��� ������: ";
    std::cin >> code;

    if (products.count(code)) {
        std::cout << "����� � ����� ����� ���� � ������." << std::endl;
    }
    else {
        std::cout << "������ � ����� ����� ��� � ������." << std::endl;
    }

    return 0;
}
