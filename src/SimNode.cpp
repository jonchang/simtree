//
//  Node.cpp
//  simBAMM
//
//  Created by Dan Rabosky on 12/2/14.
//  Copyright (c) 2014 Dan Rabosky. All rights reserved.
//

#include "SimNode.h"


SimNode::SimNode()
  : _lfDesc{nullptr},
    _rtDesc{nullptr},
    _anc{nullptr},
    _time{0.0},
    _brlen{0.0},
    _tmp{0.0},
    _isExtant{false},
    _isTip{false},
    _nodeEvent{nullptr},
    _name{}
{
}


SimNode::SimNode(SimNode* anc, double time, BranchEvent* be)
  : _lfDesc{nullptr},
    _rtDesc{nullptr},
    _anc{anc},
    _time{time},
    _brlen{0.0},
    _tmp{0.0},
    _isExtant{false},
    _isTip{false},
    _nodeEvent{be},
    _name{}
{
    
}


std::string SimNode::getRandomTipRight(SimNode* x){
    
 
    std::string name;
    if (x->getRtDesc() == NULL && x->getLfDesc() == NULL){
        name = x->getName();
    }else{
        name = getRandomTipRight(x->getRtDesc());
    }
     return name;
}

std::string SimNode::getRandomTipLeft(SimNode* x){
    
     
    std::string name;

    if (x->getRtDesc() == NULL && x->getLfDesc() == NULL){
        name = x->getName();
    }else{
        name = getRandomTipLeft(x->getLfDesc());
    }
    
     return name;
}



