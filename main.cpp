#include <iostream>
#include "factory.hpp"
#include "editor.hpp"

void help() {
    std::cout << "help - выводит это меню\n"
                 "create <path> - создает новый файл\n"
                 "save - сохраняет данные в файл\n"
                 "load <path> - выгружает данные из файла\n"
                 "add <pentagon, hexagon, octagon> <vertices> - добавить фигуру\n"
                 "remove <index> - удаляет фигуру по индексу\n"
                 "print - выводит все фигуру\n"
                 "undo - отменяет последнее действие\n"
                 "exit\n";
}

void create(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    edit.CreateDocument(tmp);
    std::cout << "OK\n";
}

void load(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    try {
        edit.LoadDocument(tmp);
        std::cout << "OK\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.SaveDocument();
        std::cout << "OK\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<figure> newElem = fac.FigureCreate(std::cin);
        edit.InsertInDocument(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "Ok\n";
}

void remove(editor& edit) {
    uint32_t index;
    std::cin >> index;
    try {
        edit.DeleteInDocument(index);
        std::cout << "OK\n";
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    std::string command;
    while (true) {
        std::cin >> command;
        if (command == "help") {
            help();
        } else if (command == "create") {
            create(edit);
        } else if (command == "load") {
            load(edit);
        } else if (command == "save") {
            save(edit);
        } else if (command == "exit") {
            break;
        } else if (command == "add") {
            add(edit);
        } else if (command == "remove") {
            remove(edit);
        } else if (command == "print") {
            edit.PrintDocument();
        } else if (command == "undo") {
            try {
                edit.Undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "Unknown command\n";
        }
    }
    return 0;
}