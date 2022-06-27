#include "canvas.h"
#include "iguiobserver.h"
#include "Renderable.h"
#include "hintWindow.h"
//#include "TwoDEntity/TwoDEntity.h"

void GUIAPI::onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}

void GUIAPI::onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}

void GUIAPI::onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object) {
    object->setRenderable(canvas);
    object->render();
}

void GUIAPI::onAddAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> algorithm) {
    HintWindow hint;
    int iterator = 0;
    while (iterator < algorithm.size()) {
        auto step = algorithm[iterator];
        if (step.first == "link") {
            this->canvas->addLinkLine(step.second[0], step.second[1]);
            iterator++;
        } else {
            for (auto & i : step.second) {
                i->setRenderable(canvas);
                i->render();
            }
            if ((algorithm.size() >= iterator + 1) && (algorithm[iterator + 1].first == "link")) {
                printf ("\nmaking connection\n");
                this->canvas->addLinkLine(algorithm[iterator + 1].second[0], algorithm[iterator + 1].second[1]);
                iterator++;
            }
            hint.setText(QString::fromStdString(step.first));
            hint.move(480, 850);
            hint.exec();
            while (hint.movement == 0) {
            }
            iterator += hint.movement;
        }
    }
}
