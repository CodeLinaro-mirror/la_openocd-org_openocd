/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "Event.h"
#include <stdexcept>

#if defined WIN32 || WIN64
#include <Windows.h>
#elif defined __linux__ || __APPLE__
#include <sys/time.h>
#include <time.h>
#include <set>
#endif

namespace Event
{
#if defined  __linux__ || __APPLE__
    class LinuxEvent
    {
    public:
        LinuxEvent(bool bManualReset, bool bInitialState)
            : m_pCondition(NULL)
            , m_pMutex(NULL)
            , m_bTriggered(bInitialState)
            , m_bManaulReset(bManualReset)
        {
            m_pMutex = new pthread_mutex_t;
            m_pCondition = new pthread_cond_t;
            pthread_mutex_init(m_pMutex, NULL);
            pthread_cond_init(m_pCondition, NULL);
        }
        ~LinuxEvent()
        {
            pthread_cond_destroy(reinterpret_cast<pthread_cond_t*>(m_pCondition));
            delete m_pCondition;
            m_pCondition = NULL;
            pthread_mutex_destroy(m_pMutex);
            delete m_pMutex;
            m_pMutex = NULL;
        }
        int wait(const System::Time::Span& timeout)
        {
            //Handle manual signal here
            pthread_mutex_lock(m_pMutex);
            if (m_bTriggered)
            {
                if (!m_bManaulReset)
                {
                    m_bTriggered = false;
                }
                pthread_mutex_unlock(m_pMutex);
                return 0;
            }

            Int error = 0;
            //not release mutex; assuming mutex it is to be unlock in pthread_cond_wait.
            //The same thread can alway get the locked mutex, and after the thread is 
            //put to wait queue mutex is to be released inside pthread_cond_wait, this is 
            //to cover the suspicious wakeup when signal comming right here between getState 
            //and pthread_cond_wait
            if (!timeout.isNull())
            {
                struct timeval now;
                ::gettimeofday(&now, NULL);
                struct timespec ts;
                ts.tv_sec = now.tv_sec + timeout.toSeconds();
                ts.tv_nsec = now.tv_usec * 1000 +
                    (timeout.toTicks() % System::Time::Span::TICKS_PER_SECOND) * 100;
                if (System::Time::NANOSECONDS_PER_SECOND <= ts.tv_nsec)
                {
                    ts.tv_sec += 1;
                    ts.tv_nsec -= System::Time::NANOSECONDS_PER_SECOND;
                }
                error = pthread_cond_timedwait(
                    m_pCondition,
                    m_pMutex,
                    &ts
                );
            }
            else
            {
                error = pthread_cond_wait(
                    m_pCondition,
                    m_pMutex
                );
            }
            if (0 == error && !m_bManaulReset)
            {
                //Only reset the event once wait done
                m_bTriggered = false;
            }
            pthread_mutex_unlock(m_pMutex);
            return error;
        }
        void signal()
        {
            pthread_mutex_lock(m_pMutex);
            m_bTriggered = true;
            pthread_cond_broadcast(m_pCondition);
            pthread_mutex_unlock(m_pMutex);
        }
        void reset()
        {
            pthread_mutex_lock(m_pMutex);
            m_bTriggered = false;
            pthread_mutex_unlock(m_pMutex);
        }

    private:
        pthread_cond_t* m_pCondition;
        pthread_mutex_t* m_pMutex;
        volatile Bool m_bTriggered;
        Bool m_bManaulReset;
    };

    typedef LinuxEvent* LinuxEventPtr;
#endif

    Event::Event(bool bManualReset, bool bInitialState) : m_hEvent(nullptr)
    {
#if defined WIN32 || WIN64
        m_hEvent = ::CreateEvent(nullptr, bManualReset, bInitialState, nullptr);
#elif defined __linux__ || __APPLE__
        m_hEvent = GlobalEventPool::createEvent(bManualReset, bInitialState);
#else
#error Unknown operating system
#endif
        if (nullptr == m_hEvent)
        {
            throw std::runtime_error("Failed to create event");
        }
    }

    Event::~Event()
    {
#if defined WIN32 || WIN64
        ::CloseHandle(m_hEvent);
        m_hEvent = nullptr;
#elif defined __linux__ || __APPLE__
        GlobalEventPool::closeEvent(m_hEvent);
        m_hEvent = nullptr;
#else
#error Unknown operating system
#endif
    }

    void Event::signal()
    {
#if defined WIN32
        ::SetEvent(m_hEvent);
#elif  defined __linux__ || __APPLE__
        GlobalEventPool::setEvent(m_hEvent);
#else
#error Unknown operating system
#endif
    }

    void Event::reset()
    {
#if defined WIN32 || WIN64
        ::ResetEvent(m_hEvent);
#elif defined __linux__ || __APPLE__
        GlobalEventPool::resetEvent(m_hEvent);
#else
#error Unknown operating system
#endif
    }

    Event::Handle Event::getHandle() const
    {
        return m_hEvent;
    }

    bool Event::waitForEvent(const Event* pEvent, const uint64_t timeout)
    {
#if defined WIN32 || WIN64
        return (0 == ::WaitForSingleObject(pEvent->getHandle(), timeout));
#elif defined __linux__ || __APPLE__
        return (0 == ::WaitForSingleObject(pEvent->getHandle(), timeout));
#else
#error Unknown operating system
#endif
    }
    

#if defined __linux__ || __APPLE__
    // --------------------------------------------------------------------------
    // createEvent
    //
    /// @returns The handle to the linux event
    // --------------------------------------------------------------------------
    Event::Handle GlobalEventPool::createEvent(Lang::Bool bManualReset, Lang::Bool bInitialState)
    {
        LinuxEventPtr pThisEvent = new LinuxEvent(bManualReset, bInitialState);
        return reinterpret_cast<Event::Handle>(pThisEvent);
    }

    // --------------------------------------------------------------------------
    // closeEvent
    //
    /// @returns true if closed
    // --------------------------------------------------------------------------
    Bool GlobalEventPool::closeEvent(const Event::Handle hEventHandle)
    {
        delete reinterpret_cast<LinuxEventPtr>(hEventHandle);
        return true;
    }

    // --------------------------------------------------------------------------
    // setEvent
    //
    /// signal the event
    // --------------------------------------------------------------------------
    void GlobalEventPool::setEvent(const Event::Handle hEventHandle)
    {
        (reinterpret_cast<LinuxEventPtr>(hEventHandle))->signal();
    }

    // --------------------------------------------------------------------------
    // resetEvent
    //
    /// reset the event signal
    // --------------------------------------------------------------------------
    void GlobalEventPool::resetEvent(const Event::Handle hEventHandle)
    {
        (reinterpret_cast<LinuxEventPtr>(hEventHandle))->reset();
    }

    // --------------------------------------------------------------------------
    // waitForSingleObject
    //
    /// @returns 0 if waited, otherwise error code
    // --------------------------------------------------------------------------
    int GlobalEventPool::waitForSingleObject(
        const Event::Handle hEventHandle,
        const System::Time::Span& timeout)
    {
        return (reinterpret_cast<LinuxEventPtr>(hEventHandle))->wait(timeout);
    }
#endif
}
