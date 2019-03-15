#ifndef SETTINGS_H
#define SETTINGS_H

struct Settings {
    int numberOfSims;
    std::string treefile;
    std::string eventfile;
    int mintaxa;
    int maxtaxa;
    int minNumberOfShifts;
    int maxNumberOfShifts;
    double minTime;
    double epsmin;
    double epsmax;
    double rmin;
    double rmax;
    double lambdaInit0;
    double lambdaShift0;
    double muInit0;
    double lambdaExpMean;
    double muExpMean;
    bool rInitLogscale;
    double maxTime;
    double maxNumberOfNodes;
    double maxTimeForEvent;
    double inc;
    double eventRate;
};

#endif
