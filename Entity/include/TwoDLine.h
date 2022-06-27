//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_TWODLINE_H
#define EDUCAD_TWODLINE_H
#include "Entity.h"

class TwoDLine : public TwoDEntity{
private:
public:
    double getA() const;

    double getB() const;

    double getC() const;

private:
    double A;
    double B;
    double C;
public:
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2, PTR<ProjectionPlane> plane);
    void render();
    void deleteFromRender();

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;
};

#endif //EDUCAD_TWODLINE_H
