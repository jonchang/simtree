//
//  SimTreeEngine.cpp
//  simBAMM
//
//  Created by Dan Rabosky on 12/4/14.
//  Copyright (c) 2014 Dan Rabosky. All rights reserved.
//

#include "SimTreeEngine.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "SimTree.h"
#include "Settings.h"
#include "MbRandom.h"


SimTreeEngine::SimTreeEngine(Settings* settings, MbRandom* random) :
    _settings{settings},
    _random{random},
    _numberOfSims{0},
    _BADMAX{0},
    _mintaxa{0},
    _maxtaxa{0},
    _minNumberOfShifts{0},
    _maxNumberOfShifts{0},
    _minTreeAge{0.0},
    _treefile{},
    _eventfile{},
    _simtrees{}

{
    _numberOfSims = _settings->numberOfSims;
    _treefile = _settings->treefile;
    _eventfile = _settings->eventfile;
    
    _BADMAX = 2000;
    
    _mintaxa = _settings->mintaxa;
    _maxtaxa = _settings->maxtaxa;
    _minNumberOfShifts = _settings->minNumberOfShifts;
    _maxNumberOfShifts = _settings->maxNumberOfShifts;
    _minTreeAge = _settings->minTime;

    
    for (int i = 0; i < _numberOfSims; i++){
        auto tree = getTreeInstance();
        if (tree) {
             _simtrees.push_back(tree);
        } else {
            if (i == 0) {
                // fail fast on the first tree so people don't wait
                // to find out their tree failed
                return;
            }
        }
 
        // _simtrees[i]->recursiveCheckTime();
        // _simtrees[i]->checkBranchLengths();
        
        // std::cout << "tree " << i << " has << ";
        // std::cout << _simtrees[i]->getNumberOfTips() << " >> tips";
        // std::cout << "\tshifts: " << _simtrees[i]->getNumberOfShifts() << std::endl;
        
    }
    
    // Data output
    
    //writeTrees();
    //writeEventData();
}


SimTreeEngine::~SimTreeEngine()
{
    for (int i = 0; i < (int)_simtrees.size(); i++){
        delete _simtrees[i];
    }
}


SimTree* SimTreeEngine::getTreeInstance()
{
    bool isBad = true;
    int badctr = 0;
    while (isBad){
        SimTree* myTree = new SimTree(_random, _settings);
        if (isTreeValid(myTree)){
            return myTree;
        }else{
            badctr++;
        }
        if (badctr > _BADMAX){
            return nullptr;
        }
    }
    std::cout << "Should not get here, terminating" << std::endl;
    exit(1);
}


bool SimTreeEngine::isTreeValid(SimTree* x)
{
    if (x->getIsTreeBad()){
        return false;
    }
    
    int tips = x->getNumberOfTips();
    int shifts = x->getNumberOfShifts();
    double age = x->getTreeAge();
        
    bool isGood = (tips >= _mintaxa && tips <= _maxtaxa
                   && shifts >= _minNumberOfShifts && shifts <= _maxNumberOfShifts
                   && age >= _minTreeAge);
        
    return isGood;
}



void SimTreeEngine::writeTrees()
{
    std::string outname = _treefile;
    std::ofstream outStream;
    outStream.open(outname.c_str());
    outStream.close();
    
    for (int i = 0; i < (int)_simtrees.size(); i++){
        std::ofstream tmpstream;
        tmpstream.open(outname.c_str(), std::ofstream::out | std::ofstream::app);
        
        std::stringstream ss;
        _simtrees[i]->writeTree(_simtrees[i]->getRoot(), ss);
        ss << ";";
        
        tmpstream << ss.str() << std::endl;
        
        tmpstream.close();
    }
    
}

std::vector<std::string> SimTreeEngine::getNewickTrees()
{
    std::vector<std::string> trees;
    for (int i = 0; i < (int)_simtrees.size(); i++) {
        std::stringstream tmpstream;
        _simtrees[i]->writeTree(_simtrees[i]->getRoot(), tmpstream);
        tmpstream << ";";
        trees.push_back(tmpstream.str());
    }
    return trees;
}


void SimTreeEngine::writeEventData()
{
    std::string outname = _eventfile;
    std::ofstream outStream;
    outStream.open(outname.c_str());
    // Write header:
    outStream << "sim,leftchild,rightchild,abstime,lambdainit,lambdashift,muinit\n";
    outStream.close();
    
    for (int i = 0; i < (int)_simtrees.size(); i++){
        std::ofstream tmpstream;
        tmpstream.open(outname.c_str(), std::ofstream::out | std::ofstream::app);
        _simtrees[i]->getEventDataString(i+1, tmpstream);
    
        tmpstream.close();
    }
}

std::string SimTreeEngine::getEventData()
{
    std::ostringstream outStream;
    // Write header:
    outStream << "sim,leftchild,rightchild,abstime,lambdainit,lambdashift,muinit\n";

    for (int i = 0; i < (int)_simtrees.size(); i++){
        _simtrees[i]->getEventDataString(i+1, outStream);
    }
    return outStream.str();
}
















