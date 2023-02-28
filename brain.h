#ifndef BRAIN_H
#define BRAIN_H

#include <vector>
#include "raylib.h"


class NodeConnection
{
    public:
        NodeConnection()
        {}
        ~NodeConnection()
        {}
    protected:
        unsigned short int in_node;
        unsigned short int out_node;
        short int weight_id {static_cast<short int>(GetRandomValue(-32767,32767))};
        float weight_fl {static_cast<float>(weight_id)/32767*4};

};

class NodeWiring : public NodeConnection
{
    public:
        NodeWiring()
        {}
        ~NodeWiring()
        {}
        std::vector<NodeWiring> wiring{};
};

class BrainWiring
{
    public:
    BrainWiring()
    {}
    ~BrainWiring()
    {}
    int action_func_set[20]{};
    int senses_func_set[20]{};
    int hidden_nodes_func[30]{};
};



#endif //BRAIN_H