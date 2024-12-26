#include "w_point.h"
#include <vector>


namespace wEng
{
    class WComposite
    {
        private:
            const std::vector<WPoint *> &m_objects;
        public:
            WComposite(const std::vector<WPoint *> &w_objects): m_objects(w_objects)
            {}

    };
}
