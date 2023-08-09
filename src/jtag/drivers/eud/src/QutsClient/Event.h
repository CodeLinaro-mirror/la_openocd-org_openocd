/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#pragma once
#include <iostream>
#include <stdint.h>
// --------------------------------------------------------------------------
// Event
//
/// System even that allows efficient synchronization between threads
// --------------------------------------------------------------------------
namespace Event
{
    class Event
    {
    public:
        static bool waitForEvent(const Event* pEvent, const uint64_t timeout);

        typedef void* Handle;

        Event(bool bManualReset = false, bool bInitialState = false);
        virtual ~Event();

        void signal();
        void reset();

        Handle getHandle() const;

    private:
        Handle m_hEvent;     ///< Handle to event object
    };

#if defined __linux__ || __APPLE__
    class GlobalEventPool
    {
    public:
        static Event::Handle createEvent(bool bManualReset = false, bool bInitialState = false);
        static Bool closeEvent(Event::Handle hEventHandle);
        static void setEvent(Event::Handle hEventHandle);
        static void resetEvent(Event::Handle hEventHandle);
        static int waitForSingleObject(const Event::Handle hEventHandle, const System::Time::Span& timeout);
    };
#endif

}

