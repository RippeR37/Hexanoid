#ifndef VIEW_GROUP_ITEMGROUP_H_INCLUDED
#define VIEW_GROUP_ITEMGROUP_H_INCLUDED

#include "../View.h"
#include "../ViewItem.h"
#include "../../Models/Groups/ItemGroup.h"
#include "../../Utils/GL+/Program.h"
#include "../../Utils/GL+/VertexArray.h"
#include "../../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewItemGroup : View<Model::ItemGroup> {
        public:
            void init(const Model::ItemGroup& items);
            void render(const Model::ItemGroup& items);

        private:
            ViewItem _viewItem;


    };

}

#endif 