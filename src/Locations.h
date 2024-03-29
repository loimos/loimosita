/* Copyright 2020 The Loimos Project Developers.
 * See the top-level LICENSE file for details.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __LOCATIONS_H__
#define __LOCATIONS_H__

#include <vector>
#include <set>

class Locations : public CBase_Locations {
  private:
    int numLocalLocations;
    std::vector<std::vector<std::pair<int,char> > > visitors;
    std::vector<char> locationState;
    std::default_random_engine generator;
    float MAX_RANDOM_VALUE;
  public:
    Locations();
    void ReceiveVisitMessages(int personIdx, char personState, int locationIdx);
    void ComputeInteractions(); // calls ReceiveInfections
};

#endif // __LOCATIONS_H__
