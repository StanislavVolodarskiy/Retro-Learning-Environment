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
 *  ale_state.hpp
 *
 *  A class that stores a copy of the current ALE state. We use one to keep track
 *   of paddle resistance and in search trees.
 *
 **************************************************************************** */

#ifndef __ALE_STATE_HPP__
#define __ALE_STATE_HPP__

#include "AleSystem.hxx"
#include <string>
#include "../games/RomSettings.hpp"
#include "../common/Log.hpp"

namespace ale {

class ALEState {
  public:
    ALEState();
    // Makes a copy of this state, also storing emulator information provided as a string
    ALEState(const ALEState &rhs, std::string serialized);

    // Restores a serialized ALEState
    ALEState(const std::string &serialized);

    /** Resets the system to its start state. numResetSteps 'RESET' actions are taken after the
      *  start. */
    void reset(int numResetSteps = 1);

    /** Returns true if the two states contain the same saved information */
    bool equals(ALEState &state);

    void incrementFrame(int steps = 1);

    void resetEpisodeFrameNumber();

    //Get the frames executed so far
    const int getFrameNumber() const { return m_frame_number;   }

    //Get the number of frames executed this episode.
    const int getEpisodeFrameNumber() const { return m_episode_frame_number; }

    std::string serialize();


  protected:
    // Let StellaEnvironment access these methods: they are needed for emulation purposes
    friend class RetroEnvironment;

    // The two methods below are meant to be used by StellaEnvironment.
    /** Restores the environment to a previously saved state. If load_system == true, we also
        restore system-specific information (such as the RNG state). */
    void load(
    		AleSystem* alesystem,
    		RomSettings* settings, const ALEState &rhs,
            bool load_system);

    /** Returns a "copy" of the current state, including the information necessary to restore
      *  the emulator. If save_system == true, this includes the RNG state. */
    ALEState save(
    		AleSystem* alesystem,
    		RomSettings* settings, bool save_system);

  private:

    int m_frame_number; // How many frames since the start
    int m_episode_frame_number; // How many frames since the beginning of this episode

    std::string m_serialized_state; // The stored environment state, if this is a saved state

};

} // namespace ale

#endif // __ALE_STATE_HPP__


