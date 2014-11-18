#include "ViewBrickGroup.h"

namespace View {

    ViewBrickGroup::ViewBrickGroup() {

    }

    ViewBrickGroup::~ViewBrickGroup() {

    }
            
    void ViewBrickGroup::init(const Model::BrickGroup& bricks) {
        _viewBrick.init(bricks.getBricks().front());
    }

    void ViewBrickGroup::render(const Model::BrickGroup& bricks) {
        for(const Model::Brick& brick : bricks.getBricks()) {
            _viewBrick.render(brick);
        }
    }

}