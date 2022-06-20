//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_RENDERABLE_H
#define EDUCAD_RENDERABLE_H
#include "string"
#include "Entity.h"

class Renderable{
public:
    virtual void addPoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name, TwoDPoint* twoDEntity) = 0;
    virtual void addLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void deletePoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void deleteLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void addPlaneByLineAndPoint (int x, int y, int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name, TwoDEntity* twoDEntity)=0;
    virtual void addLinkLine(PTR<TwoDEntity> entity1, PTR<TwoDEntity> entity2) = 0;
};

#endif //EDUCAD_RENDERABLE_H
