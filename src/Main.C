/* Copyright 2020 The Loimos Project Developers.
 * See the top-level LICENSE file for details.
 *
 * SPDX-License-Identifier: MIT
 */

#include "loimos.decl.h"
#include "Main.h"
#include "People.h"
#include "Locations.h"

/* readonly */ CProxy_Main mainProxy;
/* readonly */ CProxy_People peopleArray;
/* readonly */ CProxy_Locations locationsArray;
/* readonly */ int numPeople;
/* readonly */ int numLocations;
/* readonly */ int numPeoplePartitions;
/* readonly */ int numLocationPartitions;
/* readonly */ int numDays;

Main::Main(CkArgMsg* msg) {
  // parsing command line arguments
  if(msg->argc < 6){
    CkPrintf("Error, usage %s <people> <locations> <people subsets> <location subsets> <days>\n", msg->argv[0]);
    CkExit();
  }
  numPeople = atoi(msg->argv[1]);
  numLocations = atoi(msg->argv[2]);
  numPeoplePartitions = atoi(msg->argv[3]);
  numLocationPartitions = atoi(msg->argv[4]);
  numDays = atoi(msg->argv[5]);
  delete msg;

  // setup main proxy
  CkPrintf("Running Loimos on %d PEs with %d people, %d locations, %d people subsets, %d location subsets, and %d days\n", CkNumPes(), numPeople, numLocations, numPeoplePartitions, numLocationPartitions, numDays);
  mainProxy = thisProxy;
  accumulated = 0;

  // creating chare arrays
  peopleArray = CProxy_People::ckNew(numPeoplePartitions);
  locationsArray = CProxy_Locations::ckNew(numLocationPartitions);
  mainProxy.run();
}

#include "loimos.def.h"
