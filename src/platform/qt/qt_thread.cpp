#include <cstdio>
#include <cstdint>
#include "../../plat.h"

#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtCore/QWaitCondition>


class SimpleThread : public QThread
{
public:
    SimpleThread(void (*func)(void *param), void *param)
            : func(func), param(param)
    {
    }

protected:
    void (*func)(void *param);
    void *param;

    void run() override {
        QThread::setTerminationEnabled(true);
        return this->func(this->param);
    }
};


struct SimpleEvent {
    QMutex mutex;
    QWaitCondition cond;
};


thread_t *
thread_create(void (*func)(void *param), void *param)
{
    auto thread = new SimpleThread(func, param);

    thread->start();

    return static_cast<thread_t*>(thread);
}


void
thread_kill(void *arg)
{
    if (arg == nullptr) {
        return;
    }

    auto thread = static_cast<SimpleThread*>(arg);

    thread->terminate();
}


int
thread_wait(thread_t *arg, int timeout)
{
    if (arg == nullptr) {
        return 0;
    }

    auto thread = static_cast<SimpleThread*>(arg);

    auto time = (unsigned long) timeout;

    if (timeout == -1) {
        time = ULONG_MAX;
    }

    if (!thread->wait(time)) {
        return 1;
    }

    return 0;
}


event_t *
thread_create_event(void)
{
    return static_cast<event_t*>(new SimpleEvent);
}


void
thread_set_event(event_t *arg)
{
    if (arg == nullptr) {
        return;
    }

    auto event = static_cast<SimpleEvent*>(arg);

    event->cond.wakeAll();
}


void
thread_reset_event(event_t *arg)
{
}


int
thread_wait_event(event_t *arg, int timeout)
{
    if (arg == nullptr) {
        return 0;
    }

    auto event = static_cast<SimpleEvent*>(arg);

    auto time = (unsigned long) timeout;

    if (timeout == -1) {
        time = ULONG_MAX;
    }

    if (!event->cond.wait(&event->mutex, time)) {
        return 1;
    }

    return 0;
}


void
thread_destroy_event(event_t *arg)
{
    if (arg == nullptr) {
        return;
    }

    auto event = static_cast<SimpleEvent*>(arg);

    delete event;
}


mutex_t *
thread_create_mutex(wchar_t *name)
{
    return static_cast<mutex_t*>(new QMutex);
}


void
thread_close_mutex(mutex_t *arg)
{
    if (arg == nullptr) {
        return;
    }

    auto mutex = static_cast<QMutex*>(arg);

    delete mutex;
}


int
thread_wait_mutex(mutex_t *arg)
{
    if (arg == nullptr) {
        return 0;
    }

    auto mutex = static_cast<QMutex*>(arg);

    mutex->lock();

    return 1;
}


int
thread_release_mutex(mutex_t *arg)
{
    if (arg == nullptr) {
        return 0;
    }

    auto mutex = static_cast<QMutex*>(arg);

    mutex->unlock();

    return 1;
}
