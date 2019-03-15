//
//  main.cpp
//  simBAMM
//
//  Created by Dan Rabosky on 12/2/14.
//  Copyright (c) 2014 Dan Rabosky. All rights reserved.
//

#include <chrono>

long int getPrecisionTime()
{
    auto now = std::chrono::high_resolution_clock::now();
    auto dur = now.time_since_epoch();
    
    long int rmd = (long int)dur.count() %  1000000;

    //typedef std::chrono::high_resolution_clock::period period_t;
    //auto dur = now.time_since_epoch();
    //std::cout << "High-res clock reports " << dur.count() << " ticks of 1/" << period_t::den << " seconds \n";
    
    return rmd;
}


