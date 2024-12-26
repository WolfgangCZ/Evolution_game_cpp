#include "w_point.h"
#include <vector>


namespace wEng
{
    class WComposite
    {
        private:
            const std::vector<WPoint *> &m_points;
        public:
            WComposite(const std::vector<WPoint *> &w_objects): m_points(w_objects)
            {}
    };

    class CompositFactory
    {
        public:
            static WComposite make_circle(int num_of_points, float radius)
            {
                std::vector<WPoint *> points;
                for (int i = 0; i < num_of_points; i++)
                {
                    WPoint *point = new WPoint({radius * cos(i * 2 * PI / num_of_points), radius * sin(i * 2 * PI / num_of_points)});
                }
                return WComposite(points);
            }
    };
}
