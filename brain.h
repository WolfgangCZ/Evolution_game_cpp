#ifndef BRAIN_H
#define BRAIN_H

#include <vector>
#include "raylib.h"

//connection
//
class NodeConnection
{
    protected:
        int m_in_layer {0};
        int m_out_layer {0};
        int m_in_node {0};
        int m_out_node {0};
        int m_input {0};
        int m_output {0};
        float m_weight {0.1569};
};

//wiring of all nodes
class NodeWiring : public NodeConnection
{
    protected:
        std::vector<NodeConnection> wiring;
};



class Brain
{

};



#endif //BRAIN_H