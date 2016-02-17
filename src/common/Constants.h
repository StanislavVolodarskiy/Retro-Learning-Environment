/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare and 
 *   the Reinforcement Learning and Artificial Intelligence Laboratory
 * Released under the GNU General Public License; see License.txt for details. 
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 *  common_constants.h
 *
 *  Defines a set of constants used by various parts of the player agent code
 *
 **************************************************************************** */

#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include "DebugMacros.h"
#include <cassert>
#include <vector>
#include <valarray>
#include <cstdlib>
// SN:
#include <iostream>
#include "DebugMacros.h"
#include <stdint.h>
#include "../libretro.h"
#include "ale_interface.hpp"


namespace ale{

std::string action_to_string(Action a);

const string ATARI_PATH = "./stella-libretro/stella_libretro.so";
const string SNES_PATH = "./snes9x-next/snes9x_next_libretro.so";

} // namespace ale

#endif // __CONSTANTS_H__

