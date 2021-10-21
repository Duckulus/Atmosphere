/*
 * Copyright (c) Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stratosphere.hpp>

#define CATCH_CONFIG_NOSTDOUT
#define CATCH_CONFIG_PREFIX_ALL
#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#include "catch.hpp"

namespace ams::test {

    CATCH_TEST_CASE( "svc::SleepThread: Thread sleeps for time specified" ) {
        for (s64 ns = 1; ns < TimeSpan::FromSeconds(1).GetNanoSeconds(); ns *= 2) {
            const auto start = os::GetSystemTickOrdered();
            svc::SleepThread(ns);
            const auto end   = os::GetSystemTickOrdered();

            const s64 taken_ns = (end - start).ToTimeSpan().GetNanoSeconds();
            CATCH_REQUIRE( taken_ns >= ns );
        }
    }

}