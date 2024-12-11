#include "w_object.h"
#include <vector>


namespace wEng
{
    class WComposite
    {
        private:
            const std::vector<WObject *> &m_objects;
        public:
            WComposite(const std::vector<WObject *> &w_objects): m_objects(w_objects)
            {}

    };
}
