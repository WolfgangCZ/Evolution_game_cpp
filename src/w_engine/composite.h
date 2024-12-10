#include "w_object.h"


namespace wEng
{
    class WComposite
    {
        const &std::vector<WObject *> m_objects;
        WComposite(const &std::vector<WObject *> w_objects): m_objects(w_objects)
        {
        }
    };
}
