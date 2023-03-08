#ifndef BRAIN_H
#define BRAIN_H

#include <vector>
#include "raylib.h"

/*
connection node define one single connection 
single connection is connection between two cells (action, sense or hidden cell)
first two parametrs are layers passed as number 1 - sense, 2 - action, 3,4,5,6... hidden
NOT YET IMPLEMNTED each Synapse generate string as information about connection
*/

class Synapse
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

/*
NOT YET IMPLEMNTED brain wiring store all node connections as array
NOT YET IMPLEMNTED when constructing wiring, all invalid Synapses are discarded without replacement
NOT YET IMPLEMNTED node wiring take all strings (genetic information about each connection) 
NOT YET IMPLEMNTED node wiring also takes all  strings from node connection and create one huge string about all brain connection for further duplicating organisms
*/
class SynapseWiring : public Synapse
{
    protected:
        std::vector<Synapse> wiring;
};

/*
NOT YET IMPLEMNTED brain class takes node wiring and create all nodes in brain which have some value to be calculated
NOT YET IMPLEMNTED this value of each node is gonna be passed through all connections and in the end calculate all action nodes probabilites
NOT YET IMPLEMNTED after that by probabilities 
*/

class Brain
{

};



#endif //BRAIN_H