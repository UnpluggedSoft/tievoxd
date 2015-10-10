/**
 * File:   tievoxd.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#include <boost/program_options.hpp>

#include <iostream>
#include <syslog.h>
#include <wiringPi.h>
#include "Daemon.h"

namespace po = boost::program_options;

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {
    bool foreground = false;
    
    // TODO: Check for foreground flag
    // TODO: Add other flags
    // Check startup flags
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Display this message")
            ("version,v", "Display version information")
            ("foreground,f", "Run in foreground, logging errors to console")
            ;
        
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        // Display help message
        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }
        
        // Display version information
        if (vm.count("version")) {
            printf("[%s] - Version %s\n", argv[0], VERSION);
            return 0;
        }
        
        if (vm.count("fg")) {
            foreground = true;
        }

        
    } catch (exception &e) {
        printf("[%s] Exception caught getting options: %s\n", argv[0], e.what());
        return 1;   
    }

    // Fork to background, if we weren't told not to do it
    if (!foreground) {       
        fork();
    }
    
    // Setup logging
    openlog("tievox", LOG_PERROR | LOG_PID | LOG_CONS, LOG_DAEMON);
    
    // Setup wiringPi, using physical pin numbers.
    wiringPiSetupPhys();
    
    // Run daemon
    Daemon *daemon = new Daemon();
    int result = daemon->Run();
    
    // Cleanup after ourselves
    closelog();
    
    return result;
}

