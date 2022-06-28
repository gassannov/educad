//
// Created by Марат Гасанов on 15.04.2022.
//

#include "iostream"
#include "../include/Entity.h"

TwoDPoint::TwoDPoint(double x, double y, PTR<ProjectionPlane> plane) {
    this->projectionPlane = plane;
    this->X = x;
    this->Y = y;
}

void TwoDPoint::render(std::string name) {
    int direction;
    if (projectionPlane->ordinat->point2->y == 1) {
        direction = 1;
    }
    else if (projectionPlane->ordinat->point2->z == 1) direction = 2;
    this->renderable->addPoint(X, Y, projectionPlane->originPoint->x, projectionPlane->originPoint->y, direction, name,
                               this);
}

void TwoDPoint::deleteFromRender() {
    renderable->deletePoint(this->X, this->Y, 0, 0, 1, "uzbek");
    renderable->deletePoint(this->X, this->Y, 0, 0, 2, "uzbek");
}

PTR<Entity> TwoDPoint::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
//    return PTR<Entity>(new PointByCoords(this->X, ));
}



