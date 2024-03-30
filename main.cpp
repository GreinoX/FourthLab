/*
 * Name: Third Lab
 * Author: GreinoX
 * Tasks: Circle, Parallelogram
 */
#include <iostream>
#include "VirtualGeoFig.h"
#include <vector>
#define LIST_OF_FIGURES "Figures: ['1 - Circle', '2 - Parallelogram'] - "

class Menu{
public:
    void select(std::string& command, std::vector<Figure*> &figures){
        if(command == "/create-fig") {
            std::cout << "Which figure you want to create: ";
            std::cout << LIST_OF_FIGURES;
            std::cin >> command;
            if (command == "1") {
                Figure* new_figure = new Circle();
                std::cout << "Do you want init circle? (Yes, No)? ";
                std::cin >> command;
                if (command == "Yes") {
                    new_figure->initFromDialog();
                }
                figures.push_back(new_figure);
            }else if(command == "2"){
                Figure* new_figure = new Parallelogram();
                std::cout << "Do you want init circle? (Yes, No)? ";
                std::cin >> command;
                if(command == "Yes"){
                    new_figure->initFromDialog();
                }
                figures.push_back(new_figure);
            }
        }else if(command == "/show-classnames"){
            showNameOfFigures(figures);
        }else if(command == "/size"){
            sizeFigures(figures);
        }else if(command == "/calc-perimeter"){
            std::cout << "Summary perimeter: " << accumulatePerimeter(figures);
        }else if(command == "/calc-square"){
            std::cout << "Summary square: " << accumulateSquare(figures);
        }else if(command == "/show-figures"){
            drawFigures(figures);
        }else if(command == "/del-elem"){
            if(figures.empty()){
                std::cout << "List of figures is empty!" << '\n';
            }
            figures.pop_back();
        }else if(command == "/exit"){
            for(auto element : figures){
                deleteElement(element);
            }
            std::exit(0);
        }else{
            std::cout << "Command does not exist!" << '\n';
        }
    }

    void showNameOfFigures(std::vector<Figure*> &figures){
        for(int i = 0; i < figures.size(); i++) std::cout << i + 1 << ". " << figures[i]->classname() << '\n';
    }

    void sizeFigures(std::vector<Figure*> &figures){
        size_t accumulator = 0;
        for(auto element : figures) accumulator += element->size();
        std::cout << "Size of figures: " << accumulator << '\n';
    }

    void drawFigures(std::vector<Figure*> &figures){
        for(auto element : figures){
            element->draw();
            std::cout << '\n';
        }
    }

    double accumulateSquare(std::vector<Figure*> &figures){
        double accumulator = 0;
        for(auto element : figures) accumulator += element->square();
        return accumulator;
    }

    double accumulatePerimeter(std::vector<Figure*> &figures){
        double accumulator = 0;
        for(auto element : figures) accumulator += element->perimeter();
        return accumulator;
    }

    void deleteElement(Figure* element){
        delete element;
    }
};

int main() {
    std::vector<Figure*> figs;
    Menu menu;

    std::string command;
    while(true){
        std::cout << "Command --> ";
        std::cin >> command;
        if(command == "1"){
            Circle* new_circle = new Circle();
            new_circle->initFromDialog();
            figs.push_back(new_circle);
        }
        menu.select(command, figs);
    }
}
