//
//  Node.h
//  simBAMM
//
//  Created by Dan Rabosky on 12/2/14.
//  Copyright (c) 2014 Dan Rabosky. All rights reserved.
//

#ifndef __simBAMM__Node__
#define __simBAMM__Node__

#include <iostream>

class BranchEvent;

class SimNode
{
private:
    SimNode*   _lfDesc;
    SimNode*   _rtDesc;
    SimNode*   _anc;
    double  _time;
    double  _brlen;
    double  _tmp;
    
    bool    _isExtant;
    bool    _isTip;
    
    BranchEvent* _nodeEvent;

    std::string _name;

public:
    SimNode();
    SimNode(const SimNode&) = delete;
    SimNode& operator=(const SimNode&) = delete;
    SimNode(SimNode* anc, double time, BranchEvent* be);
    
    void    setAnc(SimNode * x);
    SimNode*   getAnc();
    
    void    setLfDesc(SimNode* x);
    SimNode*   getLfDesc();

    void    setRtDesc(SimNode* x);
    SimNode*   getRtDesc();

    void    setTime(double x);
    double  getTime();

    void    setBrlen(double x);
    double  getBrlen();

    bool    getIsExtant();
    void    setIsExtant(bool x);

    bool    getIsTip();
    void    setIsTip(bool x);
    
    double  getTmp();
    void    setTmp(double x);

    BranchEvent* getNodeEvent();
    void    setNodeEvent(BranchEvent* x);
    
    void    setName(std::string x);
    std::string getName();
    
    std::string getRandomTipRight(SimNode* x);
    std::string getRandomTipLeft(SimNode* x);


};

inline void SimNode::setTmp(double x)
{
    _tmp = x;
}

inline double SimNode::getTmp()
{
    return _tmp;
}


inline void SimNode::setAnc(SimNode* x)
{
    _anc = x;
}

inline SimNode* SimNode::getAnc()
{
    return _anc;
}

inline void SimNode::setLfDesc(SimNode* x)
{
    _lfDesc = x;
}

inline void SimNode::setRtDesc(SimNode* x)
{
    _rtDesc = x;
}

inline SimNode* SimNode::getLfDesc()
{
    return _lfDesc;
}

inline SimNode* SimNode::getRtDesc()
{
    return _rtDesc;
}

inline double SimNode::getTime()
{
    return _time;
}

inline void SimNode::setTime(double x)
{
    _time = x;
}

inline double SimNode::getBrlen()
{
    return _brlen;
}

inline void SimNode::setBrlen(double x)
{
    _brlen = x;
}

inline bool SimNode::getIsExtant()
{
    return _isExtant;
}

inline void SimNode::setIsExtant(bool x)
{
    _isExtant = x;
}


inline bool SimNode::getIsTip()
{
    return _isTip;
}

inline void SimNode::setIsTip(bool x)
{
    _isTip = x;
}

inline BranchEvent* SimNode::getNodeEvent()
{
    return _nodeEvent;
}

inline void SimNode::setNodeEvent(BranchEvent* x)
{
    _nodeEvent = x;
}

inline void SimNode::setName(std::string x)
{
    _name = x;
}

inline std::string SimNode::getName()
{
    return _name;
}


#endif /* defined(__simBAMM__Node__) */







