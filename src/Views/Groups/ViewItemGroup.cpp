#include "ViewItemGroup.h"

namespace View {

    void ViewItemGroup::init(const Model::ItemGroup& items) {
        Model::Item dummyItem;

        _viewItem.init(dummyItem);
    }

    void ViewItemGroup::render(const Model::ItemGroup& items) {
        for(const Model::Item& item : items.getItems()) {
            _viewItem.render(item);
        }
    }

}