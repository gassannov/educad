#include "render.h"
#include "time.h"
#include <iostream>
#include "unistd.h"

void Render::addToProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, const std::shared_ptr<Entity>& object) {
    planes.insert(plane);
    PTR<TwoDEntity> projectedEntity = object->getProjection(plane);
    plane->add(projectedEntity);
    object->addProjectionPlane(plane);
    observer->onAddToProjectionPlane(projectedEntity, "uzbek");
}

void Render::deleteFromPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object) const {
    PTR<TwoDEntity> projectedEntity;
    for (const auto& it: plane->projected) {
        if (it->projectedEntity == object){
            projectedEntity = it;
            object->deleteProjectionPlane(plane);
            plane->erase(projectedEntity);
            observer->onDeleteFromProjectionPlane(projectedEntity);
            break;
        }
    }
}

void Render::changeFromProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object) {
    observer->onChangeFromProjectionPlane(object->getProjection(plane));
}

void Render::addProjectionPlane(const PTR<ProjectionPlane>& projectionPlane) {
    planes.insert(projectionPlane);
}

void Render::deleteProjectionPlane(const PTR<ProjectionPlane>& projectionPlane) {
    planes.erase(projectionPlane);
}

void Render::addEntity(const PTR<Entity>& entity, std::string name) {
    for(const auto& it:entity->projections){
        PTR<TwoDEntity> projectedEntity = entity->getProjection(it);
        it->add(projectedEntity);
        projectedEntity->setProjected(it);
        projectedEntity->projectedEntity = entity;
        observer->onAddToProjectionPlane(projectedEntity, name);
        planes.insert(it);
    }
}

void Render::deleteEntity(const PTR<Entity>& entity) {
    for (const auto& it:entity->twoDProjections) {
        observer->onDeleteFromProjectionPlane(it);
        it->projectionPlane->erase(it);
    }
}

Render::Render(PTR<GUIObserver> observer) {
    this->observer = observer;
}

void Render::runAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> algorithm) {
    observer->onAddAlgorithm(algorithm);
}
