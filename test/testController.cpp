//
// Created by Марат Гасанов on 14.05.2022.
//

#include "gtest/gtest.h"
#include "iostream"
#include "controller.h"
#include "../ControllerObservable/ControllerObservable.h"
#include "vector"
#include "Algo.h"

PTR<ProjectionPlane> oxy(new ProjectionPlane(0, 0, 1, 0));
PTR<ProjectionPlane> oxz(new ProjectionPlane(1, 0, 0, 0));

// Mock Classes
class mockGUI:public GUIObserver{
public:
    PTR<Renderable> renderable;
    void onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) override {
        object->setRenderable(renderable);
        object->render();
    }

    void onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) override {
        //
    }

    void onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object) override {
        object->setRenderable(renderable);
        object->deleteFromRender();
    }

    void onAddAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> algorithm) override {
        //
    }
};

class mockUI : public Renderable{
    ControllerObservable* controller;
public:
    std::vector<PTR<Entity>> allProjected;
    mockUI(ControllerObservable* co){
        controller = co;
    }

    void clickMouse(int x, int y){
        PTR<Entity> point(new PointByCoords(x, y, 1));
        allProjected.push_back(point);
    }

    void addLineByTwoPoints(int index1, int index2){
        controller->onCreateLineByTwoPoint(allProjected[index1], allProjected[index2]);
    }

    void deleteEntity(int index){
        controller->onDeleteEntity(allProjected[index]);
    }

    void addPoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name, TwoDPoint *twoDEntity) override {
        std::cout << "Add point with : " << std::endl;
        std::cout << "X: " << x << "; Y:" << y << std::endl;
    }

    void addLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) override {
        std::cout << "Add line with : " << std::endl;
        std::cout << "Point 1: ";
        std::cout << "X: " << x1 << "; Y:" << x1 << std::endl;
        std::cout << "Point 2: ";
        std::cout << "X: " << x2 << "; Y:" << y2 << std::endl;
    }

    void deletePoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) override {
        std::cout << "Deleting point with : " << std::endl;
        std::cout << "X: " << x << "; Y:" << y << std::endl;
    }

    void
    deleteLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) override {
        std::cout << "Deleting line with : " << std::endl;
        std::cout << "Point 1: ";
        std::cout << "X: " << x1 << "; Y:" << x1 << std::endl;
        std::cout << "Point 2: ";
        std::cout << "X: " << x2 << "; Y:" << y2 << std::endl;
    }

    void addPlaneByLineAndPoint(int x, int y, int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber,
                                std::string name, TwoDEntity *twoDEntity) override {
        //
    }

    void addLinkLine(PTR<TwoDEntity> entity1, PTR<TwoDEntity> entity2) override {
        //
    }
};

TEST(basic, Test){
    AlgoInterface* algo = new Algo;
    PTR<mockGUI> gui = MAKEPTR<mockGUI>();
    Render* render = new Render(gui);
    ControllerObservable* controller = new Controller(render, algo);
    PTR<mockUI> ui = MAKEPTR<mockUI>(controller);
    gui->renderable = ui;
    ui->clickMouse(12, 7);
    ui->clickMouse(11, 8);
    ui->addLineByTwoPoints(0, 1);
    EXPECT_NO_THROW();
}

TEST(changeEntity, TestIterativeDeleting){
    AlgoInterface* algo = new Algo;
    PTR<mockGUI> gui = MAKEPTR<mockGUI>();
    Render* render = new Render(gui);
    ControllerObservable* controller = new Controller(render, algo);
    PTR<mockUI> ui = MAKEPTR<mockUI>(controller);
    gui->renderable = ui;
    ui->clickMouse(12, 7);
    ui->clickMouse(11, 8);
    ui->addLineByTwoPoints(0, 1);
    ui->deleteEntity(0);
    EXPECT_NO_THROW();
}